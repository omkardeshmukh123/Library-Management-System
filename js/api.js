// =====================================
// Mock API Layer - Simulates C++ Backend
// ======================================

const API = {
    /**
     * Authenticate user
     * @param {string} userId - User ID
     * @param {string} password - Password
     * @returns {Promise<Object>} User object or error
     */
    async login(userId, password) {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                const user = MockData.users.find(u => u.id === userId && u.password === password);
                if (user) {
                    // Don't send password to client
                    const { password: _, ...userWithoutPassword } = user;
                    resolve({ success: true, user: userWithoutPassword });
                } else {
                    reject({ success: false, message: 'Invalid credentials' });
                }
            }, 500); // Simulate network delay
        });
    },

    /**
     * Get all library items
     * @returns {Promise<Array>}
     */
    async getItems() {
        return new Promise(resolve => {
            setTimeout(() => resolve(MockData.items), 300);
        });
    },

    /**
     * Search items by query
     * @param {string} query
     * @returns {Promise<Array>}
     */
    async searchItems(query) {
        return new Promise(resolve => {
            setTimeout(() => {
                const results = State.searchItems(query);
                resolve(results);
            }, 300);
        });
    },

    /**
     * Borrow an item
     * @param {string} userId
     * @param {string} itemId
     * @returns {Promise<Object>}
     */
    async borrowItem(userId, itemId) {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                const user = State.getUserById(userId);
                const item = State.getItemById(itemId);

                if (!item) {
                    reject({ success: false, message: 'Item not found' });
                    return;
                }

                if (!item.available) {
                    reject({ success: false, message: 'Item not available' });
                    return;
                }

                const maxLimit = CONFIG.MAX_BORROW_LIMIT[user.role];
                if (user.borrowedItems >= maxLimit) {
                    reject({ success: false, message: `You have reached your borrowing limit of ${maxLimit} items` });
                    return;
                }

                // Create transaction
                const borrowDate = new Date();
                const dueDate = Utils.addDays(borrowDate, CONFIG.BORROW_DURATION[user.role]);

                const transaction = {
                    id: 'T' + Date.now(),
                    userId,
                    itemId,
                    itemTitle: item.title,
                    itemType: item.type,
                    borrowDate: borrowDate.toISOString(),
                    dueDate: dueDate.toISOString(),
                    returnDate: null,
                    status: CONFIG.TRANSACTION_STATUS.ACTIVE,
                    fine: 0
                };

                // Update state
                State.addTransaction(transaction);
                State.updateItemAvailability(itemId, false);
                user.borrowedItems++;

                resolve({ success: true, transaction });
            }, 500);
        });
    },

    /**
     * Return an item
     * @param {string} userId
     * @param {string} itemId
     * @returns {Promise<Object>}
     */
    async returnItem(userId, itemId) {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                const transaction = State.transactions.find(
                    t => t.userId === userId && t.itemId === itemId && t.status === CONFIG.TRANSACTION_STATUS.ACTIVE
                );

                if (!transaction) {
                    reject({ success: false, message: 'No active transaction found' });
                    return;
                }

                const returnDate = new Date();
                const dueDate = new Date(transaction.dueDate);
                let fine = 0;

                // Calculate fine if overdue
                if (returnDate > dueDate) {
                    const daysOverdue = Utils.daysBetween(dueDate, returnDate);
                    const fineRate = CONFIG.FINE_RATES[transaction.itemType];
                    fine = daysOverdue * fineRate;
                }

                // Update transaction
                State.updateTransaction(transaction.id, {
                    returnDate: returnDate.toISOString(),
                    status: CONFIG.TRANSACTION_STATUS.RETURNED,
                    fine
                });

                // Update item and user
                State.updateItemAvailability(itemId, true);
                const user = State.getUserById(userId);
                user.borrowedItems--;

                resolve({ success: true, fine, transaction });
            }, 500);
        });
    },

    /**
     * Add new item (librarian only)
     * @param {Object} itemData
     * @returns {Promise<Object>}
     */
    async addItem(itemData) {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                if (!State.isLibrarian()) {
                    reject({ success: false, message: 'Unauthorized: Admin access required' });
                    return;
                }

                const newItem = {
                    id: itemData.type[0] + Date.now(),
                    ...itemData,
                    available: true
                };

                State.addItem(newItem);
                resolve({ success: true, item: newItem });
            }, 500);
        });
    },

    /**
     * Get user transactions
     * @param {string} userId
     * @returns {Promise<Array>}
     */
    async getUserTransactions(userId) {
        return new Promise(resolve => {
            setTimeout(() => {
                const transactions = State.getUserTransactions(userId);
                resolve(transactions);
            }, 300);
        });
    },

    /**
     * Get all users (librarian only)
     * @returns {Promise<Array>}
     */
    async getAllUsers() {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                if (!State.isLibrarian()) {
                    reject({ success: false, message: 'Unauthorized' });
                    return;
                }
                resolve(State.users);
            }, 300);
        });
    },

    /**
     * Get overdue report
     * @returns {Promise<Array>}
     */
    async getOverdueReport() {
        return new Promise(resolve => {
            setTimeout(() => {
                const now = new Date();
                const overdueTransactions = State.transactions
                    .filter(t => t.status === CONFIG.TRANSACTION_STATUS.ACTIVE)
                    .map(t => {
                        const dueDate = new Date(t.dueDate);
                        if (now > dueDate) {
                            const daysOverdue = Utils.daysBetween(dueDate, now);
                            const fineRate = CONFIG.FINE_RATES[t.itemType];
                            const currentFine = daysOverdue * fineRate;

                            return {
                                ...t,
                                daysOverdue,
                                currentFine,
                                status: CONFIG.TRANSACTION_STATUS.OVERDUE
                            };
                        }
                        return null;
                    })
                    .filter(t => t !== null);

                resolve(overdueTransactions);
            }, 300);
        });
    }
};


