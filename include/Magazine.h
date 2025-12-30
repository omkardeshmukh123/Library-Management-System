#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

/**
 * Magazine class derived from LibraryItem
 * Demonstrates: Inheritance with different item type
 */
class Magazine : public LibraryItem {
private:
    int issueNumber;
    std::string month;
    std::string category;
    
public:
    // Constructor
    Magazine(const std::string& id, const std::string& title, const std::string& publisher,
             int year, int issue, const std::string& mon, const std::string& cat);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getItemType() const override;
    double getLateFeePerDay() const override;
    
    // Magazine-specific getters
    int getIssueNumber() const { return issueNumber; }
    std::string getMonth() const { return month; }
    std::string getCategory() const { return category; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Magazine();
};

#endif // MAGAZINE_H
