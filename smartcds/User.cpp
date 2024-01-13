#include "User.h"
#include <iostream>

User::User(const std::string& username, const std::string& password,
           const std::string& firstName, const std::string& lastName,
           const std::string& mobileNumber)
    : username(username), password(password), firstName(firstName),
      lastName(lastName), mobileNumber(mobileNumber) {

}
void User::displayProfile() const {
    std::cout << "User Profile: " << firstName << " " << lastName << " (" << username << ")" << std::endl;
}
