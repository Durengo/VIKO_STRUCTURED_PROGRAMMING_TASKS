//Standard Library inclusions
#include <iostream>
#include <cstdlib> //Library import for random number generation and memory management.
#include <chrono>
#include <ctime> //Library import for random number generation primarily used for Server_Services class. Also used for logging actions.
#include <fstream> //Library for importing and exporting files. This will be used to log user actions.
#include <string>

//Implemented Library inclusions
#include "User.h" //This includes a header file where the User class is stored.
#include "User_List.h"
#include "Server_Service.h" //This includes a header file where the Server_Services class is stored.
//#include "Service_Usage_List.h"
#include "Log_User_Action.h"
#include "Read_User_Input.h" //This includes a header file which is used for all user input.
//#include "Console.h"

//Function prototypes:
void Log_In_Prompt(char& User_Input, User_List* UserList);
void Logged_In(char& User_Input, User_List* UserList);

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

    auto* UserList = new User_List;

    Create_User(UserList, "admin", "admin"); //Here we create User class object "Admin" and insert the object into a linked list User_List, for later use. This object will have more functionality than "regular user" User object. This object will also have "Administration rights". Setting Username and Password for our "Admin" object - it cannot be change later on.
    Create_User(UserList, "dummy", "dummy");

    Server_Service Main; //We create the main Server_Services class object "Main". This object will be used to track all the available storage of the service.
    // Upon calling this object we initiate a constructor which will generate the random amount of available space for the services and allocate it to the heap.
    Server_Service::getMaximumOverallStorageAmount(); //For debugging.

    char User_Input; //Create a char "User_Input" which will be used with the Read_User_Input header file to read user Input and react accordingly.
    //static int Current_User; //Create a static int which will tell us which user is logged in: (!User class!) (1) Admin or (2) (Standard) User.
    //End of setup.

    //Console::PTC("Welcome to the electronic server cloud storage services.");
    //Console::PTC("\nContinue?\n");
    //Console::Get_Input_Yes_Or_No();
    //console

    //Log_In_Prompt(User_Input, UserList);
    Logged_In(User_Input, UserList); //Call User Login CUI

    //remove("Log.txt");

    std::cin.get(); //For debugging.
    return 0;

}

void Logged_In(char& User_Input, User_List* UserList){
    while(true){
        Log_In_Prompt(User_Input, UserList);
        if(User::getCurrent_User_ID() == 0){
            break;
        }
        if(User::getCurrent_User_ID() == 1){
            while(true){
                Read_User_Input(User_Input, 3);
                if(User_Input == '0'){
                    break;
                }
                if(User_Input == '1'){
                    std::cout << "\nFunctionality not added yet.\n";
                }
                if(User_Input == '2'){
                    Server_Service::getMaximumOverallStorageAmountOfAllUsers(UserList);
                }
                if(User_Input == '3'){
                    Admin_Modify_Services_Value(UserList, User_Input);
                }
                if(User_Input == '4'){
                    Admin_Modify_User_Account_Info(UserList, User_Input);
                }
            }
        }
        else{
            while(true){
                Read_User_Input(User_Input, 4);
                if(User_Input == '0'){
                    break;
                }
                if(User_Input == '1'){
                    User_Modify_User_Account_Info(UserList, User_Input);
                    if(User::getCurrent_User_ID() == 0){
                        std::cout << "\n\nYou have been automatically logged out!\n\n";
                        break;
                    }
                }
                if(User_Input == '2'){
                    Server_Service::getMaximumOverallStorageAmountOfUser(UserList);
                }
                if(User_Input == '3'){
                    User_Modify_Services_Value(UserList, User_Input);
                }
            }
        }
    }
}

void Log_In_Prompt(char& User_Input, User_List* UserList){
    //Console::Login_Prompt(UserList);
        while(true){
        Read_User_Input(User_Input, 2); //Calls character user interface (CUI)
        if(User_Input == '0'){ //Exit
            break;
        }
        else if(User_Input == '1'){ //Call function UserLogin.
            if(UserLogin(UserList)){
                break;
            }
        }
        else if(User_Input == '2'){ //Create a "regular user" User class object and insert it into our linked list User_list; so that a regular user can use the services.
            std::string username;
            std::string password;

            std::cout << "\nEnter Username: ";
            std::cin >> username;
            std::cout << "\nEnter Password: ";
            std::cin >> password;
            Create_User(UserList, username, password);
        }
    }
}