#pragma once
//This "Data_Manager" module is meant to track and modify all information about the user object;

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "Console.h"
#include "User_List.h"

static int Total_Users = 0; //Static int to keep track of the total amount of users.
static int Current_User_ID = 0; //Static int to keep track of the current (logged in) user.
static std::string Current_User_Username = "NULL"; //Static string to keep track of the current (logged in) user.
static int Maximum_Overall_Storage_Amount; //Static int to save the total generated amount of storage for all the services.
static int Total_Storage_Amount; //Static in to keep track of the currently unused services' amount.

class User_List;

class Data_Manager {
private:
//  int *Cloud_Storage_Amount;
//  int *Cloud_Database_Amount;
//  int *Cloud_Bandwidth_Amount;
public:

  static int getTotal_Users(); //Function to get the total user amount.
  static void addToTotal_Users(); //Function to increment the total user amount by 1.
  static void subtractFromTotal_Users(); //Function to deduct 1 form the total user amount.

  static int getCurrent_User_ID(); //Function to get the current ID of the user that is logged in now.
  static void
  setCurrent_User_ID(int New_ID); //Function to set the current ID of the user (logging out, switching user(-s)).

  static std::string
  getCurrent_User_Username(); //Function to get the current username of the user that is logged in now.
  static void setCurrent_User_Username(
          const std::string &New_Username); //Function to set the current username (e.g. when logging out, set to NULL)

  Data_Manager(); //Set up a constructor to generate a random amount of storage for the services to use and allocate it to heap.

  static void
  Generate_Total_Storage_Amount(); //Function which is called by the constructor to generate a random int number, allocate it to heap and set it as the Total_Storage_Amount value.

  static void setMaximum_Overall_Storage_Amount(
          int maximumOverallStorageAmount); //Function to set the maximum overall storage amount. Used only once by Generate_Total_Storage_Amount() function; this function should not be used otherwise.
  static void
  getMaximumOverallStorageAmount(); //Function to print the currently free amount of services and the total amount of services.
  static int getMaximum_Overall_Storage_Amount(); //Function to return the static int Maximum_Overall_Storage_Amount.

  static int getTotal_Storage_Amount(); //Function to get the static int Total_Storage_Amount.
  static void setTotal_Storage_Amount(int totalStorageAmount); //Function to set the to static int Total_Storage_Amount.
  static void Print_Total_Storage_Amount(); //Function to print the current free storage amount (Total_Storage_Amount).

  static void setMaximumOverallStorageAmount(int maximumOverallStorageAmount); //Need to check what this function does.

  static void getMaximumOverallStorageAmountOfAllUsers(
          User_List *list); //Function to print the information of how much each user object is using: (1) total of all the services; (2) every individual component.
  static void getMaximumOverallStorageAmountOfUser(
          User_List *list); //Function that works the same as above, but instead of printing all users it prints all info of the current user (Current_User_ID).

  static void Use_Total_Storage_Amount(
          int Amount); //Function that is called when a user buys a certain amount of storage. We deduct that amount from the total free amount (Total_Storage_Amount).
  static void Free_Total_Storage_Amount(
          int Amount); //Function that is called whe a user wants to refund a certain amount of storage. We return that amount to the total free amount(Total_Storage_Amount).

};