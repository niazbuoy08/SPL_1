#include "Admin.h"
#include "SmartCDS.h"
#include <iostream>
#include <iomanip>

using namespace std;

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

void Admin::YesOrNoCheck() {
    char choice;
    std::cout << "Enter [Y] for Yes or [N] for No: ";
    std::cin >> choice;

    while (toupper(choice) != 'Y' && toupper(choice) != 'N') {
        std::cout << "Invalid input! Please enter [Y] for Yes or [N] for No: ";
        std::cin >> choice;
    }

    if (toupper(choice) == 'Y') {
        system("cls");
        AddNewFood(); // Call the function to add another product
    } else {
        system("cls");
        AdminPage(); // Go back to the Admin page
    }
}


 string pname;
   string cname;

   double uprice;
   int quantity;
   int discount;

void Admin::AddNewFood() {
     display();
   cout << "----------------------------- ADMIN -----------------------------\n" << endl;
   cout << "=================================================================\n" << endl;


   ofstream file("products.txt",ios::app);

   cout<<"Enter Product Name for the next product:";
   cin>>pname;
   cout<<"Enter Company Name for the next product:";
   cin>>cname;
   cout<<"Enter Unit-Price for the next product:";
   cin>>uprice;
   cout<<"Enter Quantity for the next product:";
   cin>>quantity;
   cout<<"Enter discount for the next product:";
   cin>>discount;

   file<<pname<<"	  "<<cname<<"		  "<<uprice<<"		 "<<quantity<<"      "<<discount<<endl;
   file.close();

   cout<<"Product has been successfully added"<<endl;

   cout<<"======================================================================\n"<<endl;

   cout<<"Do you want to add another product?([Yes] or [No]):";

   YesOrNoCheck();
}
void Admin::UpdateInventory(const std::string& productName, int quantity) {
    // Read existing inventory from file
    std::ifstream inputFile("products.txt");
    std::ofstream tempFile("temp_products.txt");

    if (!inputFile || !tempFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;

    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string pname, cname, uprice, oldQuantity, discount;

        ss >> pname >> cname >> uprice >> oldQuantity >> discount;

        // Check if the current line contains the product to update
        if (pname == productName) {
            // Update the quantity
            int updatedQuantity = std::stoi(oldQuantity) - quantity;
            if (updatedQuantity < 0) {
                std::cerr << "Error: Insufficient quantity in inventory." << std::endl;
                inputFile.close();
                tempFile.close();
                return;
            }

            // Write the updated line to the temporary file
            tempFile << pname << "  " << cname << "  " << uprice << "  " << updatedQuantity << "  " << discount << std::endl;
        } else {
            // Write the unchanged line to the temporary file
            tempFile << pname << "  " << cname << "  " << uprice << "  " << oldQuantity << "  " << discount << std::endl;
        }
    }

    inputFile.close();
    tempFile.close();

    // Replace the original file with the temporary file
    if (remove("products.txt") != 0) {
        std::cerr << "\n\tError: File does not exist." << std::endl;
    }

    if (rename("temp_products.txt", "products.txt") != 0) {
        std::cerr << "\n\tError: File cannot be renamed." << std::endl;
    }

    std::cout << "\n\tInventory updated successfully." << std::endl;
}

void Admin::EditFood() {
   display();
    cout << "-------------------------- EDIT FOOD --------------------------\n" << endl;
    cout << "===============================================================\n" << endl;

    ifstream inputFile("products.txt");
    ofstream tempFile("temp_products.txt");

    if (!inputFile || !tempFile) {
        cout << "Error opening file." << endl;
        return;
    }

    int prodNumber = 1;
    string line;
    string itemToModify;
    int newQuantity, newDiscount;
    string newPrice;

    cout << setw(7) << "PROD.NO" << setw(24) << "Product Name" << setw(19) << "Company"
         << setw(14) << "Unit Price" << setw(12) << "Quantity" << setw(12) << "Discount" << endl;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;

        ss >> pname >> cname >> uprice >> quantity >> discount;

        cout << setw(7) << prodNumber << "  " << setw(20) << pname << "  " << setw(20) << cname
             << "  " << setw(10) << uprice << "  " << setw(10) << quantity << "  "
             << setw(10) << discount<<endl;
        prodNumber++;
    }

    inputFile.close();

    cout<<"Enter the product number you want to modify: ";
    cin>>itemToModify;

    cout<<"Enter the new quantity: ";
    cin>>newQuantity;

    cout<<"Enter the new price: ";
    cin>>newPrice;

    cout<<"Enter the new discount: ";
    cin>>newDiscount;

    inputFile.open("products.txt");

    prodNumber = 1;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;

        ss >> pname >> cname >> uprice >> quantity >> discount;

        if (prodNumber != stoi(itemToModify)) {
            tempFile<<setw(20)<<left<<pname<<"  "<<setw(20)<<left<<cname<<"  "
                    <<setw(10)<<left<<uprice<<"  "<<setw(10)<<left<<quantity<<"  "
                    <<setw(10)<<left<<discount<<endl;
        } else {
            tempFile<<setw(20)<<left<<pname<<"  "<<setw(20)<<left<<cname<<"  "
                    <<setw(10)<<left<<newPrice<<"  "<<setw(10)<<left<<newQuantity
                    <<"  "<<setw(10)<<left<<newDiscount<<endl;
        }

        prodNumber++;
    }

    inputFile.close();
    tempFile.close();

    remove("products.txt");
    rename("temp_products.txt", "products.txt");

    cout<<"Quantity, price and discount modified successfully."<<endl;


       cout << "1. Go to Admin Page\n" <<endl;
       cout << "2. Go to Login Page\n" <<endl;
       cout << "3. Go to Welcome Page\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-3)" <<endl;

       int c;

       cin>>c;

       cout<<endl;

       switch(c)
       {
        case 1:
              system("cls");
              AdminPage();
              break;

        case 2:
              system("cls");
              login();
              break;

        case 3:
              system("cls");
              main();
              break;

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }

}

void Admin::DeleteFood() {

     string pname2;

    display();
    cout << "----------------------------- DELETE FOOD -----------------------------\n" << endl;
    cout << "=======================================================================\n" << endl;

    ifstream inputFile("products.txt");
    ofstream tempFile("tempo_products.txt");

    if (!inputFile || !tempFile) {
        cout << "Error opening file." << endl;
        return;
    }

    int prodNumber = 1;
    string line;
    string itemTodelete;

    cout << setw(7) << "PROD.NO" << setw(24) << "Product Name" << setw(19) << "Company"
         << setw(14) << "Unit Price" << setw(12) << "Quantity" << setw(12) << "Discount" << endl;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;

        ss >> pname >> cname >> uprice >> quantity >> discount;

        cout << setw(7) << prodNumber << "  " << setw(20) << pname << "  " << setw(20) << cname
             << "  " << setw(10) << uprice << "  " << setw(10) << quantity << "  " << setw(10) << discount << endl;
        prodNumber++;
    }

    inputFile.close();

    cout<<"Enter the Product No to delete:";
    cin>>itemTodelete;
    inputFile.open("products.txt");
    prodNumber = 1;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;

        ss >> pname >> cname >> uprice >> quantity >> discount;

        if (prodNumber != stoi(itemTodelete)) {
            tempFile << setw(20) << left << pname << "  " << setw(20) << left << cname << "  "
                     << setw(10) << left << uprice << "  " << setw(10) << left << quantity << "  "
                     << setw(10) << left << discount << endl;
        }

        prodNumber++;
    }

    inputFile.close();
    tempFile.close();

    if(remove("products.txt")!=0)
    {
        cout<<"\n\tFile does not exist";
    }

    if(rename("tempo_products.txt","products.txt")!=0)
    {
        cout<<"\n\tFile can not be renamed.";
    }

    cout << "\n\tProduct deleted successfully." << endl;


       cout << "1. Go to Admin Page\n" <<endl;
       cout << "2. Go to Login Page\n" <<endl;
       cout << "3. Go to Welcome Page\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-3)" <<endl;

       int c;

       cin>>c;
       cout<<endl;

       switch(c)
       {
        case 1:
              system("cls");
              AdminPage();
              break;

        case 2:
              system("cls");
              login();
              break;

        case 3:
              system("cls");
              main();
              break;

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }

}

void Admin::Inventory() {
    display();
    cout << "----------------------------- ADMIN -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

    ifstream file("products.txt");

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    int prodNumber = 1;

    cout << setw(7) << "PROD.NO" << setw(24) << "Product Name" << setw(19) << "Company"
         << setw(14) << "Unit Price" << setw(12) << "Quantity" << setw(12) << "Discount" << endl;


    while (getline(file, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;


        ss >> pname >> cname >> uprice >> quantity >> discount;


        cout << setw(7) << prodNumber << "  " << setw(20) << pname << "  " << setw(20) << cname
             << "  " << setw(10) << uprice << "  " << setw(10) << quantity << "  " << setw(10) << discount << endl;
        prodNumber++;
    }

    file.close();

       cout << "1. Go to Admin Page\n" <<endl;
       cout << "2. Go to Login Page\n" <<endl;
       cout << "3. Go to Welcome Page\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-3)" <<endl;

       int c;

       cin>>c;

       cout<<endl;

       switch(c)
       {
        case 1:
              system("cls");
              AdminPage();
              break;

        case 2:
              system("cls");
              login();
              break;

        case 3:
              system("cls");
              main();
              break;

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }
}

void Admin::ShowAllFoodItems() {
    // Implementation of ShowAllFoodItems
}

void Admin::AddSalesperson() {
    SmartCDS smartCDS;
    smartCDS.AddSalesperson();
}

void Admin::login() {
    int option;
    display();

    SmartCDS smartCDS;

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

void Admin::main() {

    SmartCDS smartCDS;
    smartCDS.run();

}

