#include "../include/Person.h"
#include <sstream>

Person::Person(const std::string& id, const std::string& n, const std::string& e, 
               const std::string& pwd, int a)
    : userId(id), name(n), email(e), password(pwd), age(a) {}

Person::~Person() {
    // Base class destructor
}

bool Person::authenticate(const std::string& pwd) const {
    return password == pwd;
}

std::string Person::serialize() const {
    std::ostringstream oss;
    oss << userId << "|" << name << "|" << email << "|" << password << "|" << age;
    return oss.str();
}
