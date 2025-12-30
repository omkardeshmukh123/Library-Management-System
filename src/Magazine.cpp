#include "../include/Magazine.h"
#include <iostream>
#include <sstream>

Magazine::Magazine(const std::string& id, const std::string& title, const std::string& publisher,
                   int year, int issue, const std::string& mon, const std::string& cat)
    : LibraryItem(id, title, publisher, year), issueNumber(issue), month(mon), category(cat) {}

void Magazine::displayInfo() const {
    std::cout << "\n=== Magazine Information ===" << std::endl;
    std::cout << "Item ID: " << itemId << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Issue Number: " << issueNumber << std::endl;
    std::cout << "Month: " << month << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << std::endl;
    if (!isAvailable) {
        std::cout << "Current Borrower: " << currentBorrower << std::endl;
    }
    std::cout << "Late Fee: $" << getLateFeePerDay() << " per day" << std::endl;
}

std::string Magazine::getItemType() const {
    return "Magazine";
}

double Magazine::getLateFeePerDay() const {
    // Magazines have a late fee of $0.25 per day (lower than books)
    return 0.25;
}

std::string Magazine::serialize() const {
    std::ostringstream oss;
    oss << "MAGAZINE|" << LibraryItem::serialize() << "|"
        << issueNumber << "|" << month << "|" << category;
    return oss.str();
}

Magazine::~Magazine() {
    // Magazine destructor
}
