#include "User.h"

User::User() //When the User constructor is called variables are initialized with basic information; each time the constructor is called increment the total amount of users.
        : Username("\"NULL\""), Password("NULL"), Cloud_Storage_Amount(nullptr), Cloud_Database_Amount(nullptr),
          Cloud_Bandwidth_Amount(
                  nullptr)
{
  Data_Manager::addToTotal_Users();
  Unique_ID = Data_Manager::getTotal_Users();
  Console::PTC("\n!Constructor! Total: ", Data_Manager::getTotal_Users(), "\n"); //For debugging.
}

User::~User()
{ //Each time the destructor is called reduce the total amount of users by 1.
  Data_Manager::subtractFromTotal_Users();
  Free_Deleted_User_Services();
  Console::PTC("\n!Destructor! Total: ", Data_Manager::getTotal_Users(), "\n"); //For debugging.
}

void User::setUsername(const std::string &username)
{ //Setter for Username.
  Username = username;
}

const std::string &User::getUsername() const
{ //Getter for Username.
  return Username;
}

void User::setPassword(const std::string &username)
{ //Setter for Password.
  Password = username;
}

const std::string &User::getPassword() const
{ //Getter for Password.
  return Password;
}

int User::getUniqueId() const
{
  return Unique_ID;
}

int User::getTotalServicesUsed() //Return the total value of all service components used.
{
  int Total = 0;
//  int Cloud_Storage = 0;
//  int Cloud_Database = 0;
//  int Cloud_Bandwidth = 0;
  if (Cloud_Storage_Amount ==
      nullptr) { //If user's cloud storage amount is a nullptr that means it's not allocated, and it is 0.
    Total = Total + 0;
  } else {
    Total = Total + *Cloud_Storage_Amount;
  }
  if (Cloud_Database_Amount == nullptr) {
    Total = Total + 0;
  } else {
    Total = Total + *Cloud_Database_Amount;
  }
  if (Cloud_Bandwidth_Amount == nullptr) {
    Total = Total + 0;
  } else {
    Total = Total + *Cloud_Bandwidth_Amount;
  }
  return Total;
}

void
User::Free_Deleted_User_Services() //Called by the destructor of the User class. Count a total amount which must be returned to the total storage amount.
{
  int Total = 0;
  if (Cloud_Storage_Amount != nullptr) { //If memory has been allocated add this amount to total.
    Total = Total + *Cloud_Storage_Amount;
  }
  if (Cloud_Database_Amount != nullptr) {
    Total = Total + *Cloud_Database_Amount;
  }
  if (Cloud_Bandwidth_Amount != nullptr) {
    Total = Total + *Cloud_Bandwidth_Amount;
  }
  Data_Manager::Free_Total_Storage_Amount(
          Total); //Call to function to give back the total amount to the total storage amount.
  delete Cloud_Storage_Amount;
  delete Cloud_Database_Amount;
  delete Cloud_Bandwidth_Amount;
}

void User::addCloudStorageAmount(int amount) //Simple function for adding the total amount of cloud storage.
{
  *Cloud_Storage_Amount = *Cloud_Storage_Amount + amount;
}

void User::removeCloudStorageAmount(int amount)
{
  if (amount > *Cloud_Storage_Amount) {
    std::cout << "\nCannot remove more than the used amount!\n"; //Just in case ;)
    return;
  } else {
    *Cloud_Storage_Amount = *Cloud_Storage_Amount - amount;
  }
}

void
User::assignCloudStorageAmountNewAddress() //This function gets called when the user object's specified storage is not assigned to an address. This function gets called only when adding specified storage.
{
  Cloud_Storage_Amount = (int *) malloc(sizeof(int)); //Assign 4 Bytes to heap.
  *Cloud_Storage_Amount = 0; //Dereference the memory address and set data to an int value of 0. After this is completed, addition is done in other functions.
}

void User::removeCloudStorageAmountAddress(
        int *Address) //This function gets called when the user object's specified storage is assigned to an address AND the dereferenced address holds a value of 0. This function gets called when the user's object deconstructor is called AND when we subtract from the specified storage amount.
{
  free(Address); //Free malloc address.
  Cloud_Storage_Amount = nullptr; //Set the new pointer of the specified storage to nullptr.
}

int *User::getCloudStorageAmountPTR() //Get the specified storage's POINTER.
{
  return Cloud_Storage_Amount;
}

int User::getCloudStorageAmountAsInt() const //Get the specified storage's AMOUNT.
{
  if (Cloud_Storage_Amount == nullptr) { //If address is not allocated then return 0;
    return 0;
  } else {
    return *Cloud_Storage_Amount;
  }
}

void
User::printCloudStorageAmountUsedByUser() const //Function to print how much of the specified storage the user object is using.
{
  if (Cloud_Storage_Amount == nullptr || *Cloud_Storage_Amount ==
                                         0) { //If the specified storage has not been allocated to memory then print 0. The second condition shouldn't be ever check, but I put it there just in case.
    std::cout << "\nCloud storage amount used: 0TB.\n";
  } else {
    std::cout << "\nCloud storage amount used: " << getCloudStorageAmountAsInt() << "TB.\n";
  }
}

void User::addCloudDatabaseAmount(int amount)
{
  *Cloud_Database_Amount = *Cloud_Database_Amount + amount;
}

void User::removeCloudDatabaseAmount(int amount)
{
  if (amount > *Cloud_Database_Amount) {
    std::cout << "\nCannot remove more than the used amount!\n";
    return;
  } else {
    *Cloud_Database_Amount = *Cloud_Database_Amount - amount;
  }
}

void User::assignCloudDatabaseAmountNewAddress()
{
  Cloud_Database_Amount = (int *) malloc(sizeof(int));
  *Cloud_Database_Amount = 0;
}

void User::removeCloudDatabaseAmountAddress(int *Address)
{
  free(Address);
  Cloud_Database_Amount = nullptr;
}

int *User::getCloudDatabaseAmountPTR()
{
  return Cloud_Database_Amount;
}

int User::getCloudDatabaseAmountAsInt() const
{
  if (Cloud_Database_Amount == nullptr) {
    return 0;
  } else {
    return *Cloud_Database_Amount;
  }
}

void User::printCloudDatabaseAmountUsedByUser() const
{
  if (Cloud_Database_Amount == nullptr || *Cloud_Database_Amount == 0) {
    std::cout << "\nCloud database amount used: 0TB.\n";
  } else {
    std::cout << "\nCloud database amount used: " << getCloudDatabaseAmountAsInt() << "TB.\n";
  }
}

void User::addCloudBandwidthAmount(int amount)
{
  *Cloud_Bandwidth_Amount = *Cloud_Bandwidth_Amount + amount;
}

void User::removeCloudBandwidthAmount(int amount)
{
  if (amount > *Cloud_Bandwidth_Amount) {
    std::cout << "\nCannot remove more than the used amount!\n";
    return;
  } else {
    *Cloud_Bandwidth_Amount = *Cloud_Bandwidth_Amount - amount;
  }
}

void User::assignCloudBandwidthAmountNewAddress()
{
  Cloud_Bandwidth_Amount = (int *) malloc(sizeof(int));
  *Cloud_Bandwidth_Amount = 0;
}

void User::removeCloudBandwidthAmountAddress(int *Address)
{
  free(Address);
  Cloud_Bandwidth_Amount = nullptr;
}

int *User::getCloudBandwidthAmountPTR()
{
  return Cloud_Bandwidth_Amount;
}

int User::getCloudBandwidthAmountAsInt() const
{
  if (Cloud_Bandwidth_Amount == nullptr) {
    return 0;
  } else {
    return *Cloud_Bandwidth_Amount;
  }
}

void User::printCloudBandwidthAmountUsedByUser() const
{
  if (Cloud_Bandwidth_Amount == nullptr || *Cloud_Bandwidth_Amount == 0) {
    std::cout << "\nCloud bandwidth amount used: 0TB.\n";
  } else {
    std::cout << "\nCloud Bandwidth amount used: " << getCloudBandwidthAmountAsInt() << "TB.\n";
  }
}