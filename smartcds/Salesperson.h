#ifndef SALESPERSON_H
#define SALESPERSON_H
#include<iostream>
#include<string>
#include "User.h"
#include<ctime>

class SalesPerson : public User {
public:

    std::string OrderedProduct;
    int OrderedQuantity;
    int OrderedPrice;


    SalesPerson(const std::string& username, const std::string& password, const std::string& firstName,
                const std::string& lastName, const std::string& mobileNumber);

    void displayProfile() const override;
    void SalesPersonPage();
    void PlaceOrder();
    void EditOrder();
    void GenerateInvoice(const std::string& OrderedProduct, int OrderedQuantity, double OrderedPrice);
    void registerAsCustomer();

    void login();
    void main();
};

#endif
