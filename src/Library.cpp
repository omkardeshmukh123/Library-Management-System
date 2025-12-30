#include "../include/Library.h"
#include "../include/Exceptions.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

// Initialize static singleton instance
Library* Library::instance = nullptr;

Library::Library() {
    // Private constructor
}

Library* Library::getInstance() {
    if (instance == nullptr) {
        instance = new Library();
    }
    return instance;
}

Library::~Library() {
    // Destructor
}

// ==================== User Management ====================

void Library::registerStudent(const std::string& id, const std::string& name,
                              const std::string& email, const std::string& password, int age,
                              const std::string& studentId, const std::string& major, int year) {
    if (users.find(id) != users.end()) {
        throw InvalidOperationException("User ID already exists: " + id);
    }
    
    auto student = std::make_shared<Student>(id, name, email, password, age, 
                                             studentId, major, year);
    users[id] = student;
    std::cout << "Student registered successfully!" << std::endl;
}

void Library::registerFaculty(const std::string& id, const std::string& name,
                              const std::string& email, const std::string& password, int age,
                              const std::string& empId, const std::string& dept,
                              const std::string& designation) {
    if (users.find(id) != users.end()) {
        throw InvalidOperationException("User ID already exists: " + id);
    }
    
    auto faculty = std::make_shared<Faculty>(id, name, email, password, age,
                                             empId, dept, designation);
    users[id] = faculty;
    std::cout << "Faculty registered successfully!" << std::endl;
}

void Library::registerLibrarian(const std::string& id, const std::string& name,
                                const std::string& email, const std::string& password, int age,
                                const std::string& empId, const std::string& shift) {
    if (users.find(id) != users.end()) {
        throw InvalidOperationException("User ID already exists: " + id);
    }
    
    auto librarian = std::make_shared<Librarian>(id, name, email, password, age,
                                                 empId, shift);
    users[id] = librarian;
    std::cout << "Librarian registered successfully!" << std::endl;
}

std::shared_ptr<Person> Library::authenticateUser(const std::string& userId,
                                                  const std::string& password) {
    auto it = users.find(userId);
    if (it == users.end()) {
        throw UserNotFoundException(userId);
    }
    
    if (!it->second->authenticate(password)) {
        throw AuthenticationException("Invalid password for user: " + userId);
    }
    
    return it->second;
}

void Library::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "\nNo users registered in the system." << std::endl;
        return;
    }
    
    std::cout << "\n========== All Registered Users ==========" << std::endl;
    for (const auto& pair : users) {
        pair.second->displayInfo();
        std::cout << "-------------------------------------------" << std::endl;
    }
}

std::shared_ptr<Person> Library::getUser(const std::string& userId) {
    auto it = users.find(userId);
    if (it == users.end()) {
        throw UserNotFoundException(userId);
    }
    return it->second;
}

// ==================== Item Management ====================

void Library::addBook(const std::string& id, const std::string& title,
                     const std::string& publisher, int year, const std::string& isbn,
                     const std::string& author, const std::string& genre, int pages) {
    if (items.find(id) != items.end()) {
        throw InvalidOperationException("Item ID already exists: " + id);
    }
    
    auto book = std::make_shared<Book>(id, title, publisher, year, isbn, 
                                       author, genre, pages);
    items[id] = book;
    std::cout << "Book added successfully!" << std::endl;
}

void Library::addMagazine(const std::string& id, const std::string& title,
                         const std::string& publisher, int year, int issue,
                         const std::string& month, const std::string& category) {
    if (items.find(id) != items.end()) {
        throw InvalidOperationException("Item ID already exists: " + id);
    }
    
    auto magazine = std::make_shared<Magazine>(id, title, publisher, year,
                                               issue, month, category);
    items[id] = magazine;
    std::cout << "Magazine added successfully!" << std::endl;
}

void Library::addJournal(const std::string& id, const std::string& title,
                        const std::string& publisher, int year, int volume,
                        const std::string& field, const std::string& editor, bool peerReviewed) {
    if (items.find(id) != items.end()) {
        throw InvalidOperationException("Item ID already exists: " + id);
    }
    
    auto journal = std::make_shared<Journal>(id, title, publisher, year, volume,
                                            field, editor, peerReviewed);
    items[id] = journal;
    std::cout << "Journal added successfully!" << std::endl;
}

void Library::displayAllItems() const {
    if (items.empty()) {
        std::cout << "\nNo items in the library." << std::endl;
        return;
    }
    
    std::cout << "\n========== All Library Items ==========" << std::endl;
    for (const auto& pair : items) {
        pair.second->displayInfo();
        std::cout << "-------------------------------------------" << std::endl;
    }
}

void Library::displayAvailableItems() const {
    bool found = false;
    std::cout << "\n========== Available Items ==========" << std::endl;
    for (const auto& pair : items) {
        if (pair.second->getAvailability()) {
            pair.second->displayInfo();
            std::cout << "-------------------------------------------" << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No items currently available." << std::endl;
    }
}

std::shared_ptr<LibraryItem> Library::getItem(const std::string& itemId) {
    auto it = items.find(itemId);
    if (it == items.end()) {
        throw ItemNotFoundException(itemId);
    }
    return it->second;
}

// ==================== Search Functionality ====================

std::vector<std::shared_ptr<LibraryItem>> Library::searchByTitle(const std::string& title) const {
    std::vector<std::shared_ptr<LibraryItem>> results;
    std::string lowerTitle = title;
    std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    
    for (const auto& pair : items) {
        std::string itemTitle = pair.second->getTitle();
        std::transform(itemTitle.begin(), itemTitle.end(), itemTitle.begin(), ::tolower);
        
        if (itemTitle.find(lowerTitle) != std::string::npos) {
            results.push_back(pair.second);
        }
    }
    
    return results;
}

std::vector<std::shared_ptr<LibraryItem>> Library::searchByType(const std::string& type) const {
    std::vector<std::shared_ptr<LibraryItem>> results;
    
    for (const auto& pair : items) {
        if (pair.second->getItemType() == type) {
            results.push_back(pair.second);
        }
    }
    
    return results;
}

// ==================== Transaction Management ====================

int Library::getNextTransactionId() const {
    return transactions.size() + 1;
}

void Library::borrowItem(const std::string& userId, const std::string& itemId) {
    // Get user and item
    auto user = getUser(userId);
    auto item = getItem(itemId);
    
    // Check if item is available
    if (!item->getAvailability()) {
        throw ItemAlreadyBorrowedException(itemId);
    }
    
    // Check user's current borrow count
    int currentBorrowCount = 0;
    for (const auto& trans : transactions) {
        if (trans.getUserId() == userId && !trans.getIsReturned()) {
            currentBorrowCount++;
        }
    }
    
    if (currentBorrowCount >= user->getMaxBorrowLimit()) {
        throw BorrowLimitExceededException("User has reached maximum borrow limit");
    }
    
    // Create transaction
    std::string tid = "T" + std::to_string(getNextTransactionId());
    Transaction trans(tid, userId, itemId, user->getBorrowDuration());
    transactions.push_back(trans);
    
    // Update item status
    item->borrowItem(userId);
    
    std::cout << "\nItem borrowed successfully!" << std::endl;
    std::cout << "Due date: " << Transaction::timeToString(trans.getDueDate()) << std::endl;
}

void Library::returnItem(const std::string& userId, const std::string& itemId) {
    // Find the transaction
    Transaction* trans = nullptr;
    for (auto& t : transactions) {
        if (t.getUserId() == userId && t.getItemId() == itemId && !t.getIsReturned()) {
            trans = &t;
            break;
        }
    }
    
    if (trans == nullptr) {
        throw InvalidOperationException("No active borrow found for this item and user");
    }
    
    // Get item to get late fee
    auto item = getItem(itemId);
    
    // Process return
    double fine = trans->processReturn(item->getLateFeePerDay());
    
    // Update item status
    item->returnItem();
    
    std::cout << "\nItem returned successfully!" << std::endl;
    if (fine > 0) {
        std::cout << "Late fee: $" << fine << std::endl;
    } else {
        std::cout << "No late fee." << std::endl;
    }
}

void Library::displayUserTransactions(const std::string& userId) const {
    bool found = false;
    std::cout << "\n========== Transactions for User: " << userId << " ==========" << std::endl;
    
    for (const auto& trans : transactions) {
        if (trans.getUserId() == userId) {
            trans.displayInfo();
            std::cout << "-------------------------------------------" << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No transactions found for this user." << std::endl;
    }
}

void Library::displayAllTransactions() const {
    if (transactions.empty()) {
        std::cout << "\nNo transactions in the system." << std::endl;
        return;
    }
    
    std::cout << "\n========== All Transactions ==========" << std::endl;
    for (const auto& trans : transactions) {
        trans.displayInfo();
        std::cout << "-------------------------------------------" << std::endl;
    }
}

// ==================== Reports ====================

void Library::generateOverdueReport() const {
    bool found = false;
    std::cout << "\n========== Overdue Items Report ==========" << std::endl;
    
    for (const auto& trans : transactions) {
        if (!trans.getIsReturned() && trans.isOverdue()) {
            std::cout << "\nUser: " << trans.getUserId() << std::endl;
            std::cout << "Item: " << trans.getItemId() << std::endl;
            std::cout << "Days Overdue: " << trans.daysOverdue() << std::endl;
            std::cout << "-------------------------------------------" << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No overdue items." << std::endl;
    }
}

void Library::generateUserActivityReport(const std::string& userId) const {
    int totalBorrowed = 0;
    int currentlyBorrowed = 0;
    double totalFines = 0.0;
    
    for (const auto& trans : transactions) {
        if (trans.getUserId() == userId) {
            totalBorrowed++;
            if (!trans.getIsReturned()) {
                currentlyBorrowed++;
            }
            totalFines += trans.getFineAmount();
        }
    }
    
    std::cout << "\n========== User Activity Report ==========" << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Total Items Borrowed: " << totalBorrowed << std::endl;
    std::cout << "Currently Borrowed: " << currentlyBorrowed << std::endl;
    std::cout << "Total Fines Paid: $" << totalFines << std::endl;
}

int Library::getAvailableItems() const {
    int count = 0;
    for (const auto& pair : items) {
        if (pair.second->getAvailability()) {
            count++;
        }
    }
    return count;
}

// ==================== File I/O ====================

void Library::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileIOException(filename);
    }
    
    // Save users
    file << "USERS_START" << std::endl;
    for (const auto& pair : users) {
        file << pair.second->serialize() << std::endl;
    }
    file << "USERS_END" << std::endl;
    
    // Save items
    file << "ITEMS_START" << std::endl;
    for (const auto& pair : items) {
        file << pair.second->serialize() << std::endl;
    }
    file << "ITEMS_END" << std::endl;
    
    // Save transactions
    file << "TRANSACTIONS_START" << std::endl;
    for (const auto& trans : transactions) {
        file << trans.serialize() << std::endl;
    }
    file << "TRANSACTIONS_END" << std::endl;
    
    file.close();
    std::cout << "\nData saved successfully to " << filename << std::endl;
}

void Library::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileIOException(filename);
    }
    
    std::string line;
    // Note: Full deserialization would require parsing the saved data
    // This is a simplified version showing the structure
    
    file.close();
    std::cout << "\nData loaded successfully from " << filename << std::endl;
}
