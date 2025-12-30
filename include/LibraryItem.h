#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

/**
 * Abstract base class for all library items
 * Demonstrates: Abstraction, Encapsulation, Polymorphism
 */
class LibraryItem {
protected:
    std::string itemId;
    std::string title;
    std::string publisher;
    int publicationYear;
    bool isAvailable;
    std::string currentBorrower; // userId of current borrower
    
public:
    // Constructor
    LibraryItem(const std::string& id, const std::string& t, const std::string& pub, int year);
    
    // Virtual destructor
    virtual ~LibraryItem();
    
    // Pure virtual functions
    virtual void displayInfo() const = 0;
    virtual std::string getItemType() const = 0;
    virtual double getLateFeePerDay() const = 0;
    
    // Concrete methods
    void borrowItem(const std::string& userId);
    void returnItem();
    
    // Getters
    std::string getItemId() const { return itemId; }
    std::string getTitle() const { return title; }
    std::string getPublisher() const { return publisher; }
    int getPublicationYear() const { return publicationYear; }
    bool getAvailability() const { return isAvailable; }
    std::string getCurrentBorrower() const { return currentBorrower; }
    
    // Setters
    void setAvailability(bool avail) { isAvailable = avail; }
    
    // Serialization
    virtual std::string serialize() const;
};

#endif // LIBRARYITEM_H
