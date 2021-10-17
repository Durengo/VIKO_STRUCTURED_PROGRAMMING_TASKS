#include "User.h"

    int User::getUniqueId() const {
        return Unique_ID;
    }

    User::User() //Call the User constructor and initialize variables with basic information. Also add to the total amount of users each time an object constructor is called.
            : Username("\"Not set\""), Password("user"), Cloud_Storage_Amount(nullptr), Cloud_Database_Amount(nullptr), Cloud_Bandwidth_Amount(nullptr)
    {
        Total_Users++;
        Unique_ID = Total_Users;
        std::cout << "\n!Constructor! Total: " << Total_Users << "\n";
    }
    User::~User(){
        Total_Users--;
        Free_Deleted_User_Services();
        std::cout << "\nUser deconstructed; Total: " << Total_Users << "\n";
    }

    int User::getCurrent_User_ID(){
        return Current_User_ID;
    }
    void User::setCurrent_User_ID(int Change_ID){
        Current_User_ID = Change_ID;
    }

    int User::getTotalUsers(){ //For debugging.
        return Total_Users;
    }

    void User::Free_Deleted_User_Services(){
        int Total = 0;
        if(Cloud_Storage_Amount != nullptr){
            Total = Total + *Cloud_Storage_Amount;
        }
        if(Cloud_Database_Amount != nullptr){
            Total = Total + *Cloud_Database_Amount;
        }
        if(Cloud_Bandwidth_Amount != nullptr){
            Total = Total + *Cloud_Bandwidth_Amount;
        }
        Server_Service::Free_Total_Storage_Amount(Total);
        delete Cloud_Storage_Amount;
        delete Cloud_Database_Amount;
        delete Cloud_Bandwidth_Amount;
    }

    int User::getTotalServicesUsed(){
        int Total = 0;
/*        int Cloud_Storage = 0;
        int Cloud_Database = 0;
        int Cloud_Bandwidth = 0;*/
        if(Cloud_Storage_Amount == nullptr){
            Total = Total + 0;
        }
        else{
            Total = Total + *Cloud_Storage_Amount;
        }
        if(Cloud_Database_Amount == nullptr){
            Total = Total + 0;
        }
        else{
            Total = Total + *Cloud_Database_Amount;
        }
        if(Cloud_Bandwidth_Amount == nullptr){
            Total = Total + 0;
        }
        else{
            Total = Total + *Cloud_Bandwidth_Amount;
        }
        return Total;
    }

    void User::addCloudStorageAmount(int amount){
        *Cloud_Storage_Amount = *Cloud_Storage_Amount + amount;
    }
    void User::removeCloudStorageAmount(int amount){
        if(amount > *Cloud_Storage_Amount){
            std::cout << "\nCannot remove more than the used amount!\n";
            return;
        }
        else{
            *Cloud_Storage_Amount = *Cloud_Storage_Amount - amount;
        }
    }
    void User::assignCloudStorageAmountNewAddress(){
        Cloud_Storage_Amount = (int*)malloc(sizeof(int));
        *Cloud_Storage_Amount = 0;
    }
    void User::removeCloudStorageAmountAddress(int* Address){
        free(Address);
        Cloud_Storage_Amount = nullptr;
    }
    int* User::getCloudStorageAmountPTR(){
        return Cloud_Storage_Amount;
    }
    int User::getCloudStorageAmountAsInt() const {
        if(Cloud_Storage_Amount == nullptr){
            return 0;
        }
        else{
            return *Cloud_Storage_Amount;
        }
    }
    void User::printCloudStorageAmountUsedByUser() const{
        if(Cloud_Storage_Amount == nullptr || *Cloud_Storage_Amount == 0){
            std::cout << "\nCloud storage amount used: 0TB.\n";
        }
        else{
            std::cout << "\nCloud storage amount used: " << getCloudStorageAmountAsInt() << "TB.\n";
        }
    }
    void User::addCloudDatabaseAmount(int amount){
        *Cloud_Database_Amount = *Cloud_Database_Amount + amount;
    }
    void User::removeCloudDatabaseAmount(int amount){
        if(amount > *Cloud_Database_Amount){
            std::cout << "\nCannot remove more than the used amount!\n";
            return;
        }
        else{
            *Cloud_Database_Amount = *Cloud_Database_Amount - amount;
        }
    }
    void User::assignCloudDatabaseAmountNewAddress(){
        Cloud_Database_Amount = (int*)malloc(sizeof(int));
        *Cloud_Database_Amount = 0;
    }
    void User::removeCloudDatabaseAmountAddress(int* Address){
        free(Address);
        Cloud_Database_Amount = nullptr;
    }
    int* User::getCloudDatabaseAmountPTR(){
        return Cloud_Database_Amount;
    }
    int User::getCloudDatabaseAmountAsInt() const {
        if(Cloud_Database_Amount == nullptr){
            return 0;
        }
        else{
            return *Cloud_Database_Amount;
        }
    }
    void User::printCloudDatabaseAmountUsedByUser() const{
        if(Cloud_Database_Amount == nullptr || *Cloud_Database_Amount == 0){
            std::cout << "\nCloud database amount used: 0TB.\n";
        }
        else{
            std::cout << "\nCloud database amount used: " << getCloudDatabaseAmountAsInt() << "TB.\n";
        }
    }

    void User::addCloudBandwidthAmount(int amount){
        *Cloud_Bandwidth_Amount = *Cloud_Bandwidth_Amount + amount;
    }
    void User::removeCloudBandwidthAmount(int amount){
        if(amount > *Cloud_Bandwidth_Amount){
            std::cout << "\nCannot remove more than the used amount!\n";
            return;
        }
        else{
            *Cloud_Bandwidth_Amount = *Cloud_Bandwidth_Amount - amount;
        }
    }
    void User::assignCloudBandwidthAmountNewAddress(){
        Cloud_Bandwidth_Amount = (int*)malloc(sizeof(int));
        *Cloud_Bandwidth_Amount = 0;
    }
    void User::removeCloudBandwidthAmountAddress(int* Address){
        free(Address);
        Cloud_Bandwidth_Amount = nullptr;
    }
    int* User::getCloudBandwidthAmountPTR(){
        return Cloud_Bandwidth_Amount;
    }
    int User::getCloudBandwidthAmountAsInt() const {
        if(Cloud_Bandwidth_Amount == nullptr){
            return 0;
        }
        else{
            return *Cloud_Bandwidth_Amount;
        }
    }
    void User::printCloudBandwidthAmountUsedByUser() const{
        if(Cloud_Bandwidth_Amount == nullptr || *Cloud_Bandwidth_Amount == 0){
            std::cout << "\nCloud bandwidth amount used: 0TB.\n";
        }
        else{
            std::cout << "\nCloud Bandwidth amount used: " << getCloudBandwidthAmountAsInt() << "TB.\n";
        }
    }

    void User::setUsername(const std::string &username) { //Setter for Username.
        Username = username;
    }
    const std::string &User::getUsername() const { //Getter for Username.
        return Username;
    }
    void User::setPassword(const std::string &username) { //Setter for Password.
        Password = username;
    }
    const std::string &User::getPassword() const { //Getter for Password. !Not necessary for now, so it might be removed in the future!
        return Password;
    }

/*
int User::Total_Users = 0;
int User::Current_User_ID = 0;
std::string User::Current_User_Username = "Null";*/
