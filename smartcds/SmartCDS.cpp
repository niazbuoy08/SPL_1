#include "SmartCDS.h"
#include "FileManager.h"
#include "Admin.h"
#include "Salesperson.h"
#include "Customer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <conio.h>


void SmartCDS::run() {
    srand(static_cast<unsigned>(time(0)));

    int option;
    display();
    displayWelcome();

    std::cout << "Please select your option(1-3)" << std::endl;
    std::cin >> option;
    std::cout << std::endl;

    switch (option) {
    case 1:
        system("cls");
        registerUser();
        break;

    case 2:
        system("cls");
        loginUser();
        break;

    case 3:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Invalid option. Please select an option between 1 and 3" << std::endl;
    }
}

void SmartCDS::displayWelcome() const {
    std::cout << "---------------------- Welcome to SMARTCDS ---------------------\n" << std::endl;
    std::cout << "================================================================\n" << std::endl;
    std::cout << "1. REGISTER\n" << std::endl;
    std::cout << "2. LOGIN\n" << std::endl;
    std::cout << "3. EXIT\n" << std::endl;
    std::cout << "***************************************************************\n" << std::endl;
}

void SmartCDS::registerUser() {
    int option;
    display();
    std::cout << "--------------------------- REGISTER --------------------------\n" << std::endl;
    std::cout << "===============================================================\n" << std::endl;
    std::cout << "1. As an ADMIN\n" << std::endl;
    std::cout << "2. As a CUSTOMER\n" << std::endl;
    std::cout << "3. Return to Welcome Page\n" << std::endl;
    std::cout << "4. EXIT\n" << std::endl;
    std::cout << "***************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-4)" << std::endl;

    std::cin >> option;
    std::cout << std::endl;

    switch (option) {
    case 1:
        system("cls");
        registerAsAdmin();
        break;

    case 2:
        system("cls");
        registerAsCustomer();
        break;

    case 3:
        system("cls");
        run();
        break;

    case 4:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Invalid option. Please select an option between 1 and 4" << std::endl;
    }
}

void SmartCDS::loginUser() {
    int option;
    display();
    std::cout << "-------------------------- LOGIN --------------------------\n" << std::endl;
    std::cout << "===========================================================\n" << std::endl;
    std::cout << "1. As an ADMIN\n" << std::endl;
    std::cout << "2. As a CUSTOMER\n" << std::endl;
    std::cout << "3. Return to Welcome Page\n" << std::endl;
    std::cout << "4. EXIT\n" << std::endl;
    std::cout << "***************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-4)" << std::endl;

    std::cin >> option;
    std::cout << std::endl;

    switch (option) {
    case 1:
        system("cls");
        loginAsAdmin();
        break;

    case 2:
        system("cls");
        loginAsCustomer();
        break;

    case 3:
        system("cls");
        run();
        break;

    case 4:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Invalid option. Please select an option between 1 and 4" << std::endl;
    }
}

void SmartCDS::display() const {
    std::cout << "################################################################\n" << std::endl;
    std::cout << "########################## SMARTCDS ############################\n" << std::endl;
    std::cout << "################################################################\n" << std::endl;
    std::cout << "================================================================\n" << std::endl;
}

void SmartCDS::registerAsAdmin() {
    std::string username, password, fname, lname, mobile;

    std::cout << "Enter  username: ";
    std::cin >> username;

    std::cout << "Enter  password: ";
    std::cin >> password;

    std::cout << "Enter  your First Name: ";
    std::cin >> fname;

    std::cout << "Enter  your Last Name: ";
    std::cin >> lname;

    std::cout << "Enter  Mobile Number: ";
    std::cin >> mobile;

    std::string userData = username + " " + password + " " + fname + " " + lname + " " + mobile;
    FileManager::writeToFile("admin_registration.txt", userData);

    std::cout << "Registration successful!" << std::endl;
}

void SmartCDS::loginAsAdmin() {

    Admin admin;
    admin.AdminPage();


    int count = 0;
    std::string userID, password, id, pass;

    std::cout << "\t\t\t Please enter your username and password" << std::endl;

    std::cout << "USERNAME: ";
    std::cin >> userID;

    std::cout << "PASSWORD: ";
    password = getPassword();

    std::string data;
    FileManager::readFromFile("admin_registration.txt", data);
    std::stringstream stream(data);

    while (stream >> id >> pass) {
        std::string restOfLine;
        getline(stream, restOfLine);
        if (id == userID && pass == password) {
            count = 1;
            system("cls");
        }
    }

    if (count == 1) {
        std::cout << userID << " your login is successful\n Thanks for logging in \n";
        Admin admin(userID, password, "", "", "");
        admin.displayProfile();
        AdminPage();
    } else {
        std::cout << "LOGIN ERROR\n Please check username and password \n";
        return;
    }
}
void SmartCDS::registerAsCustomer() {
    std::string username, password, fname, lname, mobile;

    std::cout << "Enter a username: ";
    std::cin >> username;

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::cout << "Enter your First Name: ";
    std::cin >> fname;

    std::cout << "Enter your Last Name: ";
    std::cin >> lname;

    std::cout << "Enter Mobile Number: ";
    std::cin >> mobile;

    std::string userData = username + " " + password + " " + fname + " " + lname + " " + mobile + " " ;
    FileManager::writeToFile("customer_registration.txt", userData);

    std::cout << "Registration successful!" << std::endl;

}

void SmartCDS::loginAsCustomer() {
    int count = 0;
    std::string userID, password, id, pass, customerId;

    std::cout << "\t\t\t Please enter your username and password" << std::endl;

    std::cout << "USERNAME: ";
    std::cin >> userID;

    std::cout << "PASSWORD: ";
    password = getPassword();

    std::string data;
    FileManager::readFromFile("customer_registration.txt", data);
    std::stringstream stream(data);

    while (stream >> id >> pass) {
        std::string restOfLine;
        getline(stream, restOfLine);
        if (id == userID && pass == password) {
            count = 1;
            system("cls");
            customerId = restOfLine; // Assuming the Customer ID is stored in the restOfLine
        }
    }

    if (count == 1) {
        std::cout << userID << " your login is successful\n Thanks for logging in \n";
        Customer customer(userID, password, "", "", "", customerId);
        customer.displayProfile();
        // Call CustomerPage() or any other functionality here
    } else {
        std::cout << "LOGIN ERROR\n Please check username and password \n";
        return;
    }
}



std::string SmartCDS::getPassword() const {
    std::string password = "";
    char ch;
while (true) {
    ch = _getch();
    if (ch == 13)
        break;
    password.push_back(ch);
    std::cout << "*";
    }
    std::cout << std::endl;
    return password;
}
