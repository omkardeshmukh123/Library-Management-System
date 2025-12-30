#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

/**
 * Abstract base class for all persons in the library system
 * Demonstrates: Abstraction, Encapsulation, Polymorphism
 */
class Person {
protected:
    std::string userId;
    std::string name;
    std::string email;
    std::string password;
    int age;

public:
    // Constructor
    Person(const std::string& id, const std::string& n, const std::string& e, 
           const std::string& pwd, int a);
    
    // Virtual destructor (important for polymorphism)
    virtual ~Person();
    
    // Pure virtual functions (Abstract methods)
    virtual void displayInfo() const = 0;
    virtual std::string getRole() const = 0;
    virtual int getMaxBorrowLimit() const = 0;
    virtual int getBorrowDuration() const = 0;
    
    // Concrete methods
    bool authenticate(const std::string& pwd) const;
    
    // Getters (Encapsulation)
    std::string getUserId() const { return userId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    int getAge() const { return age; }
    
    // Setters
    void setEmail(const std::string& e) { email = e; }
    void setPassword(const std::string& pwd) { password = pwd; }
    
    // Serialization for file I/O
    virtual std::string serialize() const;
};

#endif // PERSON_H
