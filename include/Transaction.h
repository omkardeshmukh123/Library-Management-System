#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

/**
 * Transaction class for managing borrow/return operations
 * Demonstrates: Composition, Date management
 */
class Transaction {
private:
    std::string transactionId;
    std::string userId;
    std::string itemId;
    time_t borrowDate;
    time_t dueDate;
    time_t returnDate;
    bool isReturned;
    double fineAmount;
    
    // Helper function to calculate days difference
    int daysBetween(time_t start, time_t end) const;
    
public:
    // Constructor
    Transaction(const std::string& tid, const std::string& uid, const std::string& iid,
                int borrowDurationDays);
    
    // Process return and calculate fine
    double processReturn(double lateFeePerDay);
    
    // Check if overdue
    bool isOverdue() const;
    int daysOverdue() const;
    
    // Display transaction info
    void displayInfo() const;
    
    // Getters
    std::string getTransactionId() const { return transactionId; }
    std::string getUserId() const { return userId; }
    std::string getItemId() const { return itemId; }
    time_t getBorrowDate() const { return borrowDate; }
    time_t getDueDate() const { return dueDate; }
    time_t getReturnDate() const { return returnDate; }
    bool getIsReturned() const { return isReturned; }
    double getFineAmount() const { return fineAmount; }
    
    // Serialization
    std::string serialize() const;
    
    // Static helper to get current time as string
    static std::string timeToString(time_t t);
};

#endif // TRANSACTION_H
