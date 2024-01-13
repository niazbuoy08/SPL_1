#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "User.h"

class SalesPerson : public User {
public:
    SalesPerson(const std::string& username, const std::string& password, const std::string& firstName,
                const std::string& lastName, const std::string& mobileNumber);

    void displayProfile() const override;
    void SalesPersonPage();
    void PlaceOrder();
    void registerAsCustomer();
    void login();
    void main();
};

#endif
