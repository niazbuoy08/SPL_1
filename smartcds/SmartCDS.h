#ifndef SMART_CDS_H
#define SMART_CDS_H

#include <string>
#include <iostream>
#include <sstream>


class SmartCDS {
public:

    std::string getPassword() const;
    void display() const;
    void registerAsAdmin();
    void registerAsCustomer();
    void loginAsAdmin();
    void loginAsCustomer();
    void AdminPage();
    void run();
    void displayWelcome() const;
    void registerUser();
    void loginUser();
    void AddSalesperson();
    void loginAsSalesperson();

private:

};

#endif
