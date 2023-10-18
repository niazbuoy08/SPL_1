#include<iostream>
#include<fstream>
#include <sstream>
#include<string.h>
using namespace std;

void login();
void registration();
void display();
void AddNewFood();
void YesOrNoCheck();
void AdminPage();
void EditFood();
void DisplayAllItems();

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

    string username, password;

    cout << "Enter  username: ";
    cin >> username;

    cout << "Enter  password: ";
    cin >> password;

    ofstream file("admin_registration.txt", ios::app);

    if (!file) {
        cerr << "Error opening the file!" << endl;
        return;
    }


    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
    void AdminPage();


   }
   void registerAsCustomer()
   {
    display();
    cout << "--------------------------- REGISTER--------------------------\n" << endl;
    cout << "===============================================================\n" << endl;

    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    ofstream file("customer_registration.txt", ios::app);

    if (!file) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;

   }
   void loginAsAdmin()
   {
       display();
       cout << "----------------------------- LOGIN -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

       int count;

       string userID, password, id, pass;

       cout<<"\t\t\t Please enter your username and password "<<endl;

       cout<<"USERNAME: ";

       cin>>userID;

       cout<<"PASSWORD: ";

       cin>>password;

       ifstream input("admin_registration.txt");

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
           AdminPage();

       }
       else
       {
           cout<<" LOGIN ERROR \n Please check username and password \n";
       }


   }
   void loginAsSalesperson()
   {

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
           AdminPage();

       }else
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

       cout << "1.Add New Food\n" <<endl;
       cout << "2.Edit Food\n" <<endl;
       cout << "3.Delete Food\n" <<endl;
       cout << "4.Inventory\n" <<endl;
       cout << "5.Show All food items\n" <<endl;
       cout << "6.Add Salesperson\n" <<endl;
       cout << "7.Go to Login Page\n" <<endl;
       cout << "8.Go to Welcome Page\n" <<endl;
       cout << "9.Exit\n" <<endl;

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

        case 5:
              system("cls");
              DisplayAllItems();
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
   void AddNewFood()
   {
   display();
   cout << "----------------------------- ADMIN -----------------------------\n" << endl;
   cout << "=================================================================\n" << endl;

   string pname;
   string cname;

   double uprice;
   int quantity;
   int discount;
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
        main();
    }
   }

   void DisplayAllItems() {

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

    cout << "PROD.NO\tProduct Name\tCompany\tUnit Price\tQuantity\tDiscount" << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string pname, cname, uprice, quantity, discount;


        ss >> pname >> cname >> uprice >> quantity >> discount;


        cout << prodNumber << "\t" << pname << "\t" << cname << "\t" << uprice << "\t" << quantity << "\t" << discount << endl;
        prodNumber++;
    }

    file.close();
}


   void EditFood()
   {
       display();
       cout << "----------------------------- ADMIN -----------------------------\n" << endl;
       cout << "=================================================================\n" << endl;

   }





