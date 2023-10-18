#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void display();

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

   }
   void registerAsCustomer()
   {
    display();
    cout << "--------------------------- REGISTER --------------------------\n" << endl;
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

       }else
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


