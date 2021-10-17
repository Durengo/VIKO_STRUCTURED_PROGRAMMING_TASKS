#pragma once

#include "User.h"
#include "User_List.h"

static int Maximum_Overall_Storage_Amount;

static int Total_Storage_Amount = 0; //The main int for our total storage amount. We make this integer static so that it exists throughout the whole program execution runtime.

class User;
class User_List;
//static User* Get_User_By_ID(User_List* list, int UniqueID);
class Server_Service {
private:


public:

    Server_Service();

    //All of these were static functions!
    static void getMaximumOverallStorageAmount();
    static void getMaximumOverallStorageAmountOfAllUsers(User_List* list);
    static void getMaximumOverallStorageAmountOfUser(User_List* list);
    static void setMaximumOverallStorageAmount(int maximumOverallStorageAmount);
    static void setTotalStorageAmount(int totalStorageAmount);
    static int getTotalStorageAmount();
    static void Print_Total_Storage_Amount();
    static void Generate_Total_Storage_Amount();
    static void Use_Total_Storage_Amount(int Amount);
    static void Free_Total_Storage_Amount(int Amount);
    static void Print_Service_Statistics(User_List* list);
    static void Add_Cloud_Storage_Amount(User_List* list, int UniqueID, int Add_Amount);
    static void Remove_Cloud_Storage_Amount(User_List* list, int UniqueID, int Remove_Amount);
    static void Add_Cloud_Database_Amount(User_List* list, int UniqueID, int Add_Amount);
    static void Remove_Cloud_Database_Amount(User_List* list, int UniqueID, int Remove_Amount);
    static void Add_Cloud_Bandwidth_Amount(User_List* list, int UniqueID, int Add_Amount);
    static void Remove_Cloud_Bandwidth_Amount(User_List* list, int UniqueID, int Remove_Amount);
};

void Modify_User_Storage_Services_Value(User_List* list, char& User_Input, int User_ID);

void Modify_User_Database_Services_Value(User_List* list, char& User_Input, int User_ID);
void Modify_User_Bandwidth_Services_Value(User_List* list, char& User_Input, int User_ID);
void Admin_Modify_Services_Value(User_List* list, char& User_Input);

void User_Modify_Services_Value(User_List* list, char& User_Input);
//IFNOTWORKIN IT WAS THIS: void Free_Deleted_User_Services();
//void User::Free_Deleted_User_Services();