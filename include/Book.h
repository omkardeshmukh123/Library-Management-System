#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

/**
 * Book class derived from LibraryItem
 * Demonstrates: Inheritance, Polymorphism
 */
class Book : public LibraryItem {
private:
    std::string isbn;
    std::string author;
    std::string genre;
    int totalPages;
    
public:
    // Constructor
    Book(const std::string& id, const std::string& title, const std::string& publisher,
         int year, const std::string& isbnNum, const std::string& auth,
         const std::string& gen, int pages);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getItemType() const override;
    double getLateFeePerDay() const override;
    
    // Book-specific getters
    std::string getIsbn() const { return isbn; }
    std::string getAuthor() const { return author; }
    std::string getGenre() const { return genre; }
    int getTotalPages() const { return totalPages; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Book();
};

#endif // BOOK_H
