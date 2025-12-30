#include "../include/Journal.h"
#include <iostream>
#include <sstream>

Journal::Journal(const std::string& id, const std::string& title, const std::string& publisher,
                 int year, int volume, const std::string& field, const std::string& ed, bool peer)
    : LibraryItem(id, title, publisher, year), volumeNumber(volume), researchField(field),
      editor(ed), isPeerReviewed(peer) {}

void Journal::displayInfo() const {
    std::cout << "\n=== Journal Information ===" << std::endl;
    std::cout << "Item ID: " << itemId << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Volume Number: " << volumeNumber << std::endl;
    std::cout << "Research Field: " << researchField << std::endl;
    std::cout << "Editor: " << editor << std::endl;
    std::cout << "Peer Reviewed: " << (isPeerReviewed ? "Yes" : "No") << std::endl;
    std::cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << std::endl;
    if (!isAvailable) {
        std::cout << "Current Borrower: " << currentBorrower << std::endl;
    }
    std::cout << "Late Fee: $" << getLateFeePerDay() << " per day" << std::endl;
}

std::string Journal::getItemType() const {
    return "Journal";
}

double Journal::getLateFeePerDay() const {
    // Journals have a late fee of $0.75 per day (higher than books due to academic value)
    return 0.75;
}

std::string Journal::serialize() const {
    std::ostringstream oss;
    oss << "JOURNAL|" << LibraryItem::serialize() << "|"
        << volumeNumber << "|" << researchField << "|" << editor << "|" << isPeerReviewed;
    return oss.str();
}

Journal::~Journal() {
    // Journal destructor
}
