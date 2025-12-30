#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <map>
#include <memory>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Librarian.h"
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "Journal.h"
#include "Transaction.h"

/**
 * Library class - Main system management
 * Demonstrates: Singleton Pattern, STL usage, Composition
 */
class Library {
private:
    // Singleton instance
    static Library* instance;
    
    // STL Containers
    std::map<std::string, std::shared_ptr<Person>> users;
    std::map<std::string, std::shared_ptr<LibraryItem>> items;
    std::vector<Transaction> transactions;
    
    // Private constructor for singleton
    Library();
    
    // Helper functions
    int getNextTransactionId() const;
    
public:
    // Singleton instance getter
    static Library* getInstance();
    
    // Delete copy constructor and assignment operator
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    
    // User Management
    void registerStudent(const std::string& id, const std::string& name, 
                        const std::string& email, const std::string& password, int age,
                        const std::string& studentId, const std::string& major, int year);
    
    void registerFaculty(const std::string& id, const std::string& name,
                        const std::string& email, const std::string& password, int age,
                        const std::string& empId, const std::string& dept, 
                        const std::string& designation);
    
    void registerLibrarian(const std::string& id, const std::string& name,
                          const std::string& email, const std::string& password, int age,
                          const std::string& empId, const std::string& shift);
    
    std::shared_ptr<Person> authenticateUser(const std::string& userId, 
                                             const std::string& password);
    
    void displayAllUsers() const;
    std::shared_ptr<Person> getUser(const std::string& userId);
    
    // Item Management
    void addBook(const std::string& id, const std::string& title, 
                 const std::string& publisher, int year, const std::string& isbn,
                 const std::string& author, const std::string& genre, int pages);
    
    void addMagazine(const std::string& id, const std::string& title,
                     const std::string& publisher, int year, int issue,
                     const std::string& month, const std::string& category);
    
    void addJournal(const std::string& id, const std::string& title,
                    const std::string& publisher, int year, int volume,
                    const std::string& field, const std::string& editor, bool peerReviewed);
    
    void displayAllItems() const;
    void displayAvailableItems() const;
    std::shared_ptr<LibraryItem> getItem(const std::string& itemId);
    
    // Search functionality
    std::vector<std::shared_ptr<LibraryItem>> searchByTitle(const std::string& title) const;
    std::vector<std::shared_ptr<LibraryItem>> searchByType(const std::string& type) const;
    
    // Transaction Management
    void borrowItem(const std::string& userId, const std::string& itemId);
    void returnItem(const std::string& userId, const std::string& itemId);
    
    void displayUserTransactions(const std::string& userId) const;
    void displayAllTransactions() const;
    
    // Reports
    void generateOverdueReport() const;
    void generateUserActivityReport(const std::string& userId) const;
    
    // File I/O
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    // Get statistics
    int getTotalUsers() const { return users.size(); }
    int getTotalItems() const { return items.size(); }
    int getAvailableItems() const;
    int getTotalTransactions() const { return transactions.size(); }
    
    // Destructor
    ~Library();
};

#endif // LIBRARY_H
