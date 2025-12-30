#include "../include/Librarian.h"
#include <iostream>
#include <sstream>

Librarian::Librarian(const std::string& id, const std::string& name, const std::string& email,
                     const std::string& password, int age, const std::string& empId,
                     const std::string& shft)
    : Person(id, name, email, password, age), employeeId(empId), shift(shft) {}

void Librarian::displayInfo() const {
    std::cout << "\n=== Librarian Information ===" << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Employee ID: " << employeeId << std::endl;
    std::cout << "Shift: " << shift << std::endl;
    std::cout << "Role: Administrator" << std::endl;
}

std::string Librarian::getRole() const {
    return "Librarian";
}

int Librarian::getMaxBorrowLimit() const {
    // Librarians can borrow up to 15 items
    return 15;
}

int Librarian::getBorrowDuration() const {
    // Librarians can borrow for 60 days
    return 60;
}

std::string Librarian::serialize() const {
    std::ostringstream oss;
    oss << "LIBRARIAN|" << Person::serialize() << "|" 
        << employeeId << "|" << shift;
    return oss.str();
}

Librarian::~Librarian() {
    // Librarian destructor
}
