#include "../include/LibraryItem.h"
#include "../include/Exceptions.h"
#include <sstream>

LibraryItem::LibraryItem(const std::string& id, const std::string& t, 
                         const std::string& pub, int year)
    : itemId(id), title(t), publisher(pub), publicationYear(year), 
      isAvailable(true), currentBorrower("") {}

LibraryItem::~LibraryItem() {
    // Base class destructor
}

void LibraryItem::borrowItem(const std::string& userId) {
    if (!isAvailable) {
        throw ItemAlreadyBorrowedException(itemId);
    }
    isAvailable = false;
    currentBorrower = userId;
}

void LibraryItem::returnItem() {
    if (isAvailable) {
        throw InvalidOperationException("Item is not currently borrowed: " + itemId);
    }
    isAvailable = true;
    currentBorrower = "";
}

std::string LibraryItem::serialize() const {
    std::ostringstream oss;
    oss << itemId << "|" << title << "|" << publisher << "|" 
        << publicationYear << "|" << isAvailable << "|" << currentBorrower;
    return oss.str();
}
