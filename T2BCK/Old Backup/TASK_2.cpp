//Standard Library inclusions
#include <iostream>
#include <cstdlib> //Library import for random number generation and memory management.
#include <chrono>
#include <ctime> //Library import for random number generation primarily used for Server_Services class. Also used for logging actions.
#include <fstream> //Library for importing and exporting files. This will be used to log user actions.
#include <string>

//Implemented Library inclusions
#include "Read_User_Input.h" //This includes a header file which is used for all user input.
#include "User.h" //This includes a header file where the User class is stored.
#include "Server_Service.h" //This includes a header file where the Server_Services class is stored.
#include "Log_User_Action.h"

//Function prototypes:
void Log_In(int& Current_User, char& User_Input,User* Standard_User, User* Admin);


int main(){
    //General setup for the program to work.
    std::fstream Log;
    Log.open("Log.txt", std::ios::trunc);

    Log.open("Log.txt", std::ios::out);
    Log_User_Action(Log);
    for(int i = 0; i < 100; i++){
        Log_User_Action("Some txt", Log);
    }
    Log.close();

    //Read_Log(Log);

    srand(time(nullptr)); //We use this command from the cstdlib to make every use of rand() command non-sequential.

    User* Admin = new User; //Here we create User class object "Admin" for later use. This object will have more functionality than Standard_User object. This object will also have "Administration rights".
    Admin->setUsername("Admin"); //Setting Username and Password for our "Admin" object - it cannot be change later on.
    Admin->setPassword("admin");

    Server_Service Main; //We create the main Server_Services class object "Main". This object will be used to track all the available storage of the service.
    // Upon calling this object we initiate a constructor which will generate the random amount of available space for the services and allocate it to the heap.
    //Server_Service::getMaximumOverallStorageAmount(); //For debugging.

    User* Standard_User = new User; //Create a User class object "Standard_User" so that a regular user can use the services.

    User* Dummy_User = new User;
    Dummy_User->setUsername("Dummy");
    Dummy_User->AddCloudStorageAmount(1500);

    char User_Input; //Create a char "User_Input" which will be used with the Read_User_Input header file to read user Input and react accordingly.
    static int Current_User; //Create a static int which will tell us which user is logged in: (!User class!) (1) Admin or (2) (Standard) User.
    //End of setup.
    //Debugging.
    Standard_User->getCloudStorageAmount();
    Standard_User->AddCloudStorageAmount(250);
    Standard_User->getCloudStorageAmount();
    Standard_User->AddCloudStorageAmount(200);
    Standard_User->getCloudStorageAmount();
    Standard_User->AddCloudStorageAmount(50);
    Standard_User->getCloudStorageAmount();
    Server_Service::getMaximumOverallStorageAmount();
    Standard_User->FreeCloudStorageAmount(500);
    Standard_User->getCloudStorageAmount();
    Server_Service::getMaximumOverallStorageAmount();
    Standard_User->getCloudStorageAmount();
    Standard_User->AddCloudStorageAmount(250);
    Standard_User->getCloudStorageAmount();

    std::cout << "Admin: \n";

    Admin->getCloudStorageAmount();
    Admin->AddCloudStorageAmount(250);
    Admin->getCloudStorageAmount();
    Admin->AddCloudStorageAmount(200);
    Admin->getCloudStorageAmount();
    Admin->AddCloudStorageAmount(50);
    Admin->getCloudStorageAmount();
    Server_Service::getMaximumOverallStorageAmount();
    Admin->FreeCloudStorageAmount(500);
    Admin->getCloudStorageAmount();
    Server_Service::getMaximumOverallStorageAmount();

    Server_Service::Print_Total_Storage_Amount();
    Server_Service::getMaximumOverallStorageAmount();

    std::cout << "Welcome to the electronic server cloud storage services.\n";

    while(true){
        Log_In(Current_User, User_Input, Standard_User, Admin);

        if(User_Input == '0'){
            break;
        }
        else{
            Server_Service::Server_Interface(Current_User, User_Input, Standard_User, Admin, Dummy_User);
            Server_Service::getMaximumOverallStorageAmount(); //For debugging. Check with the first function call; if the output is the same, then everything works.
        }
    }

    remove("Log.txt");

    std::cin.get(); //For debugging.
    return 0;

}

void Log_In(int& Current_User, char& User_Input,User* Standard_User, User* Admin){
    while(true){ //Main loop for execution. 1st step: log in; 2nd step: (1) Admin or (2) User functionality execution; 3rd step: Log out and log back in /or/ exit program. !Not everything is implemented yet!

        Current_User = 0; //Everytime this loop starts set Current_User to 0 (equivalent to NULL). This is done so that we can avoid bugs and throw an exception in the future if this gets bypassed.

        if(Standard_User->getUsername() == "User"){ //If the user starts up the program for the first time this <if> statement is going to be true and a regular user will be prompted to create an account.
            Read_User_Input(User_Input, 2); //Call the Read_User_Input function from Read_User_Input header file.
            if(User_Input == '1'){ //Log in as Admin.
                if(Admin->UserLogin()){ //Calls function to enter Username and Password for Admin object. If true, proceed.
                    Current_User = 1; //Set Current_User to 1 (1 = Admin)
                    break; //Break /or/ continue past this point. !Not implemented yet!
                }
            }
            if(User_Input == '2'){ //Create new user.
                Create_New_User(Standard_User); //Calls function from User header file.
            }
            if(User_Input == '0'){
                break;
            }
        }
        else if(Standard_User->getUsername() != "User"){ //Only log in as Admin or User.
            Read_User_Input(User_Input, 3); //Calls function from Read_User_Input header.
            if(User_Input == '1'){ //Log in as Admin.
                if(Admin->UserLogin()){
                    Current_User = 1;
                    break;
                }
            }
            if(User_Input == '2'){ //Log in as user.
                if(Standard_User->UserLogin()){ //Calls function to enter Username and Password for Standard_User object.
                    Current_User = 2;
                    break;
                }
            }
            if(User_Input == '0'){
                break;
            }
        }
    }
}