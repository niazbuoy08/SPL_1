#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
private:
    std::string customerId;

public:
    Customer(const std::string& username, const std::string& password, const std::string& firstName,
             const std::string& lastName, const std::string& mobileNumber, const std::string& customerId);

    void displayProfile() const override;
    void generateCustomerID(std::string& customerId);

    void display();
    void CustomerPage();
    void UpdateProfile();
    void UpdateName();
    void UpdateMobileNumber();
    void ChangePassword();
    void login();
    void main();
};

#endif
