#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

/**
 * Student class derived from Person
 * Demonstrates: Inheritance, Method Overriding
 */
class Student : public Person {
private:
    std::string studentId;
    std::string major;
    int year; // Academic year (1-4)
    
public:
    // Constructor
    Student(const std::string& id, const std::string& name, const std::string& email,
            const std::string& password, int age, const std::string& sid,
            const std::string& maj, int yr);
    
    // Override virtual functions
    void displayInfo() const override;
    std::string getRole() const override;
    int getMaxBorrowLimit() const override;
    int getBorrowDuration() const override;
    
    // Student-specific getters
    std::string getStudentId() const { return studentId; }
    std::string getMajor() const { return major; }
    int getYear() const { return year; }
    
    // Serialization
    std::string serialize() const override;
    
    // Destructor
    ~Student();
};

#endif // STUDENT_H
