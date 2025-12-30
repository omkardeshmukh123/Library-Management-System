#include "../include/Faculty.h"
#include <iostream>
#include <sstream>

Faculty::Faculty(const std::string& id, const std::string& name, const std::string& email,
                 const std::string& password, int age, const std::string& empId,
                 const std::string& dept, const std::string& desig)
    : Person(id, name, email, password, age), employeeId(empId), department(dept), 
      designation(desig) {}

void Faculty::displayInfo() const {
    std::cout << "\n=== Faculty Information ===" << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Employee ID: " << employeeId << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Designation: " << designation << std::endl;
    std::cout << "Max Borrow Limit: " << getMaxBorrowLimit() << " items" << std::endl;
    std::cout << "Borrow Duration: " << getBorrowDuration() << " days" << std::endl;
}

std::string Faculty::getRole() const {
    return "Faculty";
}

int Faculty::getMaxBorrowLimit() const {
    // Faculty can borrow up to 10 items (more than students)
    return 10;
}

int Faculty::getBorrowDuration() const {
    // Faculty can borrow for 30 days (longer than students)
    return 30;
}

std::string Faculty::serialize() const {
    std::ostringstream oss;
    oss << "FACULTY|" << Person::serialize() << "|" 
        << employeeId << "|" << department << "|" << designation;
    return oss.str();
}

Faculty::~Faculty() {
    // Faculty destructor
}
