#include "../include/Book.h"
#include <iostream>
#include <sstream>

Book::Book(const std::string& id, const std::string& title, const std::string& publisher,
           int year, const std::string& isbnNum, const std::string& auth,
           const std::string& gen, int pages)
    : LibraryItem(id, title, publisher, year), isbn(isbnNum), author(auth),
      genre(gen), totalPages(pages) {}

void Book::displayInfo() const {
    std::cout << "\n=== Book Information ===" << std::endl;
    std::cout << "Item ID: " << itemId << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Total Pages: " << totalPages << std::endl;
    std::cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << std::endl;
    if (!isAvailable) {
        std::cout << "Current Borrower: " << currentBorrower << std::endl;
    }
    std::cout << "Late Fee: $" << getLateFeePerDay() << " per day" << std::endl;
}

std::string Book::getItemType() const {
    return "Book";
}

double Book::getLateFeePerDay() const {
    // Books have a late fee of $0.50 per day
    return 0.50;
}

std::string Book::serialize() const {
    std::ostringstream oss;
    oss << "BOOK|" << LibraryItem::serialize() << "|"
        << isbn << "|" << author << "|" << genre << "|" << totalPages;
    return oss.str();
}

Book::~Book() {
    // Book destructor
}
