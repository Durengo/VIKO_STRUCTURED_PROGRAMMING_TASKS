#pragma once

//This module will include all the function to manipulate the user object account information, user storage information, and printing server statistics.

#include "User_List.h"
#include "Data_Manager.h"

class Service_Manager {
public:
  static void Print_Service_Statistics(
          User_List *list); //Function for printing all service total and components usage of every user.

  static void Add_Cloud_Storage_Amount(User_List *list, int UniqueID,
                                       int Add_Amount); //Function to add cloud storage amount to a user object.
  static void Remove_Cloud_Storage_Amount(User_List *list, int UniqueID,
                                          int Remove_Amount); //Function to refund cloud storage amount to a user object.

  static void
  Add_Cloud_Database_Amount(User_List *list, int UniqueID, int Add_Amount); //Same as above only for cloud database.
  static void Remove_Cloud_Database_Amount(User_List *list, int UniqueID, int Remove_Amount);

  static void Add_Cloud_Bandwidth_Amount(User_List *list, int UniqueID,
                                         int Add_Amount); //Same as above only for bandwidth database.
  static void Remove_Cloud_Bandwidth_Amount(User_List *list, int UniqueID, int Remove_Amount);

  static void Admin_Modify_Services_Value(User_List *list); //Function CUI for Admin to modify services value.
  static void User_Modify_Services_Value(User_List *list); //Same as above only for user.

  static void Modify_User_Storage_Services_Value(User_List *list,
                                                 int User_ID); //Function CUI asking what the user wants to do with the specified storage: exit, add or remove.
  static void Modify_User_Database_Services_Value(User_List *list, int User_ID);

  static void Modify_User_Bandwidth_Services_Value(User_List *list, int User_ID);

  static void
  Admin_Modify_User_Account_Info(User_List *list); //Function CUI for the admin to modify user account information.
  static void
  User_Modify_User_Account_Info(User_List *list); //Same as the above but only for the current user that is logged in.

  static void Modify_Username(User_List *list, int Current_UserID); //Function that modifies the user's username.
  static void Modify_Password(User_List *list, int Current_UserID); //Function that modifies the user's password.
  static void Delete_Account(User_List *list, int Current_UserID); //Function that deletes a user object.

};