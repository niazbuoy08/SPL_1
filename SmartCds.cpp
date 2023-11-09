#include<iostream>
#include<fstream>
#include <sstream>
#include<string.h>
#include <conio.h>
#include <iomanip>
using namespace std;

void login();
void registration();
void display();
void AddNewFood();
void YesOrNoCheck();
void AdminPage();
void EditFood();
void Inventory();
void DeleteFood();
void AddSalesperson();
void CustomerPage();
void UpdateProfile();
void SalesPersonPage();
void PlaceOrder();
void GenerateInvoice(const string& productName, int quantity);
void ShowAllFoodItems();
void UpdateName();
void UpdateMobileNumber();


string getPassword() {
    string password = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13)
            break;
        password.push_back(ch);
        cout << "*";
    }
    cout << endl;
    return password;
}

int main()
{
   int option;

   display();
   cout << "---------------------- Welcome to SMARTCDS ---------------------\n" <<endl;
   cout << "================================================================\n" <<endl;
   cout << "1. REGISTER\n" <<endl;
   cout << "2. LOGIN\n" <<endl;
   cout << "3. EXIT\n" <<endl;
   cout << "****************************************************************\n" <<endl;

   cin >> option;
   cout << endl;

   switch(option)
   {
       case 1:
           system("cls");
           registration();
           break;

       case 2:
           system("cls");
           login();
           break;

       case 3:
           system("cls");
           cout << "Exiting the program\n" << endl;
           break;

       default:
           system("cls");
           cout << "Invalid option. Please select an option between 1 and 3" <<endl;

   }
}



   void login()
   {
       int  option;
       void loginAsAdmin();
       void loginAsSalesperson();
       void loginAsCustomer();

       display();
       cout << "-------------------------- LOGIN --------------------------\n" << endl;
       cout << "===========================================================\n" << endl;
       cout << "1. As an ADMIN\n" << endl;
       cout << "2. As a SALESPERSON\n" << endl;
       cout << "3. As a CUSTOMER\n" << endl;
       cout << "4. Return to Welcome Page\n" << endl;
       cout << "5. EXIT\n" << endl;
       cout << "***********************************************************" << endl;

       cin >> option;
       cout << endl;

       switch (option) {
        case 1:
            system("cls");
            loginAsAdmin();
            break;

        case 2:
            system("cls");
            loginAsSalesperson();
            break;

        case 3:
            system("cls");
            loginAsCustomer();
            break;

        case 4:
            system("cls");
            main();
            break;

        case 5:
            system("cls");
            cout << "Exiting the program\n" << endl;
            break;

        default:
            system("cls");
            cout << "Invalid option. Please select an option between 1 and 5" << endl;
    }
   }

   void registration()
   {
       int  option;
       void registerAsAdmin();
       void registerAsCustomer();

       display();
       cout << "--------------------------- REGISTER --------------------------\n" << endl;
       cout << "===============================================================\n" << endl;
       cout << "1. As an ADMIN\n" << endl;
       cout << "2. As a CUSTOMER\n" << endl;
       cout << "3. Return to Welcome Page\n" << endl;
       cout << "4. EXIT\n" << endl;
       cout << "***************************************************************" << endl;

       cin >> option;
       cout << endl;

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
            main();
            break;

        case 4:
            system("cls");
            cout << "Exiting the program\n" << endl;
            break;

        default:
            system("cls");
            cout << "Invalid option. Please select an option between 1 and 4" << endl;
    }
   }


   void registerAsAdmin()
   {
      display();
    cout << "--------------------------- REGISTER --------------------------\n" << endl;
    cout << "===============================================================\n" << endl;

    string username, password, fname, lname, mobile;

    cout << "Enter  username: ";
    cin >> username;

    cout << "Enter  password: ";
    cin >> password;

    cout << "Enter  your First Name: ";
    cin >> fname;

    cout << "Enter  your Last Name: ";
    cin >> lname;

    cout << "Enter  Mobile Number: ";
    cin >> mobile;

    ofstream file("admin_registration.txt", ios::app);

    if (!file) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    file << username << " " << password << " " << fname << " " << lname << " " << mobile <<  endl;
    file.close();

    cout << "Registration successful!" << endl;

   }
   string cusername, cpassword, cfname,clname, cmobile ;

   void registerAsCustomer()
   {
    display();
    cout << "--------------------------- REGISTER--------------------------\n" << endl;
    cout << "===============================================================\n" << endl;

    string username, password, fname,lname, mobile ;

    cout << "Enter a username: ";
    cin >> cusername;

    cout << "Enter a password: ";
    cin >> cpassword;

    cout << "Enter  your First Name: ";
    cin >> cfname;

    cout << "Enter  your Last Name: ";
    cin >> clname;

    cout << "Enter  Mobile Number: ";
    cin >> cmobile;

    ofstream file("customer_registration.txt", ios::app);

    if (!file) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    file<<setw(20)<<left<<cusername<<"  "<<setw(20)<<left<<cpassword<<"  "
                    <<setw(10)<<left<<cfname<<"  "<<setw(10)<<left<<clname<<"  "<<left<<cmobile
                    <<endl;
    file.close();

    cout << "Registration successful!" << endl;

   }

   void AddSalesperson()
   {
    display();
    cout << "--------------------------- REGISTER--------------------------\n" << endl;
    cout << "===============================================================\n" << endl;

    string username, password, fname,lname, mobile ;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    cout << "Enter  your First Name: ";
    cin >> fname;

    cout << "Enter  your Last Name: ";
    cin >> lname;

    cout << "Enter  Mobile Number: ";
    cin >> mobile;

    ofstream file("salesperson_registration.txt", ios::app);

    if (!file) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    file << username << " " << password << " " << fname << " " << lname << " " << mobile <<  endl;
    file.close();

    cout << "Registration successful!" << endl;

   }


   void loginAsAdmin()
   {

    display();
    cout << "----------------------------- LOGIN -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

    int count = 0;
    string userID, password, id, pass;

    cout << "\t\t\t Please enter your username and password" << endl;

    cout << "USERNAME: ";
    cin >> userID;

    cout << "PASSWORD: ";
    password = getPassword(); // Call getPassword to hide the password input

    ifstream input("admin_registration.txt");

    if (!input) {
        cerr << "Error opening the file!" << endl;
        return;
    }

      while (input >> id >> pass) {
        cout << "Read from file: id=" << id << ", pass=" << pass << endl; // Debugging output
        string restOfLine;
        getline(input, restOfLine); // Read the rest of the line (i.e., the firstname, lastname, mobile)
        if (id == userID && pass == password) {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1) {
        cout << userID << " your login is successful\n Thanks for logging in \n";
        AdminPage();
    }
    else {
        cout << "LOGIN ERROR\n Please check username and password \n";
        return;
    }




   }
   void loginAsSalesperson()
   {

       display();
       cout << "----------------------------- LOGIN -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int count;

       string userID, password, id, pass;

       cout<<"\t\t\t Please enter your username and password"<<endl;

       cout<<"USERNAME: ";

       cin>>userID;

       cout<<"PASSWORD: ";

       cin>>password;

       ifstream input("salesperson_registration.txt");

       while(input>>id>>pass)
       {
           if(id==userID && pass==password)
           {
               count=1;
               system("cls");
           }
       }

       input.close();

       if(count==1)
       {
           cout<<userID<<" your login is successful\n Thanks for logging in \n";
           SalesPersonPage();
       }
       else
       {
           cout<<" LOGIN ERROR \n Please check username and password \n";
       }


   }
   void loginAsCustomer()
   {
       display();
       cout << "----------------------------- LOGIN -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int count;

       string userID, password, id, pass;

       cout<<"\t\t\t Please enter your username and password"<<endl;

       cout<<"USERNAME: ";

       cin>>userID;

       cout<<"PASSWORD: ";

       cin>>password;

       ifstream input("customer_registration.txt");

       while(input>>id>>pass)
       {
           if(id==userID && pass==password)
           {
               count=1;
               system("cls");
           }
       }

       input.close();

       if(count==1)
       {
           cout<<userID<<" your login is successful\n Thanks for logging in \n";
           CustomerPage();

       }
       else
       {
           cout<<" LOGIN ERROR \n Please check username and password \n";
       }

   }

   void display()
   {
       cout << "################################################################\n" <<endl;
       cout << "########################## SMARTCDS ############################\n" <<endl;
       cout << "################################################################\n" <<endl;
       cout << "================================================================\n" <<endl;

   }

   void AdminPage()
   {
       display();
       cout << "----------------------------- ADMIN -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int c;

       cout << "1. Add New Food\n" <<endl;
       cout << "2. Edit Food\n" <<endl;
       cout << "3. Delete Food\n" <<endl;
       cout << "4. Inventory\n" <<endl;
       cout << "5. Show All food items\n" <<endl;
       cout << "6. Add Salesperson\n" <<endl;
       cout << "7. Go to Login Page\n" <<endl;
       cout << "8. Go to Welcome Page\n" <<endl;
       cout << "9. Exit\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-9)" <<endl;
       cin>>c;
       cout<<endl;

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

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }
   }

   string pname;
   string cname;

   double uprice;
   int quantity;
   int discount;
   void AddNewFood()
   {

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

   file<<pname<<"		"<<cname<<"		  "<<uprice<<"		 "<<quantity<<"      "<<discount<<endl;
   file.close();

   cout<<"Product has been successfully added"<<endl;

   cout<<"===============================================\n"<<endl;

   cout<<"Do you want to add another product?([Yes] or [No]):";

   YesOrNoCheck();


}

   void YesOrNoCheck()
   {
    string op;
    cin>>op;

    if (op == "Yes" )
    {
        system("cls");
        AddNewFood();

    }
    else if(op == "No" )
    {
        system("cls");
        AdminPage();

    }

   }

   void Inventory() {

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



   void EditFood()
   {
    display();
    cout << "----------------------- EDIT FOOD -----------------------\n" << endl;
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
void DeleteFood()
 {
    string pname2;

    display();
    cout << "----------------------------- DELETE FOOD -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

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


   void CustomerPage()
   {
       display();
       cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int c;

       cout << "1. Purchase History(Last 7 days)\n" <<endl;
       cout << "2. Update Profile\n" <<endl;
       cout << "3. Change Password\n" <<endl;
       cout << "4. Go to Login Page\n" <<endl;
       cout << "5. Go to Welcome Page\n" <<endl;
       cout << "6. Exit\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-6)" <<endl;
       cin>>c;
       cout<<endl;

       switch(c)
       {
        case 1:
              system("cls");
              break;

        case 2:
              system("cls");
              UpdateProfile();
              break;
        case 3:
              system("cls");
              break;
        case 4:
              system("cls");
              login();
              break;

        case 5:
              system("cls");
              main();
              break;

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }
   }

    void UpdateProfile()
   {
       display();
       cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int c;

       cout << "1. Update Name\n" <<endl;
       cout << "2. Update Mobile Number\n" <<endl;
       cout << "3. Go to Login Page\n" <<endl;
       cout << "4. Go to Welcome Page\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-4)" <<endl;
       cin>>c;
       cout<<endl;

       switch(c)
       {
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
                cout<<"Wrong input"<<endl;
              }



   }

   void SalesPersonPage()
   {
       display();
       cout << "----------------------------- SalesPerson -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int c;

       cout << "1. Place Order\n" <<endl;
       cout << "2. Add New Customer\n" <<endl;
       cout << "3. Go to Login Page\n" <<endl;
       cout << "4. Go to Welcome Page\n" <<endl;
       cout << "5. Exit\n" <<endl;

       cout << "***************************************************************\n" <<endl;
       cout << "Please select your option(1-4)" <<endl;
       cin>>c;
       cout<<endl;

       switch(c)
       {
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

        default:
                system("cls");
                cout<<"Wrong input"<<endl;
              }

   }
 void PlaceOrder()
{
    display();
    cout << "----------------------------- PLACE ORDER -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

    string productName;
    int quantity;

    cout << "Enter the Product Name: ";
    cin.ignore();
    getline(cin, productName);

    cout << "Enter the Quantity: ";
    cin >> quantity;

    ifstream productsFile("products.txt");
    ofstream tempFile("temp_products.txt");

    if (!productsFile || !tempFile)
    {
        cout << "Error opening files." << endl;
        return;
    }

    string line;
    bool productFound = false;

    while (getline(productsFile, line))
    {
        stringstream ss(line);
        string pname, cname;
        double uprice;
        int availableQuantity, discount;

        ss >> pname >> cname >> uprice >> availableQuantity >> discount;

        if (pname == productName)
        {
            if (availableQuantity >= quantity)
            {
                productFound = true;
                availableQuantity -= quantity;
                tempFile << setw(20) << left << pname << "  " << setw(20) << left << cname << "  "
                         << setw(10) << left << uprice << "  " << setw(10) << left << availableQuantity << "  "
                         << setw(10) << left << discount << endl;

                // You can add code to record this order in a separate order history file here.

                cout << "Order placed successfully!" << endl;
            }
            else
            {
                cout << "Insufficient quantity available for the selected product." << endl;
                productFound = true;
            }
        }
        else
        {
            tempFile << setw(20) << left << pname << "  " << setw(20) << left << cname << "  "
                     << setw(10) << left << uprice << "  " << setw(10) << left << availableQuantity << "  "
                     << setw(10) << left << discount << endl;
        }
    }

    if (!productFound)
    {
        cout << "Product not found in the inventory." << endl;
    }

    productsFile.close();
    tempFile.close();

    remove("products.txt");
    rename("temp_products.txt", "products.txt");

    cout << "1. Continue Ordering\n";
    cout << "2. Checkout\n";
    cout << "3. Go to Salesperson Page\n";

    int choice;

    cin >> choice;

    if (choice == 1) {
        system("cls");
        PlaceOrder();
    } else if (choice == 2) {
        // Generate an invoice for the order (you can implement this function)
        GenerateInvoice(productName, quantity);
    } else if (choice == 3) {
        system("cls");
        SalesPersonPage();
    }
}

void GenerateInvoice(const string& productName, int quantity)
{
    // Here, you can create an invoice, display it, and remove the product from the inventory.
    // You may want to create a new file for storing invoices and add code to manage it.

    // Display the invoice
    display();
    cout << "------------------------ INVOICE ------------------------\n";
    cout << "=======================================================\n";
    cout << "Product Name: " << productName << endl;
    cout << "Quantity: " << quantity << endl;
    // You can add more details to the invoice here.

    // Remove the product from the inventory (you can use a similar approach as in PlaceOrder)
    // Implement code to remove the product from the inventory file.

    cout << "Invoice generated successfully!" << endl;
    cout << "Product removed from inventory." << endl;

    // Go back to the Salesperson Page
    system("pause");
    system("cls");
    SalesPersonPage();
}
void ShowAllFoodItems() {

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
         << endl;


    while (getline(file, line)) {
        stringstream ss(line);
        string pname, cname;


        ss >> pname >> cname ;


        cout << setw(7) << prodNumber << "  " << setw(20) << pname << "  " << setw(20) << cname
              << endl;
        prodNumber++;
    }

    file.close();

       cout << "1. Go to Admin Page\n" <<endl;
       cout << "2. Go to Login Page\n" <<endl;
       cout << "3. Go to Welcome Page\n" <<endl;

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
void UpdateName()
{
    display();
    cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

    int id;
    cout << "Enter your ID: ";
    cin >> id;

    string updatedName;
    cout << "Enter Updated Name: ";
    cin.ignore();
    getline(cin, updatedName);

    ifstream inputFile("customer_registration.txt");
    ofstream tempFile("temp_customer_registration.txt");

    if (!inputFile || !tempFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    int i = 1;
    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string cusername, cpassword, cfname, clname, cmobile;

        ss >> cusername >> cpassword >> cfname >> clname >> cmobile;

        if (i != id) {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile
                     << endl;

        } else {
            tempFile << setw(20) << left << updatedName << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname
                     << "  " << left << cmobile << endl;
            found = true;
        }
        i++;
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

void UpdateMobileNumber()
{
    display();
    cout << "----------------------------- CUSTOMER -----------------------------\n" << endl;
    cout << "=================================================================\n" << endl;

    int id;
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
    int i = 1;
    bool found = false;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string cusername, cpassword, cfname, clname, cmobile;

        ss >> cusername >> cpassword >> cfname >> clname >> cmobile;

        if (i != id) {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname << "  " << left << cmobile
                     << endl;

        } else {
            tempFile << setw(20) << left << cusername << "  " << setw(20) << left << cpassword << "  "
                     << setw(10) << left << cfname << "  " << setw(10) << left << clname
                     << "  " << left << updatedNumber << endl;
            found = true;
        }
        i++;
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














