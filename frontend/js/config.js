// ============================================
// Application Configuration
// ============================================

const CONFIG = {
    // Application Info
    APP_NAME: 'LibraryHub',
    APP_VERSION: '1.0.0',
    APP_DESCRIPTION: 'Modern Library Management System',

    // User Roles
    ROLES: {
        STUDENT: 'Student',
        FACULTY: 'Faculty',
        LIBRARIAN: 'Librarian'
    },

    // Item Types
    ITEM_TYPES: {
        BOOK: 'Book',
        MAGAZINE: 'Magazine',
        JOURNAL: 'Journal'
    },

    // Borrowing Limits (days)
    BORROW_DURATION: {
        Student: 14,
        Faculty: 30,
        Librarian: 60
    },

    // Maximum items that can be borrowed
    MAX_BORROW_LIMIT: {
        Student: 5,
        Faculty: 10,
        Librarian: 15
    },

    // Fine rates (per day in $)
    FINE_RATES: {
        Book: 0.50,
        Magazine: 0.25,
        Journal: 0.75
    },

    // Transaction Status
    TRANSACTION_STATUS: {
        ACTIVE: 'Active',
        RETURNED: 'Returned',
        OVERDUE: 'Overdue'
    },

    // Local Storage Keys
    STORAGE_KEYS: {
        USER_SESSION: 'library_user_session',
        THEME: 'library_theme',
        TRANSACTIONS: 'library_transactions',
        ITEMS: 'library_items'
    },

    // Default Theme
    DEFAULT_THEME: 'light',

    // Date Format
    DATE_FORMAT: 'YYYY-MM-DD',

    // Sample Credentials
    SAMPLE_USERS: [
        { id: 'S001', password: 'pass123', role: 'Student' },
        { id: 'F001', password: 'pass456', role: 'Faculty' },
        { id: 'L001', password: 'pass789', role: 'Librarian' }
    ]
};


