#pragma once

#include <iostream>
#include "Server_Service.h"

/*This "User" header file includes the User class which will be used alongside Server_Service class (from "Server_Service" header file).
 * 1st goal of this class is to create an Admin object which will have more functionality than a standard user in the Server_Service class.
 * 2nd goal of this class is to enable the Admin or the User to successfully log into their account by checking the entered Username and Password.
 * 3rd goal of this class is to store information from the Server_Service class main object such as: (for standard user) the total amount of storage used with the provided service(-s);
 * (for admin) see and access all the information about the standard user and also see all their taken actions (i.e. every action of the standard user is logged).*/

//static int Total_Users = 0; //Keep track of the total amount of users.
//static int Current_User_ID = 0;
//static std::string Current_User_Username = "NULL";

class User_List;

class User {
private:
    std::string Username; //Create a string for user username.
    std::string Password; //Create a string for user password.
    int Unique_ID;

    int* Cloud_Storage_Amount;
    int* Cloud_Database_Amount;
    int* Cloud_Bandwidth_Amount;

public:
    User* next = nullptr;

    static int Total_Users; //Keep track of the total amount of users.
    static int Current_User_ID;
    static std::string Current_User_Username;


    int getUniqueId() const;

    User();

    ~User();

    static int getTotalUsers();

    void Free_Deleted_User_Services();

    static int getCurrent_User_ID();
    static void setCurrent_User_ID(int Change_ID);
    int getTotalServicesUsed();

    void addCloudStorageAmount(int amount);
    void removeCloudStorageAmount(int amount);
    void assignCloudStorageAmountNewAddress();
    void removeCloudStorageAmountAddress(int* Address);
    int* getCloudStorageAmountPTR();
    int getCloudStorageAmountAsInt() const;
    void printCloudStorageAmountUsedByUser() const;

    void addCloudDatabaseAmount(int amount);
    void removeCloudDatabaseAmount(int amount);
    void assignCloudDatabaseAmountNewAddress();
    void removeCloudDatabaseAmountAddress(int* Address);
    int* getCloudDatabaseAmountPTR();
    int getCloudDatabaseAmountAsInt() const;
    void printCloudDatabaseAmountUsedByUser() const;

    void addCloudBandwidthAmount(int amount);
    void removeCloudBandwidthAmount(int amount);
    void assignCloudBandwidthAmountNewAddress();
    void removeCloudBandwidthAmountAddress(int* Address);
    int* getCloudBandwidthAmountPTR();
    int getCloudBandwidthAmountAsInt() const;
    void printCloudBandwidthAmountUsedByUser() const;

    void setUsername(const std::string &username);
    const std::string &getUsername() const;
    void setPassword(const std::string &username);
    const std::string &getPassword() const;
};

int User::Total_Users = 0;
int User::Current_User_ID = 0;
std::string User::Current_User_Username = "Null";