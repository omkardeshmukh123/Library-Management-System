// ============================================
// Application State Management
// ============================================

const State = {
    // Current user session
    currentUser: null,

    // Current theme
    theme: CONFIG.DEFAULT_THEME,

    // Current route
    currentRoute: 'login',

    // Application data
    users: [],
    items: [],
    transactions: [],

    // UI state
    isLoading: false,
    searchQuery: '',
    filters: {
        itemType: 'all',
        availability: 'all'
    },

    /**
     * Initialize application state
     */
    init() {
        // Load theme from storage
        const savedTheme = Utils.loadFromStorage(CONFIG.STORAGE_KEYS.THEME);
        if (savedTheme) {
            this.theme = savedTheme;
            this.applyTheme();
        }

        // Load user session
        const savedSession = Utils.loadFromStorage(CONFIG.STORAGE_KEYS.USER_SESSION);
        if (savedSession) {
            this.currentUser = savedSession;
        }

        // Initialize mock data
        MockData.init();
        this.users = MockData.users;
        this.items = MockData.items;
        this.transactions = MockData.transactions;
    },

    /**
     * Set current user and save to storage
     * @param {Object} user - User object
     */
    setUser(user) {
        this.currentUser = user;
        Utils.saveToStorage(CONFIG.STORAGE_KEYS.USER_SESSION, user);
        this.notify('userChanged', user);
    },

    /**
     * Clear current user session
     */
    clearUser() {
        this.currentUser = null;
        Utils.removeFromStorage(CONFIG.STORAGE_KEYS.USER_SESSION);
        this.notify('userChanged', null);
    },

    /**
     * Toggle theme between light and dark
     */
    toggleTheme() {
        this.theme = this.theme === 'light' ? 'dark' : 'light';
        Utils.saveToStorage(CONFIG.STORAGE_KEYS.THEME, this.theme);
        this.applyTheme();
        this.notify('themeChanged', this.theme);
    },

    /**
     * Apply current theme to document
     */
    applyTheme() {
        document.documentElement.setAttribute('data-theme', this.theme);
    },

    /**
     * Check if user is authenticated
     * @returns {boolean}
     */
    isAuthenticated() {
        return this.currentUser !== null;
    },

    /**
     * Check if current user has role
     * @param {string} role - Role to check
     * @returns {boolean}
     */
    hasRole(role) {
        return this.currentUser && this.currentUser.role === role;
    },

    /**
     * Check if user is librarian (has admin access)
     * @returns {boolean}
     */
    isLibrarian() {
        return this.hasRole(CONFIG.ROLES.LIBRARIAN);
    },

    /**
     * Get available items
     * @returns {Array}
     */
    getAvailableItems() {
        return this.items.filter(item => item.available);
    },

    /**
     * Get user by ID
     * @param {string} userId
     * @returns {Object|null}
     */
    getUserById(userId) {
        return this.users.find(u => u.id === userId) || null;
    },

    /**
     * Get item by ID
     * @param {string} itemId
     * @returns {Object|null}
     */
    getItemById(itemId) {
        return this.items.find(i => i.id === itemId) || null;
    },

    /**
     * Get user's active transactions
     * @param {string} userId
     * @returns {Array}
     */
    getUserTransactions(userId) {
        return this.transactions.filter(t => t.userId === userId);
    },

    /**
     * Get active transactions
     * @returns {Array}
     */
    getActiveTransactions() {
        return this.transactions.filter(t => t.status === CONFIG.TRANSACTION_STATUS.ACTIVE);
    },

    /**
     * Get overdue transactions
     * @returns {Array}
     */
    getOverdueTransactions() {
        return this.transactions.filter(t => t.status === CONFIG.TRANSACTION_STATUS.OVERDUE);
    },

    /**
     * Add transaction
     * @param {Object} transaction
     */
    addTransaction(transaction) {
        this.transactions.push(transaction);
        MockData.transactions = this.transactions;
        MockData.saveTransactions();
        this.notify('transactionsChanged', this.transactions);
    },

    /**
     * Update transaction
     * @param {string} transactionId
     * @param {Object} updates
     */
    updateTransaction(transactionId, updates) {
        const index = this.transactions.findIndex(t => t.id === transactionId);
        if (index !== -1) {
            this.transactions[index] = { ...this.transactions[index], ...updates };
            MockData.transactions = this.transactions;
            MockData.saveTransactions();
            this.notify('transactionsChanged', this.transactions);
        }
    },

    /**
     * Add library item (librarian only)
     * @param {Object} item
     */
    addItem(item) {
        this.items.push(item);
        MockData.items = this.items;
        this.notify('itemsChanged', this.items);
    },

    /**
     * Update library item availability
     * @param {string} itemId
     * @param {boolean} available
     */
    updateItemAvailability(itemId, available) {
        const item = this.getItemById(itemId);
        if (item) {
            item.available = available;
            this.notify('itemsChanged', this.items);
        }
    },

    /**
     * Search items by query
     * @param {string} query
     * @returns {Array}
     */
    searchItems(query) {
        return Utils.searchFilter(this.items, query, ['title', 'author', 'genre', 'category', 'field']);
    },

    /**
     * Filter items by type
     * @param {string} type
     * @returns {Array}
     */
    filterItemsByType(type) {
        if (type === 'all') return this.items;
        return this.items.filter(item => item.type === type);
    },

    /**
     * Get statistics
     * @returns {Object}
     */
    getStatistics() {
        return {
            totalUsers: this.users.length,
            totalItems: this.items.length,
            availableItems: this.getAvailableItems().length,
            totalTransactions: this.transactions.length,
            activeTransactions: this.getActiveTransactions().length,
            overdueTransactions: this.getOverdueTransactions().length,
            totalBorrowed: this.currentUser ? this.currentUser.borrowedItems : 0
        };
    },

    // Event subscribers
    subscribers: {},

    /**
     * Subscribe to state changes
     * @param {string} event - Event name
     * @param {Function} callback - Callback function
     */
    subscribe(event, callback) {
        if (!this.subscribers[event]) {
            this.subscribers[event] = [];
        }
        this.subscribers[event].push(callback);
    },

    /**
     * Notify subscribers of state change
     * @param {string} event - Event name
     * @param {any} data - Event data
     */
    notify(event, data) {
        if (this.subscribers[event]) {
            this.subscribers[event].forEach(callback => callback(data));
        }
    }
};


