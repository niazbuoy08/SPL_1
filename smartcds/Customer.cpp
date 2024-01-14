#include "Customer.h"
#include "SmartCDS.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>


using namespace std;

Customer::Customer(const std::string& username, const std::string& password, const std::string& firstName,
                   const std::string& lastName, const std::string& mobileNumber, const std::string& customerId)
    : User(username, password, firstName, lastName, mobileNumber), customerId(customerId) {}

void Customer::displayProfile() const {
    std::cout << "Customer Profile: " << firstName << " " << lastName << " (" << username << "), Customer ID: " << customerId << std::endl;
}

void Customer::CustomerPage() {

    SmartCDS smartCDS;

    smartCDS.display();
    std::cout << "----------------------------- CUSTOMER -----------------------------\n" << std::endl;
    std::cout << "====================================================================\n" << std::endl;

    int c;

    std::cout << "1. Purchase History(Last 7 days)\n" << std::endl;
    std::cout << "2. Update Profile\n" << std::endl;
    std::cout << "3. Change Password\n" << std::endl;
    std::cout << "4. Go to Login Page\n" << std::endl;
    std::cout << "5. Go to Welcome Page\n" << std::endl;
    std::cout << "6. Exit\n" << std::endl;

    std::cout << "*******************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-6)" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    switch (c) {
    case 1:
        system("cls");
        // Implement Purchase History
        break;

    case 2:
        system("cls");
        UpdateProfile();
        break;

    case 3:
        system("cls");
        ChangePassword();
        break;

    case 4:
        system("cls");
        login();
        break;

    case 5:
        system("cls");
        main();
        break;

    case 6:
        system("cls");
        std::cout << "Exiting the program\n" << std::endl;
        break;

    default:
        system("cls");
        std::cout << "Wrong input" << std::endl;
    }
}

void Customer::UpdateProfile() {
    SmartCDS smartCDS;

    smartCDS.display();

    std::cout << "----------------------------- CUSTOMER -----------------------------\n" << std::endl;
    std::cout << "====================================================================\n" << std::endl;

    int c;

    std::cout << "1. Update Name\n" << std::endl;
    std::cout << "2. Update Mobile Number\n" << std::endl;
    std::cout << "3. Go to Login Page\n" << std::endl;
    std::cout << "4. Go to Welcome Page\n" << std::endl;

    std::cout << "*******************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-4)" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    switch (c) {
    case 1:
        system("cls");
        UpdateName();
        break;

    case 2:
        system("cls");
        UpdateMobileNumber();
        break;

    case 3:
        system("cls");
        login();
        break;

    case 4:
        system("cls");
        main();
        break;

    default:
        system("cls");
        std::cout << "Wrong input" << std::endl;
    }
}

void Customer::UpdateName() {

    SmartCDS smartCDS;

    smartCDS.display();
    cout << "----------------------------- CUSTOMER ------------------------------\n" << endl;
    cout << "=====================================================================\n" << endl;

    string id;
    cout << "Enter your ID: ";
    cin >> id;

    string updatedName;
    cout << "Enter New Username: ";
    cin.ignore();
    getline(cin, updatedName);

    ifstream inputFile("customer_registration.txt");
    ofstream tempFile("temp_customer_registration.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;

    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string cusername, cpassword, cfname, clname, cmobile, customerId;

        ss >> cusername >> cpassword >> cfname >> clname >> cmobile >>customerId;

        if (customerId!=id) {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile<<"  "<<customerId
                     << endl;

        } else {
            tempFile << setw(20) << left << updatedName << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname
                     << "  " << left << cmobile << "  "<<customerId<<endl;
            found = true;
        }

    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cerr << "Customer ID not found." << endl;
        remove("temp_customer_registration.txt");
        return;
    }

    if (remove("customer_registration.txt") != 0) {
        cerr << "Error deleting the original file." << endl;
        return;
    }

    if (rename("temp_customer_registration.txt", "customer_registration.txt") != 0) {
        cerr << "Error renaming the temporary file." << endl;
        return;
    }

    cout << "The name has been successfully updated." << endl;
}

void Customer::UpdateMobileNumber() {

     SmartCDS smartCDS;

    smartCDS.display();
    cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
    cout << "====================================================================\n" << endl;

    string id;
    cout << "Enter your ID: ";
    cin >> id;

    string updatedNumber;
    cout << "Enter Updated Mobile Number: ";
    cin.ignore();
    getline(cin, updatedNumber);

    ifstream inputFile("customer_registration.txt");
    ofstream tempFile("temp_customer_registration.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;

    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string cusername, cpassword, cfname, clname, cmobile,customerId;

        ss >> cusername >> cpassword >> cfname >> clname >> cmobile>>customerId;

        if (customerId!=id) {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile<<"  "<<customerId
                     << endl;

        } else {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname
                     << "  " << left << updatedNumber <<"  "<<customerId<< endl;
            found = true;
        }

    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        cerr << "Customer ID not found." << endl;
        remove("temp_customer_registration.txt");
        return;
    }

    if (remove("customer_registration.txt") != 0) {
        cerr << "Error deleting the original file." << endl;
        return;
    }

    if (rename("temp_customer_registration.txt", "customer_registration.txt") != 0) {
        cerr << "Error renaming the temporary file." << endl;
        return;
    }

    cout << "Mobile number has been successfully updated." << endl;
}
void Customer::ChangePassword() {
     SmartCDS smartCDS;

    smartCDS.display();;
    cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
    cout << "=====================================================================\n" << endl;

    string id;
    cout << "Enter your ID: ";
    cin >> id;

    string currentPassword;
    cout << "Enter your current password: ";
    cin >> currentPassword;

    string newPassword;
    cout << "Enter your new password: ";
    cin >> newPassword;

    ifstream inputFile("customer_registration.txt");
    ofstream tempFile("temp_customer_registration.txt");

    if (!inputFile || !tempFile)
    {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;

    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string cusername, cpassword, cfname, clname, cmobile;

        ss >> cusername >> cpassword >> cfname >> clname >> cmobile>>customerId;

        if (customerId==id)
        {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << newPassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile<<"  "<<customerId
                     << endl;
            found = true;
            cout << "Password changed successfully." << endl;
        }
        else
        {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile<<"  "<<customerId
                     << endl;
        }

    }

    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cerr << "Invalid ID or current password." << endl;
        remove("temp_customer_registration.txt");
        return;
    }

    if (remove("customer_registration.txt") != 0)
    {
        cerr << "Error deleting the original file." << endl;
        return;
    }

    if (rename("temp_customer_registration.txt", "customer_registration.txt") != 0)
    {
        cerr << "Error renaming the temporary file." << endl;
        return;
    }
}

void Customer::login() {

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

void Customer::main() {

    SmartCDS smartCDS;
    smartCDS.run();

}
