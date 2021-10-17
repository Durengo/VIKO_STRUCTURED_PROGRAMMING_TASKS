#pragma once

/*The "User_List" module is a linked listed for the User class objects that will be stored dynamically.
 * 1st goal of this module is to dynamically allocate and deallocate User class objects into heap.
 * 2nd goal of this module is to freely manipulate User class objects - create, delete, modify User class objects.
 * 3rd goal of this module is to send all actions to the Data_Manager module to keep track of the amount of users and their information.
 * 4th goal of this module is to log all actions into the Logging module.
*/

//#include "User_Node.h"
#include "User.h" //To instantiate user class objects into User_List linked list.
#include "Console.h" //To print to console.
#include "Data_Manager.h" //To keep track of created users

class User;

class User_List { //Class for User_List. This is a linked list which moves in only one direction, hence it has an initial point and a terminal point. Here we declare the head (initial) point of our list and the tail (terminal) point of our list.
public:
  User *head = nullptr; //Initialize head pointer to nullptr
  User *tail = nullptr; //Initialize tail pointer to nullptr


  User_List(); //Constructor for our linked lists.

  static void Display_List(User_List *list); //Function for displaying all elements in a linked list.
  //void Create_User(User_List* list);
  static void Create_User(User_List *list, const std::string &username,
                          const std::string &password); //Function for creating new users (nodes/elements in the linked list) and allocating them to heap.
  static bool Search_For_Username_Duplicate(User_List *list,
                                            const std::string &username); //Function used when creating new users to check for duplicate usernames.
  int length() const; //Function to count the length of the linked list.

  static void deleteHead(
          User_List *list); //Function to delete ONLY the initial element of a linked list (leaving other elements still linked).

  static void deleteTail(
          User_List *list); //Function to delete ONLY the terminal element of a linked list (leaving other elements still linked).

  static void deleteByPos(User_List *list,
                          int position); //Function to delete an element from a linked list by a given position. Runs through multiple cases to either run the deleteHead() function or the deleteTail() function; else call the deletePos() function.

  static void deletePos(User_List *list,
                        int position); //Function to delete any element from a linked list, but not the initial or terminal element.

  static bool UserLogin(User_List *list); //Function to prompt user to log into an already existing user class object.

  static bool Search_For_User_Login(User_List *list, std::string &username,
                                    std::string &password); //Function which is called by UserLogin() function to check if the entered username AND password matches any user class objects in a user list.

  static void
  Delete_Current_User_By_ID(User_List *list,
                            int Current_UserID); //Function to delete a currently logged-in user (Current_User_ID).

  static User *Get_User_By_ID(User_List *list,
                              int UniqueID); //Function to get a user object from a linked list by searching for their ID.
};