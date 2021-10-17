#include "Data_Manager.h"

int Data_Manager::getTotal_Users()
{
  return Total_Users;
}

void Data_Manager::addToTotal_Users()
{
  Total_Users = Total_Users + 1;
}

void Data_Manager::subtractFromTotal_Users()
{
  Total_Users = Total_Users - 1;
}

int Data_Manager::getCurrent_User_ID()
{
  return Current_User_ID;
}

void Data_Manager::setCurrent_User_ID(int New_ID)
{
  Current_User_ID = New_ID;
}

std::string Data_Manager::getCurrent_User_Username()
{
  return Current_User_Username;
}

void Data_Manager::setCurrent_User_Username(const std::string &New_Username)
{
  Current_User_Username = New_Username;
}

Data_Manager::Data_Manager()
//Once an object is called we use this constructor to generate a random amount of total storage.
{
  Generate_Total_Storage_Amount(); //Calls the function which generates a random amount of total storage.
  getMaximumOverallStorageAmount(); //For debugging.
  Console::PTC("\nData Manager Constructed!\n");
}

void Data_Manager::Generate_Total_Storage_Amount()
{ //This is the main function which generates a random amount of total storage.
  static int *RND = new int; //Create a new pointer and allocate it to heap.
  *RND = ((rand() % 100000) + 100000); //Allocate a randomly generated amount into the allocated memory slot.
  setTotal_Storage_Amount(
          *RND); //Set static int Total_Storage_Amount to our RND pointer. Pass by reference, so we modify the allocated heap memory.
  setMaximum_Overall_Storage_Amount(*RND);
}

void Data_Manager::setMaximum_Overall_Storage_Amount(int maximumOverallStorageAmount)
{
  Maximum_Overall_Storage_Amount = maximumOverallStorageAmount;
}

void Data_Manager::getMaximumOverallStorageAmount()
{
  Console::PTC("\nUsing: ", Maximum_Overall_Storage_Amount - Total_Storage_Amount, "TB out of ",
               Maximum_Overall_Storage_Amount, "TB.\n");
}

int Data_Manager::getMaximum_Overall_Storage_Amount()
{
  return Maximum_Overall_Storage_Amount;
}

int Data_Manager::getTotal_Storage_Amount()
{
  return Total_Storage_Amount;
}

void Data_Manager::setTotal_Storage_Amount(int totalStorageAmount)
{
  Total_Storage_Amount = totalStorageAmount;
}

void Data_Manager::setMaximumOverallStorageAmount(int maximumOverallStorageAmount)
{
  Maximum_Overall_Storage_Amount = maximumOverallStorageAmount;
}

void Data_Manager::Print_Total_Storage_Amount()
{ //Function for printing the total storage amount.
  Console::PTC("\nThere is ", Total_Storage_Amount, "TB available.\n");
}

void Data_Manager::getMaximumOverallStorageAmountOfAllUsers(User_List *list)
{
  User *Current_User = list->head->next; //Do not count the admin.
  Console::PTC("\nService info:\n");
  getMaximumOverallStorageAmount();
  Console::PTC("\nTotal free amount: ", getTotal_Storage_Amount(), "TB\n");
  while (Current_User != nullptr) {
    Console::PTC("\nUser ", Current_User->getUsername(), " current service usage statistics:\n");
    Console::PTC("\nSum of all components used: ", Current_User->getTotalServicesUsed(), "TB\n");
    Console::PTC("\nIndividual component usage:");
    Current_User->printCloudStorageAmountUsedByUser();
    Current_User->printCloudDatabaseAmountUsedByUser();
    Current_User->printCloudBandwidthAmountUsedByUser();
    Current_User = Current_User->next;
  }
  std::cout << std::endl;
}

void Data_Manager::getMaximumOverallStorageAmountOfUser(User_List *list)
{
  User *Current_User = User_List::Get_User_By_ID(list, Data_Manager::getCurrent_User_ID());
  Console::PTC("\nService info:\n");
  getMaximumOverallStorageAmount();
  Console::PTC("\nTotal free amount: ", getTotal_Storage_Amount(), "TB\n");
  Console::PTC("\nUser ", Current_User->getUsername(), " current service usage statistics:\n");
  Console::PTC("\nSum of all components used: ", Current_User->getTotalServicesUsed(), "TB\n");
  Console::PTC("\nIndividual component usage:");
  Current_User->printCloudStorageAmountUsedByUser();
  Current_User->printCloudDatabaseAmountUsedByUser();
  Current_User->printCloudBandwidthAmountUsedByUser();
  std::cout << std::endl;
}

void Data_Manager::Use_Total_Storage_Amount(int Amount)
{
  if (Amount > Maximum_Overall_Storage_Amount) {
    std::cout << "\n!EXCEPTION! Bypassing logic!\n";
    return;
  }
  Total_Storage_Amount = Total_Storage_Amount - Amount;
}

void Data_Manager::Free_Total_Storage_Amount(int Amount)
{
  Total_Storage_Amount = Total_Storage_Amount + Amount;
}