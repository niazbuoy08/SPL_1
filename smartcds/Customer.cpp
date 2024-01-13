#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& username, const std::string& password, const std::string& firstName,
                   const std::string& lastName, const std::string& mobileNumber, const std::string& customerId)
    : User(username, password, firstName, lastName, mobileNumber), customerId(customerId) {}

void Customer::displayProfile() const {
    std::cout << "Customer Profile: " << firstName << " " << lastName << " (" << username << "), Customer ID: " << customerId << std::endl;
}
