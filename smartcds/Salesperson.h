#ifndef SALESPERSON_H
#define SALESPERSON_H
#include<iostream>
#include<string>
#include "User.h"
#include<ctime>
#include<vector>

class SalesPerson : public User {
public:

    std::string OrderedProduct;
    int OrderedQuantity;
    int OrderedPrice;
    std::string CustomerName;
    std::vector<std::string> registeredCustomers;


    SalesPerson(const std::string& username, const std::string& password, const std::string& firstName,
                const std::string& lastName, const std::string& mobileNumber);

    void displayProfile() const override;
    void SalesPersonPage();
    void PlaceOrder();
    void EditOrder();
    void GenerateInvoice(const std::string& OrderedProduct, int OrderedQuantity, double OrderedPrice);
    void registerAsCustomer();
    void StorePurchaseHistory(const std::string& OrderedProduct, int OrderedQuantity, double OrderedPrice);
    bool IsCustomerRegistered(const std::string& customerName) const;
    void initializeRegisteredCustomers();




    void login();
    void main();
};

#endif
