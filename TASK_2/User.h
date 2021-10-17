#pragma once
// *This "User" module includes the User class which will be used to create user class objects and modify their information.
// * 1st goal of this class is to create an Admin object which will have more functionality than a default user.
// * 2nd goal of this class is to enable the Admin or the User to successfully log into their account by checking the entered Username and Password.

#include <iostream>
#include "Console.h"
#include "Data_Manager.h"

//static int Total_Users = 0; //Keep track of the total amount of users.
//static int Current_User_ID = 0;
//static std::string Current_User_Username = "NULL";

class User_List;

class User {
private:
  std::string Username; //Create a string for user username.
  std::string Password; //Create a string for user password.
  int Unique_ID; //Each created User object has a unique ID.

  int *Cloud_Storage_Amount; //Each user object tracks the amount of cloud storage they are using.
  int *Cloud_Database_Amount; //Each user object tracks the amount of cloud database they are using.
  int *Cloud_Bandwidth_Amount; //Each user object tracks the amount of cloud bandwidth they are using.

public:
  User *next = nullptr; //Used with User_List to point to the next element in a linked list.

  //static int Total_Users; //Keep track of the total amount of users.
  //static int Current_User_ID;
  //static std::string Current_User_Username;
  User();

  ~User();

  void setUsername(const std::string &username); //Set a username for a User class object.
  const std::string &getUsername() const; //Get a username from a User class object.
  void setPassword(const std::string &username); //Set a password for a User class object.
  const std::string &getPassword() const; //Get a password from a User class object.

  int getUniqueId() const; //Function to get the Unique ID of the user object.

//  int *getCloud_Storage_AmountPTR();
//  int *getCloud_Database_AmountPTR();
//  int *getCloud_Bandwidth_AmountPTR();

  int getTotalServicesUsed(); //Function to return the total amount of all the services a user object is using.

  void
  Free_Deleted_User_Services(); //Function to return all the used service amount back to the Total_Storage_Amount when the user object gets deconstructed.

  void addCloudStorageAmount(
          int amount); //Function to add an amount of storage to the objects total used cloud storage amount.
  void removeCloudStorageAmount(
          int amount); //Function to remove an amount of storage from the objects total used cloud storage amount.
  void
  assignCloudStorageAmountNewAddress(); //Function to assign cloud storage amount address to heap when the user requests an amount for the first time or after the total amount is 0;
  void removeCloudStorageAmountAddress(int *Address); //Function to release memory once the cloud storage amount is 0.
  int *getCloudStorageAmountPTR(); //Function to get the objects cloud storage pointer.
  int getCloudStorageAmountAsInt() const; //Function to return how much the user object is using cloud storage.
  void printCloudStorageAmountUsedByUser() const; //Function to print how much the user object is using cloud storage.

  void addCloudDatabaseAmount(int amount); //Same as the above just for cloud database.
  void removeCloudDatabaseAmount(int amount);
  void assignCloudDatabaseAmountNewAddress();
  void removeCloudDatabaseAmountAddress(int *Address);
  int *getCloudDatabaseAmountPTR();
  int getCloudDatabaseAmountAsInt() const;
  void printCloudDatabaseAmountUsedByUser() const;

  void addCloudBandwidthAmount(int amount); //Same as the above just for cloud bandwidth.
  void removeCloudBandwidthAmount(int amount);
  void assignCloudBandwidthAmountNewAddress();
  void removeCloudBandwidthAmountAddress(int *Address);
  int *getCloudBandwidthAmountPTR();
  int getCloudBandwidthAmountAsInt() const;
  void printCloudBandwidthAmountUsedByUser() const;
};