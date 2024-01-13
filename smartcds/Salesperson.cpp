#include "SalesPerson.h"
#include "SmartCDS.h" // Include the main header file where 'main' and other functions are declared

#include <iostream>

SalesPerson::SalesPerson(const std::string& username, const std::string& password, const std::string& firstName,
                         const std::string& lastName, const std::string& mobileNumber)
    : User(username, password, firstName, lastName, mobileNumber) {}

void SalesPerson::displayProfile() const {
    std::cout << "Salesperson Profile: " << firstName << " " << lastName << " (" << username << ")" << std::endl;
}

void SalesPerson::SalesPersonPage() {
    SmartCDS smartCDS;

    smartCDS.display();
    std::cout << "----------------------------- SalesPerson -----------------------------\n" << std::endl;
    std::cout << "=======================================================================\n" << std::endl;

    int c;

    std::cout << "1. Place Order\n" << std::endl;
    std::cout << "2. Add New Customer\n" << std::endl;
    std::cout << "3. Go to Login Page\n" << std::endl;
    std::cout << "4. Go to Welcome Page\n" << std::endl;
    std::cout << "5. Exit\n" << std::endl;

    std::cout << "**********************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-5)" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    switch (c) {
    case 1:
        system("cls");
        PlaceOrder();
        break;

    case 2:
        system("cls");
        registerAsCustomer();
        break;

    case 3:
        system("cls");
        login();
        break;

    case 4:
        system("cls");
        main();
        break;

    case 5:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Wrong input" << std::endl;
    }
}

void SalesPerson::PlaceOrder() {
    // Implementation of placing an order
}

void SalesPerson::registerAsCustomer() {
    // Implementation of registering as a customer
    // You may reuse the code from the AddSalesperson() function in the Admin class
}

void SalesPerson::login() {

    SmartCDS smartCDS;

    int option;
    smartCDS.display();

    std::cout << "-------------------------- LOGIN --------------------------\n" << std::endl;
    std::cout << "===========================================================\n" << std::endl;
    std::cout << "1. As an ADMIN\n" << std::endl;
    std::cout << "2. As a CUSTOMER\n" << std::endl;
    std::cout << "3. As a SALESPERSON\n" << std::endl;
    std::cout << "4. Return to Welcome Page\n" << std::endl;
    std::cout << "5. EXIT\n" << std::endl;
    std::cout << "***************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-5)" << std::endl;

    std::cin >> option;
    std::cout << std::endl;

    switch (option) {
    case 1:
        system("cls");
        smartCDS.loginAsAdmin();
        break;

    case 2:
        system("cls");
        smartCDS.loginAsCustomer();
        break;

    case 3:
        system("cls");
        smartCDS.loginAsSalesperson();
        break;

    case 4:
        system("cls");
        smartCDS.run();
        break;

    case 5:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Invalid option. Please select an option between 1 and 4" << std::endl;
    }
}

void SalesPerson::main() {

    SmartCDS smartCDS;
    smartCDS.run();

}
