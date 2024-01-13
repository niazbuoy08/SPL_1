#include "Admin.h"
#include "SmartCDS.h"
#include <iostream>

Admin::Admin(const std::string& username, const std::string& password, const std::string& firstName,
             const std::string& lastName, const std::string& mobileNumber)
    : User(username, password, firstName, lastName, mobileNumber) {}

Admin::Admin() : User("default_username", "default_password", "Admin", "", "") {

}

void Admin::displayProfile() const {
    std::cout << "Admin Profile: " << firstName << " " << lastName << " (" << username << ")" << std::endl;
}

void Admin::AdminPage() {
    display();
    std::cout << "----------------------------- ADMIN -----------------------------\n" << std::endl;
    std::cout << "=================================================================\n" << std::endl;

    int c;

    std::cout << "1. Add New Food\n" << std::endl;
    std::cout << "2. Edit Food\n" << std::endl;
    std::cout << "3. Delete Food\n" << std::endl;
    std::cout << "4. Inventory\n" << std::endl;
    std::cout << "5. Show All food items\n" << std::endl;
    std::cout << "6. Add Salesperson\n" << std::endl;
    std::cout << "7. Go to Login Page\n" << std::endl;
    std::cout << "8. Go to Welcome Page\n" << std::endl;
    std::cout << "9. Exit\n" << std::endl;

    std::cout << "***************************************************************\n" << std::endl;
    std::cout << "Please select your option(1-9)" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    switch(c)
       {
        case 1:
              system("cls");
              AddNewFood();
              break;

        case 2:
              system("cls");
              EditFood();
              break;

        case 3:
              system("cls");
              DeleteFood();
              break;

        case 4:
              system("cls");
              Inventory();
              break;

        case 5:
              system("cls");
              ShowAllFoodItems();
              break;

        case 6:
              system("cls");
              AddSalesperson();
              break;

        case 7:
              system("cls");
              login();
              break;

        case 8:
              system("cls");
              main();
              break;

        case 9:
            system("cls");
            std::cout << "Exiting the program\n" << std::endl;
            break;

        default:
            system("cls");
            std::cout << "Wrong input" << std::endl;
    }
}

void Admin::display() {
    std::cout << "################################################################\n" << std::endl;
    std::cout << "########################## SMARTCDS ############################\n" << std::endl;
    std::cout << "################################################################\n" << std::endl;
    std::cout << "================================================================\n" << std::endl;
}

void Admin::AddNewFood() {
    // Implementation of AddNewFood
}

void Admin::EditFood() {
    // Implementation of EditFood
}

void Admin::DeleteFood() {
    // Implementation of DeleteFood
}

void Admin::Inventory() {
    // Implementation of Inventory
}

void Admin::ShowAllFoodItems() {
    // Implementation of ShowAllFoodItems
}

void Admin::AddSalesperson() {
    // Implementation of AddSalesperson
}

void Admin::login() {
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
        //loginAsAdmin();
        break;

    case 2:
        system("cls");
        //loginAsCustomer();
        break;

    case 3:
        system("cls");
        //run();
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


void Admin::main() {
    // Implementation of main
}

