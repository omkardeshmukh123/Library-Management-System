#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"

/**
 * Librarian class derived from Person
 * Demonstrates: Inheritance with administrative privileges
 */
class Librarian : public Person {
private:
    std::string employeeId;
    std::string shift; // Morning, Evening, Night
    
public:
    // Constructor
    Librarian(const std::string& id, const std::string& name, const std::string& email,
              const std::string& password, int age, const std::string& empId,
              const std::string& shft);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getRole() const override;
    int getMaxBorrowLimit() const override;
    int getBorrowDuration() const override;
    
    // Librarian-specific getters
    std::string getEmployeeId() const { return employeeId; }
    std::string getShift() const { return shift; }
    
    // Administrative privileges
    bool hasAdminAccess() const { return true; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Librarian();
};

#endif // LIBRARIAN_H
