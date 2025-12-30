#include "../include/Transaction.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Transaction::Transaction(const std::string& tid, const std::string& uid, 
                         const std::string& iid, int borrowDurationDays)
    : transactionId(tid), userId(uid), itemId(iid), isReturned(false), 
      fineAmount(0.0), returnDate(0) {
    borrowDate = time(nullptr);
    dueDate = borrowDate + (borrowDurationDays * 24 * 60 * 60); // Convert days to seconds
}

int Transaction::daysBetween(time_t start, time_t end) const {
    double seconds = difftime(end, start);
    return static_cast<int>(seconds / (24 * 60 * 60));
}

double Transaction::processReturn(double lateFeePerDay) {
    if (isReturned) {
        return fineAmount;
    }
    
    returnDate = time(nullptr);
    isReturned = true;
    
    if (returnDate > dueDate) {
        int overdueDays = daysBetween(dueDate, returnDate);
        fineAmount = overdueDays * lateFeePerDay;
    }
    
    return fineAmount;
}

bool Transaction::isOverdue() const {
    if (isReturned) {
        return returnDate > dueDate;
    }
    time_t now = time(nullptr);
    return now > dueDate;
}

int Transaction::daysOverdue() const {
    if (!isOverdue()) {
        return 0;
    }
    
    if (isReturned) {
        return daysBetween(dueDate, returnDate);
    } else {
        time_t now = time(nullptr);
        return daysBetween(dueDate, now);
    }
}

void Transaction::displayInfo() const {
    std::cout << "\n=== Transaction Information ===" << std::endl;
    std::cout << "Transaction ID: " << transactionId << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Item ID: " << itemId << std::endl;
    std::cout << "Borrow Date: " << timeToString(borrowDate) << std::endl;
    std::cout << "Due Date: " << timeToString(dueDate) << std::endl;
    
    if (isReturned) {
        std::cout << "Return Date: " << timeToString(returnDate) << std::endl;
        std::cout << "Fine Amount: $" << std::fixed << std::setprecision(2) << fineAmount << std::endl;
    } else {
        std::cout << "Status: Not yet returned" << std::endl;
        if (isOverdue()) {
            std::cout << "Days Overdue: " << daysOverdue() << std::endl;
        }
    }
}

std::string Transaction::serialize() const {
    std::ostringstream oss;
    oss << transactionId << "|" << userId << "|" << itemId << "|"
        << borrowDate << "|" << dueDate << "|" << returnDate << "|"
        << isReturned << "|" << fineAmount;
    return oss.str();
}

std::string Transaction::timeToString(time_t t) {
    if (t == 0) return "N/A";
    
    char buffer[80];
    struct tm* timeinfo = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}
