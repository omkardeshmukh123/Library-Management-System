#include "../include/Student.h"
#include <iostream>
#include <sstream>

Student::Student(const std::string& id, const std::string& name, const std::string& email,
                 const std::string& password, int age, const std::string& sid,
                 const std::string& maj, int yr)
    : Person(id, name, email, password, age), studentId(sid), major(maj), year(yr) {}

void Student::displayInfo() const {
    std::cout << "\n=== Student Information ===" << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Student ID: " << studentId << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Max Borrow Limit: " << getMaxBorrowLimit() << " items" << std::endl;
    std::cout << "Borrow Duration: " << getBorrowDuration() << " days" << std::endl;
}

std::string Student::getRole() const {
    return "Student";
}

int Student::getMaxBorrowLimit() const {
    // Students can borrow up to 5 items
    return 5;
}

int Student::getBorrowDuration() const {
    // Students can borrow for 14 days
    return 14;
}

std::string Student::serialize() const {
    std::ostringstream oss;
    oss << "STUDENT|" << Person::serialize() << "|" 
        << studentId << "|" << major << "|" << year;
    return oss.str();
}

Student::~Student() {
    // Student destructor
}
