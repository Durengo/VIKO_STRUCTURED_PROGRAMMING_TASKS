#pragma once

#include "User.h"
#include "../Linked_List_Test/User.h"

/*This "Server_Service" header file includes the Server_Service class which will be used alongside User class (from "User" header file).
 * 1st goal of this class is to randomly generate an amount of (<int>) data (referred to TB) for all the services; and allocate that memory to heap; this will be referred to as total storage amount.
 * 2nd goal of this class is to monitor any changes made to the total storage amount, log it, and send the information to the user class.*/

static int Maximum_Overall_Storage_Amount;

class Server_Service {
private:
    static int Total_Storage_Amount; //The main int for our total storage amount. We make this integer static so that it exists throughout the whole program execution runtime.

public:

    Server_Service() //Once an object is called we use this constructor to generate a random amount of total storage.
    {
        Generate_Total_Storage_Amount(); //Calls the function which generates a random amount of total storage.
        Server_Service::getTotalStorageAmount(); //For debugging.
    }

    static void getMaximumOverallStorageAmount() {
        std::cout << "\nUsing: " << Total_Storage_Amount << "TB out of " << Maximum_Overall_Storage_Amount << "TB.\n";
    }
    static void setMaximumOverallStorageAmount(int maximumOverallStorageAmount) {
        Maximum_Overall_Storage_Amount = maximumOverallStorageAmount;
    }
    static void setTotalStorageAmount(int totalStorageAmount) { //Setter for Total_Storage_Amount. We pass by reference to not copy and modify the main static integer.
        Total_Storage_Amount = totalStorageAmount;
    }
    static int getTotalStorageAmount() { //Getter for Total_Storage_Amount
        return Total_Storage_Amount;
    }
    static void Print_Total_Storage_Amount(){ //Function for printing the total storage amount.
        std::cout << "\nThere is " << Total_Storage_Amount << "TB available.\n";
    }


    static void Generate_Total_Storage_Amount(){ //This is the main function which generates a random amount of total storage.
        static int* RND = new int; //Create a new pointer and allocate it to heap.
        *RND = ((rand() % 100000) + 100000); //Allocate a randomly generated amount into the allocated memory slot.
        Server_Service::setTotalStorageAmount(*RND); //Set static int Total_Storage_Amount to our RND pointer. Pass by reference, so we modify the allocated heap memory.
        Server_Service::setMaximumOverallStorageAmount(*RND);
    }
    static void Use_Total_Storage_Amount(int Amount){
        Total_Storage_Amount = Total_Storage_Amount - Amount;
    }
    static void Free_Total_Storage_Amount(int Amount){
        Total_Storage_Amount = Total_Storage_Amount + Amount;
    }


    static void Server_Interface(int& Current_User, char& User_Input, User* Standard_User, User* Admin, User* Dummy_User){ //This function prints which user has logged into to the services.

        if(Current_User == 1){
            std::cout << "\nUsing services as admin!\n";
            Admin_Interface(User_Input, Standard_User, Dummy_User);
        }
        if(Current_User == 2){
            std::cout << "\nUsing services as user!\n";
            Standard_User_Interface(User_Input);
        }

    }
    static void Admin_Interface(char& User_Input, User* Standard_User, User* Dummy_User){
        while(true){
            std::cout << "\nPlease choose what you want to do:\n";
            Read_User_Input(User_Input, 4); //(0) Log out; (1) See Log files; (2) See services' usage statistics; (3) Modify User Services' Values; (4) Delete user account

            if(User_Input == '0'){
                break;
            }
            if(User_Input == '1'){
                std::cout << "\nnot here yet.\n";
            }
            if(User_Input == '2'){
                Print_Service_Statistics(Standard_User, Dummy_User);
            }
            if(User_Input == '3'){
                Modify_User_Info(Standard_User, Dummy_User, User_Input);
            }
            if(User_Input == '4'){
                break;
            }
        }
    }
    static void Standard_User_Interface(char& User_Input){
        std::cout << "\nCalling SUI\n";
    }


    static void Print_Service_Statistics(User* Standard_User, User* Dummy_User){
        getMaximumOverallStorageAmount();
        Print_Total_Storage_Amount();

        std::cout << "\nUser " << Standard_User->getUsername() << " is using:\n";
        Standard_User->getCloudStorageAmount();

        std::cout << "\nUser " << Dummy_User->getUsername() << " is using:\n";
        Dummy_User->getCloudStorageAmount();
    }
    static void Modify_User_Info(User* Standard_User, User* Dummy_User, char& User_Input){
        std::cout << "Modify user: (1) " << Standard_User->getUsername() << "; (2) " << Dummy_User->getUsername() << ".\n";

        Read_User_Input(User_Input, 6);

        if(User_Input == '1'){
            std::cout << "\nUser " << Standard_User->getUsername() << " selected!\n";

            Read_User_Input(User_Input, 7);

            if(User_Input == '1'){
                std::string username;
                std::cout << "\nEnter a new username: ";
                std::cin >> username;
                std::cout << "\nUser's " << Standard_User->getUsername() << " username has been change to ";
                Standard_User->setUsername(username);
                std::cout << Standard_User->getUsername() << std::endl;
            }
            if(User_Input == '2'){
                std::string password;
                std::cout << "\nEnter a new password: ";
                std::cin >> password;
                std::cout << "\nUser's " << Standard_User->getUsername() << " password has been change!\n";
                Standard_User->setPassword(password);
            }
            if(User_Input == '3'){
                std::cout << "\nUser " << Standard_User->getUsername() << " is using:\n";
                Standard_User->getCloudStorageAmount();

                Read_User_Input(User_Input, 8);
                if(User_Input == '1'){
                    int New_Value = 0;
                    int Old_Value = Standard_User->getCloudStorageAmountAsInt();
                    while(true){
/*                        std::cout << "\nTotal storage available: " << Server_Service::Total_Storage_Amount << std::endl;
                        std::cout << "\nPrevious value: "; Standard_User->getCloudStorageAmount();
                        std::cout << "\nNew value: ";
                        std::cin >> New_Value;

                        if(New_Value > Server_Service::Total_Storage_Amount){
                            std::cout << "\nNew value cannot be greater than the current total storage available!\n";
                        }
                        if(New_Value >= Old_Value){
                            Standard_User->AddCloudStorageAmount(New_Value);
                            std::cout << "\n" << New_Value << "TB has been added to Cloud storage for user " << Standard_User->getUsername();
                        }
                        if(New_Value < Old_Value){
                            int temp =
                        }*/

                        break;
                    }

                }
            }

        }
        if(User_Input == '2'){
            std::cout << "\nUser " << Dummy_User->getUsername() << " selected!\n";

            std::cout << "\nUser " << Dummy_User->getUsername() << " is using:\n";
            Dummy_User->getCloudStorageAmount();



        }

    }
};

int Server_Service::Total_Storage_Amount = 0;

//User class scope:

void User::getCloudStorageAmount() const { //there was a pointer here.
    if(Cloud_Storage_Amount == nullptr){
        std::cout << "\n0 storage used.\n";
    }
    else{
        std::cout << std::endl << *Cloud_Storage_Amount << std::endl;
    }
}

void User::AddCloudStorageAmount(int cloudStorageAmount) {
    int* New_Cloud_Storage = new int;
    if(User::Cloud_Storage_Amount == nullptr){
        *New_Cloud_Storage = cloudStorageAmount;
        User::Cloud_Storage_Amount = New_Cloud_Storage;
        Server_Service::Use_Total_Storage_Amount(cloudStorageAmount);
    }
    else{
/*        int* Temp_Cloud_Storage_Amount = new int;
        *Temp_Cloud_Storage_Amount = cloudStorageAmount;
        *User::Cloud_Storage_Amount = *User::Cloud_Storage_Amount + *Temp_Cloud_Storage_Amount;
        free(Temp_Cloud_Storage_Amount);*/

        *New_Cloud_Storage = cloudStorageAmount;
        *User::Cloud_Storage_Amount = *User::Cloud_Storage_Amount + *New_Cloud_Storage;
        Server_Service::Use_Total_Storage_Amount(cloudStorageAmount);
    }
}

void User::FreeCloudStorageAmount(int cloudStorageAmount) {
    static int* Temporary_Subtraction = new int;
    *Temporary_Subtraction = cloudStorageAmount;
    *User::Cloud_Storage_Amount = *User::Cloud_Storage_Amount - *Temporary_Subtraction;
    Server_Service::Free_Total_Storage_Amount(*Temporary_Subtraction);
    free(Temporary_Subtraction);
}
