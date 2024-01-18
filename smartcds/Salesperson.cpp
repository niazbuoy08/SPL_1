#include "SalesPerson.h"
#include "SmartCDS.h"
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include"Admin.h"
#include<vector>
#include <algorithm>


using namespace std;

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
    std::cout << "2. Go to Login Page\n" << std::endl;
    std::cout << "3. Go to Welcome Page\n" << std::endl;
    std::cout << "4. Exit\n" << std::endl;

    std::cout << "**********************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-4)" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    switch (c) {
    case 1:
        system("cls");
        PlaceOrder();
        break;

    case 2:
        system("cls");
        login();
        break;

    case 3:
        system("cls");
        main();
        break;

    case 4:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Wrong input" << std::endl;
    }
}

void SalesPerson::EditOrder() {

    SmartCDS smartCDS;

    smartCDS.display();
    cout << "--------------------------------- EDIT ORDER -----------------------------\n" << endl;
    cout << "============================================================================\n" << endl;


    cout << "Current Ordered Quantity: " << OrderedQuantity << endl;
    cout << "Enter the new Ordered Quantity: ";
    cin >> OrderedQuantity;

    cout << "Order edited successfully!" << endl;



    system("pause");
    system("cls");
    SalesPersonPage();
}

void SalesPerson::PlaceOrder() {
    SmartCDS smartCDS;

    smartCDS.display();
    cout << "--------------------------------- PLACE ORDER -----------------------------\n" << endl;
    cout << "============================================================================\n" << endl;

    initializeRegisteredCustomers();
    cout << "Enter the Customer Name: ";
    cin.ignore();
    getline(cin, CustomerName);

    // Check if the customer is registered
    if (!IsCustomerRegistered(CustomerName)) {
        cout << "Error: Customer not registered. Cannot place an order.\n";
        return;
    }

    cout << "Enter the Product Name: ";
    getline(cin, OrderedProduct);

    cout << "Enter the Ordered Quantity: ";
    cin >> OrderedQuantity;

    cout << "Enter the Price per item: ";
    cin >> OrderedPrice;

    cout << "1. Edit Order\n";
    cout << "2. Confirm Order\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        cout << "Editing order...\n";
        PlaceOrder();
    } else if (choice == 2) {
        system("cls");
        cout << "Confirming order...\n";

        GenerateInvoice(OrderedProduct, OrderedQuantity, OrderedPrice);

        StorePurchaseHistory(OrderedProduct, OrderedQuantity, OrderedPrice);
    } else {
        cout << "Invalid choice.\n";
    }
}
void SalesPerson:: initializeRegisteredCustomers() {
        std::ifstream inputFile("customer_registration.txt");

        if (!inputFile.is_open()) {
            std::cerr << "Error opening customer_registration.txt" << std::endl;
            return;
        }

        std::string line;
        while (getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string name;
            if (iss >> name) {
                registeredCustomers.push_back(name);
            }
        }

        inputFile.close();
    }


bool SalesPerson::IsCustomerRegistered(const std::string& customerName) const {

        if (registeredCustomers.empty()) {
            std::cout << "No customers are registered. Cannot proceed with the purchase." << std::endl;
            return false;
        }

        auto it = std::find(registeredCustomers.begin(), registeredCustomers.end(), customerName);


        if (it != registeredCustomers.end()) {
            std::cout << "Customer is registered. Proceeding with the purchase." << std::endl;
            return true;
        } else {
            std::cout << "Customer is not registered. Cannot proceed with the purchase." << std::endl;
            return false;
        }
}

void SalesPerson::GenerateInvoice(const string& OrderedProduct, int OrderedQuantity, double OrderedPrice){

     time_t now = time(0);
    char* dt = ctime(&now);



    ofstream invoiceFile("invoice.txt");

    if (!invoiceFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string invoice;
    invoice += "\n\n";
    invoice += "=============================================================================\n";
    invoice += "============================== INVOICE =====================================\n";
    invoice += "=============================================================================\n";
    invoice += "\n";
    invoice += "Invoice Date: " + string(dt) + "\n";
    invoice += "Product Name: " + OrderedProduct + "\n";
    invoice += "Quantity: " + to_string(OrderedQuantity) + "\n";
    invoice += "Price per item: " + to_string(OrderedPrice) + "\n";
    invoice += "Total: " + to_string(OrderedPrice * OrderedQuantity) + "\n";
    invoice += "\n";
    invoice += "=============================================================================\n";
    invoice += "Invoice generated successfully!\n";
    invoice += "Product removed from inventory.\n";
    invoice += "=============================================================================\n";
    invoice += "\n\n";

    cout << invoice;
    invoiceFile << invoice;

    Admin adminInstance;

    adminInstance.UpdateInventory(OrderedProduct, OrderedQuantity);

    invoiceFile.close();

    cout << "Invoice generated and saved to invoice.txt successfully!" << endl;

    system("pause");
    system("cls");
    SalesPersonPage();



};


void SalesPerson::StorePurchaseHistory(const string& OrderedProduct, int OrderedQuantity, double OrderedPrice) {
    time_t now = time(0);
    char* dt = ctime(&now);

    ofstream purchaseHistoryFile("purchase_history.txt", ios::app);

    if (!purchaseHistoryFile) {
        cerr << "Error opening purchase history file." << endl;
        return;
    }

    purchaseHistoryFile << "Invoice Date: " << dt;
    purchaseHistoryFile << "Product Name: " << OrderedProduct << "\n";
    purchaseHistoryFile << "Quantity: " << OrderedQuantity << "\n";
    purchaseHistoryFile << "Price per item: " << OrderedPrice << "\n";
    purchaseHistoryFile << "Total: " << (OrderedPrice * OrderedQuantity) << "\n";
    purchaseHistoryFile << "---------------------------------------------------------------\n\n";

    purchaseHistoryFile.close();
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
