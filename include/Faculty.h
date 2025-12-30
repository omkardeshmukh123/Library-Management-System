#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

/**
 * Faculty class derived from Person
 * Demonstrates: Inheritance with different privileges
 */
class Faculty : public Person {
private:
    std::string employeeId;
    std::string department;
    std::string designation; // Professor, Associate Professor, etc.
    
public:
    // Constructor
    Faculty(const std::string& id, const std::string& name, const std::string& email,
            const std::string& password, int age, const std::string& empId,
            const std::string& dept, const std::string& desig);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getRole() const override;
    int getMaxBorrowLimit() const override;
    int getBorrowDuration() const override;
    
    // Faculty-specific getters
    std::string getEmployeeId() const { return employeeId; }
    std::string getDepartment() const { return department; }
    std::string getDesignation() const { return designation; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Faculty();
};

#endif // FACULTY_H
