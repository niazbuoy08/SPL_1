#include "Salesperson.h"
#include <iostream>

Salesperson::Salesperson(const std::string& username, const std::string& password, const std::string& firstName,
                         const std::string& lastName, const std::string& mobileNumber)
    : User(username, password, firstName, lastName, mobileNumber) {}

void Salesperson::displayProfile() const {
    std::cout << "Salesperson Profile: " << firstName << " " << lastName << " (" << username << ")" << std::endl;
}
