#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string mobileNumber;

public:
    User(const std::string& username = "", const std::string& password = "",
         const std::string& firstName = "", const std::string& lastName = "",
         const std::string& mobileNumber = "");


    virtual void displayProfile() const = 0;
};

#endif
