#pragma once

#include "User.h"
#include "User_List.h"
#include "Read_User_Input.h" //TEMPORARY

/*This "User_List" header file contains a struct User_List, it is a linked listed for the "User.h" User class objects to be stored dynamically.
 * 1st goal of this struct is to manipulate "User.h" User class objects - create, delete, modify User class objects, also log the amount of total users (User::Total_Users)
 * 2nd goal of this struct is to dynamically allocate and deallocate User class objects into heap.
*/
class User;
class Server_Service;


class User_List{ //Struct for User_List. This is a linked list which moves in only one direction, hence it has an initial point and a terminal point. Here we declare the head (initial) point of our list and the tail (terminal) point of our list.
public:
    User* head = nullptr; //Initialize head pointer to nullptr
    User* tail = nullptr; //Initialize tail pointer to nullptr
    int length() const;
};

void Display_List(User_List* list);

void Create_User(User_List* list);

void Create_User(User_List* list, const std::string& username, const std::string& password);

bool Search_For_Username_Duplicate(User_List* list, const std::string& username);

void deleteTail(User_List* list);

void deleteByPos(User_List* list, int position);

void deletePos(User_List* list, int position);

bool Search_For_User_Login(User_List* list, std::string& username, std::string& password); //Function prototype for UserLogin.

bool UserLogin(User_List* list);

void Delete_Current_User_By_ID(User_List* list, int& Current_UserID);

User* Get_User_By_ID(User_List* list, int UniqueID);
void Modify_Username(User_List* list, char& User_Input, int Current_UserID);
void Modify_Password(User_List* list, char& User_Input, int Current_UserID);

void Delete_Account(User_List* list, char& User_Input, int Current_UserID);
void Admin_Modify_User_Account_Info(User_List* list, char& User_Input);

void User_Modify_User_Account_Info(User_List* list, char& User_Input);