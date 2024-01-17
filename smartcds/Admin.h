#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream>
#include <fstream>
#include "FileManager.h"
#include "SmartCDS.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, const std::string& firstName,
          const std::string& lastName, const std::string& mobileNumber);

    Admin();

    void displayProfile() const override;
    void run();
    void display();
    void AdminPage();
    void AddNewFood();
    void EditFood();
    void DeleteFood();
    void Inventory();
    void AddSalesperson();
    void login();
    void main();
    void loginAsAdmin();
    void loginAsCustomer();
    void loginAsSalesperson();
    void YesOrNoCheck();
    void UpdateInventory(const std::string& productName, int quantity);


private:
    std::string username;
    std::string password;
    std::string firstName;
    std::string lastName;
    std::string mobile;
};

#endif
