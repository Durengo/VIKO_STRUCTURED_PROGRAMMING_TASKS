#include "Service_Manager.h"

void Service_Manager::Print_Service_Statistics(User_List *list)
{
  Data_Manager::getMaximumOverallStorageAmount(); //Functions to print general information about services' usage.
  Data_Manager::Print_Total_Storage_Amount();
  C::PTC("\n");
  if (Data_Manager::getTotal_Users() ==
      1) { //If there is only in total 1 user (only admin), then there is nothing to show.
    C::PTC("\nThere are no users to show information about; Exiting this menu.\n");
    return;
  }
  User *current = list->head->next; //Do not count admin user.
  while (current != nullptr) {
    C::PTC("User ", current->getUsername(), ":\n"); //Printing individual user service usage information.

    current->printCloudStorageAmountUsedByUser();
    current->printCloudDatabaseAmountUsedByUser();
    current->printCloudBandwidthAmountUsedByUser();

    C::PTC("\n");
    current = current->next;
  }
}

void Service_Manager::Add_Cloud_Storage_Amount(User_List *list, int UniqueID,
                                               int Add_Amount) //Function for adding a specified amount of cloud storage to a user object.
{
  if (Add_Amount == 0) { //If the specified amount is 0 then just return.
    C::PTC("\nNot adding anything.\n");
    return;
  }
  if (Add_Amount < 0) {
    C::PTC("\nCannot add a negative value.\n");
    return;
  }
  if (Add_Amount >
      Data_Manager::getTotal_Storage_Amount()) { //If the specified amount is more than the currently available total storage amount, return.
    C::PTC("\nCannot add more cloud storage than the maximum amount!\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list,
                                            UniqueID); //We call a function to get the specified element (user) from the user list and modify that user's information.
  if (current->getCloudStorageAmountPTR() ==
      nullptr) { //If the user objects cloud storage is a nullptr we assign that pointer to heap.
    current->assignCloudStorageAmountNewAddress(); //Function call to allocate the pointer to heap.
  }
  current->addCloudStorageAmount(Add_Amount); //Function call to modify cloud storage amount.
  Data_Manager::Use_Total_Storage_Amount(Add_Amount); //Function call to modify the total available storage amount.

  C::PTC("\nAdded ", Add_Amount, "TB of cloud storage to user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudStorageAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");

}

void Service_Manager::Remove_Cloud_Storage_Amount(User_List *list, int UniqueID,
                                                  int Remove_Amount) //Function for removing a specified amount of cloud storage from a user object.
{
  if (Remove_Amount == 0) { //If specified amount is 0, return.
    C::PTC("\nNot removing anything.\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list,
                                            UniqueID); //We call a function to get the specified element (user) from the user list and modify that user's information.
  if (current->getCloudStorageAmountPTR() ==
      nullptr) { //If the user objects cloud storage is a nullptr (0) we cannot remove storage.
    C::PTC("\nStorage has not been allocated yet.\n");
    return;
  } else if (Remove_Amount >
             current->getCloudStorageAmountAsInt()) { //If the specified amount is more than the currently available total storage amount, return.
    C::PTC("\nCannot remove more cloud storage than the total amount of storage!\n");
    return;
  }
  current->removeCloudStorageAmount(Remove_Amount); //Call to function to remove specified amount from cloud storage.
  if (current->getCloudStorageAmountAsInt() ==
      0) { //If the specified amount sets the cloud storage amount of that user's object to 0, we will free that pointer because there is no point to hold a 0 in memory.
    current->removeCloudStorageAmountAddress(current->getCloudStorageAmountPTR()); //Call to function to free memory.
  }
  Data_Manager::Free_Total_Storage_Amount(
          Remove_Amount); //Call to function to restore the specified amount to the total available amount.

  C::PTC("\nRemoved ", Remove_Amount, "TB of cloud storage from user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudStorageAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");
}

void Service_Manager::Add_Cloud_Database_Amount(User_List *list, int UniqueID, int Add_Amount)
{
  if (Add_Amount == 0) {
    C::PTC("\nNot adding anything.\n");
    return;
  }
  if (Add_Amount < 0) {
    C::PTC("\nCannot add a negative value.\n");
    return;
  }
  if (Add_Amount > Data_Manager::getTotal_Storage_Amount()) {
    C::PTC("\nCannot add more cloud database than the maximum amount!\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list, UniqueID);
  if (current->getCloudDatabaseAmountPTR() == nullptr) {
    current->assignCloudDatabaseAmountNewAddress();
  }
  current->addCloudDatabaseAmount(Add_Amount);
  Data_Manager::Use_Total_Storage_Amount(Add_Amount);

  C::PTC("\nAdded ", Add_Amount, "TB of database to user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudDatabaseAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");

}

void Service_Manager::Remove_Cloud_Database_Amount(User_List *list, int UniqueID, int Remove_Amount)
{
  if (Remove_Amount == 0) {
    C::PTC("\nNot removing anything.\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list, UniqueID);
  if (current->getCloudDatabaseAmountPTR() == nullptr) {
    C::PTC("\nDatabase has not been allocated yet.\n");
    return;
  } else if (Remove_Amount > current->getCloudDatabaseAmountAsInt()) {
    C::PTC("\nCannot remove more cloud database than the total amount of storage!\n");
    return;
  }
  current->removeCloudDatabaseAmount(Remove_Amount);
  if (current->getCloudDatabaseAmountAsInt() == 0) {
    current->removeCloudDatabaseAmountAddress(current->getCloudDatabaseAmountPTR());
  }
  Data_Manager::Free_Total_Storage_Amount(Remove_Amount);

  C::PTC("\nRemoved ", Remove_Amount, "TB of database from user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudDatabaseAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");
}

void Service_Manager::Add_Cloud_Bandwidth_Amount(User_List *list, int UniqueID, int Add_Amount)
{
  if (Add_Amount == 0) {
    C::PTC("\nNot adding anything.\n");
    return;
  }
  if (Add_Amount < 0) {
    C::PTC("\nCannot add a negative value.\n");
    return;
  }
  if (Add_Amount > Data_Manager::getTotal_Storage_Amount()) {
    C::PTC("\nCannot add more cloud bandwidth than the maximum amount!\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list, UniqueID);
  if (current->getCloudBandwidthAmountPTR() == nullptr) {
    current->assignCloudBandwidthAmountNewAddress();
  }
  current->addCloudBandwidthAmount(Add_Amount);
  Data_Manager::Use_Total_Storage_Amount(Add_Amount);

  C::PTC("\nAdded ", Add_Amount, "TB of bandwidth to user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudBandwidthAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");
}

void Service_Manager::Remove_Cloud_Bandwidth_Amount(User_List *list, int UniqueID, int Remove_Amount)
{
  if (Remove_Amount == 0) {
    C::PTC("\nNot removing anything.\n");
    return;
  }
  User *current = User_List::Get_User_By_ID(list, UniqueID);
  if (current->getCloudBandwidthAmountPTR() == nullptr) {
    C::PTC("\nBandwidth has not been allocated yet.\n");
    return;
  } else if (Remove_Amount > current->getCloudBandwidthAmountAsInt()) {
    C::PTC("\nCannot remove more cloud Bandwidth than the total amount of storage!\n");
    return;
  }
  current->removeCloudBandwidthAmount(Remove_Amount);
  if (current->getCloudBandwidthAmountAsInt() == 0) {
    current->removeCloudBandwidthAmountAddress(current->getCloudBandwidthAmountPTR());
  }
  Data_Manager::Free_Total_Storage_Amount(Remove_Amount);

  C::PTC("\nRemoved ", Remove_Amount, "TB of bandwidth from user ", current->getUsername(), "\n");
  C::PTC("\nCurrent Amount: ", current->getCloudBandwidthAmountAsInt(), "TB\n");
  C::PTC("\nOperation completed!\n");
}