// ============================================
// Mock Data - Simulating C++ Backend
// ============================================

const MockData = {
    // Users Data
    users: [
        // Students
        {
            id: 'S001',
            name: 'Alice Johnson',
            email: 'alice.johnson@university.edu',
            password: 'pass123',
            role: 'Student',
            age: 20,
            studentId: 'STU2024001',
            major: 'Computer Science',
            year: 2,
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2024-01-15'
        },
        {
            id: 'S002',
            name: 'Bob Smith',
            email: 'bob.smith@university.edu',
            password: 'pass123',
            role: 'Student',
            age: 21,
            studentId: 'STU2024002',
            major: 'Mathematics',
            year: 3,
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2024-01-20'
        },
        {
            id: 'S003',
            name: 'Carol Davis',
            email: 'carol.davis@university.edu',
            password: 'pass123',
            role: 'Student',
            age: 19,
            studentId: 'STU2024003',
            major: 'Physics',
            year: 1,
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2024-02-01'
        },

        // Faculty
        {
            id: 'F001',
            name: 'Dr. David Wilson',
            email: 'david.wilson@university.edu',
            password: 'pass456',
            role: 'Faculty',
            age: 45,
            employeeId: 'FAC2020001',
            department: 'Computer Science',
            designation: 'Professor',
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2020-03-10'
        },
        {
            id: 'F002',
            name: 'Dr. Emma Brown',
            email: 'emma.brown@university.edu',
            password: 'pass456',
            role: 'Faculty',
            age: 38,
            employeeId: 'FAC2019002',
            department: 'Mathematics',
            designation: 'Associate Professor',
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2019-08-15'
        },

        // Librarians
        {
            id: 'L001',
            name: 'Frank Taylor',
            email: 'frank.taylor@university.edu',
            password: 'pass789',
            role: 'Librarian',
            age: 35,
            employeeId: 'LIB2021001',
            shift: 'Morning',
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2021-06-01'
        },
        {
            id: 'L002',
            name: 'Grace Lee',
            email: 'grace.lee@university.edu',
            password: 'pass789',
            role: 'Librarian',
            age: 28,
            employeeId: 'LIB2022002',
            shift: 'Evening',
            borrowedItems: 0,
            activeTransactions: [],
            joinDate: '2022-01-10'
        }
    ],

    // Library Items
    items: [
        // Books
        {
            id: 'B001',
            type: 'Book',
            title: 'Introduction to Algorithms',
            publisher: 'MIT Press',
            year: 2022,
            isbn: '978-0262046305',
            author: 'Thomas H. Cormen',
            genre: 'Computer Science',
            pages: 1312,
            available: true,
            coverImage: '📚'
        },
        {
            id: 'B002',
            type: 'Book',
            title: 'Clean Code',
            publisher: 'Prentice Hall',
            year: 2008,
            isbn: '978-0132350884',
            author: 'Robert C. Martin',
            genre: 'Software Engineering',
            pages: 464,
            available: true,
            coverImage: '📖'
        },
        {
            id: 'B003',
            type: 'Book',
            title: 'The Pragmatic Programmer',
            publisher: 'Addison-Wesley',
            year: 2019,
            isbn: '978-0135957059',
            author: 'David Thomas',
            genre: 'Software Development',
            pages: 352,
            available: true,
            coverImage: '📕'
        },
        {
            id: 'B004',
            type: 'Book',
            title: 'Design Patterns',
            publisher: 'Addison-Wesley',
            year: 1994,
            isbn: '978-0201633610',
            author: 'Gang of Four',
            genre: 'Software Architecture',
            pages: 395,
            available: true,
            coverImage: '📗'
        },
        {
            id: 'B005',
            type: 'Book',
            title: 'Structure and Interpretation of Computer Programs',
            publisher: 'MIT Press',
            year: 1996,
            isbn: '978-0262510871',
            author: 'Harold Abelson',
            genre: 'Computer Science',
            pages: 657,
            available: true,
            coverImage: '📘'
        },
        {
            id: 'B006',
            type: 'Book',
            title: 'Artificial Intelligence: A Modern Approach',
            publisher: 'Pearson',
            year: 2020,
            isbn: '978-0134610993',
            author: 'Stuart Russell',
            genre: 'Artificial Intelligence',
            pages: 1136,
            available: true,
            coverImage: '🤖'
        },

        // Magazines
        {
            id: 'M001',
            type: 'Magazine',
            title: 'National Geographic',
            publisher: 'National Geographic Society',
            year: 2024,
            issue: 1,
            month: 'January',
            category: 'Science & Nature',
            available: true,
            coverImage: '📰'
        },
        {
            id: 'M002',
            type: 'Magazine',
            title: 'Scientific American',
            publisher: 'Springer Nature',
            year: 2024,
            issue: 2,
            month: 'February',
            category: 'Science',
            available: true,
            coverImage: '🔬'
        },
        {
            id: 'M003',
            type: 'Magazine',
            title: 'Wired',
            publisher: 'Condé Nast',
            year: 2024,
            issue: 3,
            month: 'March',
            category: 'Technology',
            available: true,
            coverImage: '💻'
        },
        {
            id: 'M004',
            type: 'Magazine',
            title: 'Nature',
            publisher: 'Nature Publishing Group',
            year: 2024,
            issue: 4,
            month: 'April',
            category: 'Scientific Research',
            available: true,
            coverImage: '🌿'
        },

        // Journals
        {
            id: 'J001',
            type: 'Journal',
            title: 'Journal of Computer Science',
            publisher: 'ACM',
            year: 2024,
            volume: 45,
            field: 'Computer Science',
            editor: 'Dr. Sarah Mitchell',
            peerReviewed: true,
            available: true,
            coverImage: '📄'
        },
        {
            id: 'J002',
            type: 'Journal',
            title: 'Mathematical Reviews',
            publisher: 'AMS',
            year: 2024,
            volume: 120,
            field: 'Mathematics',
            editor: 'Dr. John Anderson',
            peerReviewed: true,
            available: true,
            coverImage: '📊'
        },
        {
            id: 'J003',
            type: 'Journal',
            title: 'Physical Review Letters',
            publisher: 'American Physical Society',
            year: 2024,
            volume: 132,
            field: 'Physics',
            editor: 'Dr. Maria Garcia',
            peerReviewed: true,
            available: true,
            coverImage: '⚛️'
        },
        {
            id: 'J004',
            type: 'Journal',
            title: 'IEEE Transactions on Pattern Analysis',
            publisher: 'IEEE',
            year: 2024,
            volume: 46,
            field: 'Machine Learning',
            editor: 'Dr. Li Wang',
            peerReviewed: true,
            available: true,
            coverImage: '🧠'
        }
    ],

    // Transactions (will be dynamically created)
    transactions: [],

    // Statistics
    statistics: {
        totalUsers: 7,
        totalItems: 18,
        totalTransactions: 0,
        activeTransactions: 0,
        overdueItems: 0,
        totalFinesCollected: 0
    },

    /**
     * Initialize mock data
     */
    init() {
        // Load from localStorage if available
        const savedTransactions = Utils.loadFromStorage(CONFIG.STORAGE_KEYS.TRANSACTIONS);
        if (savedTransactions) {
            this.transactions = savedTransactions;
        }
        // Update statistics
        this.updateStatistics();
    },

    /**
     * Update statistics
     */
    updateStatistics() {
        this.statistics.totalUsers = this.users.length;
        this.statistics.totalItems = this.items.length;
        this.statistics.totalTransactions = this.transactions.length;
        this.statistics.activeTransactions = this.transactions.filter(t => t.status === 'Active').length;
        this.statistics.overdueItems = this.transactions.filter(t => t.status === 'Overdue').length;
    },

    /**
     * Save transactions to storage
     */
    saveTransactions() {
        Utils.saveToStorage(CONFIG.STORAGE_KEYS.TRANSACTIONS, this.transactions);
        this.updateStatistics();
    }
};
