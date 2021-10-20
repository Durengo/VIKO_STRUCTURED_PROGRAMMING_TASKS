#pragma once

//This module is the interface for the users.

#include "User_List.h"
#include "Service_Manager.h"

class Interface : public Console {
public:

  static void
  Login_Prompt(User_List *list); //Function that has cases for: Exiting the program, Logging in and creating a new user.
  static void Admin_CUI(User_List *list); //Function CUI for when the admin logs in.
  static void User_CUI(User_List *list); //Function CUI for when the user logs in.

  static int Service_Manager_For_Admin(); //Interface for manipulating services for the admin.
  static int Service_Manager_For_User(); //Same as the above, only for the user.

  static int Exit_Add_Remove(); //Function CUI for 3 options: exit, add and remove.

  static int
  Account_Information_Manager_For_Admin_And_User(); //Function CUI for both the admin and the user to editing account information such as: username, password or delete account.

};
