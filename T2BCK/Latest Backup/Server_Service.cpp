#include "Server_Service.h"
#include "User_List.h"
#include "User.h"


    Server_Service::Server_Service() //Once an object is called we use this constructor to generate a random amount of total storage.
    {
        Generate_Total_Storage_Amount(); //Calls the function which generates a random amount of total storage.
        Server_Service::getTotalStorageAmount(); //For debugging.
    }

    void Server_Service::getMaximumOverallStorageAmount() {
        std::cout << "\nUsing: " << Maximum_Overall_Storage_Amount - Total_Storage_Amount << "TB out of " << Maximum_Overall_Storage_Amount << "TB.\n";
    }
    void Server_Service::getMaximumOverallStorageAmountOfAllUsers(User_List* list){
        User* Current_User = list->head->next; //Do not count the admin.
        std::cout << "\nService info:\n";
        getMaximumOverallStorageAmount();
        std::cout << "\nTotal free amount: " << getTotalStorageAmount() << "TB\n";
        while (Current_User != nullptr){
            std::cout << "\nUser " << Current_User->getUsername() << " current service usage statistics:\n";
            std::cout << "\nSum of all components used: ";
            std::cout << Current_User->getTotalServicesUsed() << "TB\n";
            std::cout << "\nIndividual component usage:";
            Current_User->printCloudStorageAmountUsedByUser();
            Current_User->printCloudDatabaseAmountUsedByUser();
            Current_User->printCloudBandwidthAmountUsedByUser();
            Current_User = Current_User->next;
        }
        std::cout << std::endl;
    }
    void Server_Service::getMaximumOverallStorageAmountOfUser(User_List* list){
        User* Current_User = Get_User_By_ID(list, User::getCurrent_User_ID());
        std::cout << "\nService info:\n";
        getMaximumOverallStorageAmount();
        std::cout << "\nTotal free amount: " << getTotalStorageAmount() << "TB\n";
        std::cout << "\nUser " << Current_User->getUsername() << " current service usage statistics:\n";
        std::cout << "\nSum of all components used: ";
        std::cout << Current_User->getTotalServicesUsed() << "TB\n";
        std::cout << "\nIndividual component usage:";
        Current_User->printCloudStorageAmountUsedByUser();
        Current_User->printCloudDatabaseAmountUsedByUser();
        Current_User->printCloudBandwidthAmountUsedByUser();
        std::cout << std::endl;
    }
    void Server_Service::setMaximumOverallStorageAmount(int maximumOverallStorageAmount) {
        Maximum_Overall_Storage_Amount = maximumOverallStorageAmount;
    }
    void Server_Service::setTotalStorageAmount(int totalStorageAmount) { //Setter for Total_Storage_Amount. We pass by reference to not copy and modify the main static integer.
        Total_Storage_Amount = totalStorageAmount;
    }
    int Server_Service::getTotalStorageAmount() { //Getter for Total_Storage_Amount
        return Total_Storage_Amount;
    }
    void Server_Service::Print_Total_Storage_Amount(){ //Function for printing the total storage amount.
        std::cout << "\nThere is " << Total_Storage_Amount << "TB available.\n";
    }

    void Server_Service::Generate_Total_Storage_Amount(){ //This is the main function which generates a random amount of total storage.
        static int* RND = new int; //Create a new pointer and allocate it to heap.
        *RND = ((rand() % 100000) + 100000); //Allocate a randomly generated amount into the allocated memory slot.
        Server_Service::setTotalStorageAmount(*RND); //Set static int Total_Storage_Amount to our RND pointer. Pass by reference, so we modify the allocated heap memory.
        Server_Service::setMaximumOverallStorageAmount(*RND);
    }
    void Server_Service::Use_Total_Storage_Amount(int Amount){
        if(Amount > Maximum_Overall_Storage_Amount){
            std::cout << "\n!EXCEPTION! Bypassing logic!\n";
            return;
        }
        Total_Storage_Amount = Total_Storage_Amount - Amount;
    }
    void Server_Service::Free_Total_Storage_Amount(int Amount){
        Total_Storage_Amount = Total_Storage_Amount + Amount;
    }

    void Server_Service::Print_Service_Statistics(User_List* list){
        getMaximumOverallStorageAmount();
        Print_Total_Storage_Amount();
        std::cout << std::endl;
        if(User::Total_Users == 1){
            std::cout << "\nThere are no users to show information about; Exiting this menu.\n";
            return;
        }
        User* current = list->head->next; //Do not count admin user.
        while(current != nullptr){
            std::cout << "User " << current->getUsername() << ":\n";

            current->printCloudStorageAmountUsedByUser();
            current->printCloudDatabaseAmountUsedByUser();
            current->printCloudBandwidthAmountUsedByUser();

            std::cout << "\n";
            current = current->next;
        }
    }
    void Server_Service::Add_Cloud_Storage_Amount(User_List* list, int UniqueID, int Add_Amount){
        if(Add_Amount == 0){
            std::cout << "\nNot adding anything.\n";
            return;
        }
        if(Add_Amount > Total_Storage_Amount){
            std::cout << "\nCannot add more cloud storage than the maximum amount!\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudStorageAmountPTR() == nullptr){
            current->assignCloudStorageAmountNewAddress();
        }
        current->addCloudStorageAmount(Add_Amount);
        Server_Service::Use_Total_Storage_Amount(Add_Amount);

        std::cout << "\nAdded " << Add_Amount << "TB of cloud storage to user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudStorageAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";

    }
    void Server_Service::Remove_Cloud_Storage_Amount(User_List* list, int UniqueID, int Remove_Amount){
        if(Remove_Amount == 0){
            std::cout << "\nNot removing anything.\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudStorageAmountPTR() == nullptr){
            std::cout << "\nStorage has not been allocated yet.\n";
            return;
        }
        else if(Remove_Amount > current->getCloudStorageAmountAsInt()){
            std::cout << "\nCannot remove more cloud storage than the total amount of storage!\n";
            return;
        }
        current->removeCloudStorageAmount(Remove_Amount);
        if(current->getCloudStorageAmountAsInt() == 0){
            current->removeCloudStorageAmountAddress(current->getCloudStorageAmountPTR());
        }
        Server_Service::Free_Total_Storage_Amount(Remove_Amount);

        std::cout << "\nRemoved " << Remove_Amount << "TB of cloud storage from user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudStorageAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";
    }
    void Server_Service::Add_Cloud_Database_Amount(User_List* list, int UniqueID, int Add_Amount){
        if(Add_Amount == 0){
            std::cout << "\nNot adding anything.\n";
            return;
        }
        if(Add_Amount > Total_Storage_Amount){
            std::cout << "\nCannot add more cloud database than the maximum amount!\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudDatabaseAmountPTR() == nullptr){
            current->assignCloudDatabaseAmountNewAddress();
        }
        current->addCloudDatabaseAmount(Add_Amount);
        Server_Service::Use_Total_Storage_Amount(Add_Amount);

        std::cout << "\nAdded " << Add_Amount << "TB of database to user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudDatabaseAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";

    }
    void Server_Service::Remove_Cloud_Database_Amount(User_List* list, int UniqueID, int Remove_Amount){
        if(Remove_Amount == 0){
            std::cout << "\nNot removing anything.\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudDatabaseAmountPTR() == nullptr){
            std::cout << "\nDatabase has not been allocated yet.\n";
            return;
        }
        else if(Remove_Amount > current->getCloudDatabaseAmountAsInt()){
            std::cout << "\nCannot remove more cloud database than the total amount of storage!\n";
            return;
        }
        current->removeCloudDatabaseAmount(Remove_Amount);
        if(current->getCloudDatabaseAmountAsInt() == 0){
            current->removeCloudDatabaseAmountAddress(current->getCloudDatabaseAmountPTR());
        }
        Server_Service::Free_Total_Storage_Amount(Remove_Amount);

        std::cout << "\nRemoved " << Remove_Amount << "TB of database from user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudDatabaseAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";
    }
    void Server_Service::Add_Cloud_Bandwidth_Amount(User_List* list, int UniqueID, int Add_Amount){
        if(Add_Amount == 0){
            std::cout << "\nNot adding anything.\n";
            return;
        }
        if(Add_Amount > Total_Storage_Amount){
            std::cout << "\nCannot add more cloud bandwidth than the maximum amount!\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudBandwidthAmountPTR() == nullptr){
            current->assignCloudBandwidthAmountNewAddress();
        }
        current->addCloudBandwidthAmount(Add_Amount);
        Server_Service::Use_Total_Storage_Amount(Add_Amount);

        std::cout << "\nAdded " << Add_Amount << "TB of bandwidth to user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudBandwidthAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";

    }
    void Server_Service::Remove_Cloud_Bandwidth_Amount(User_List* list, int UniqueID, int Remove_Amount){
        if(Remove_Amount == 0){
            std::cout << "\nNot removing anything.\n";
            return;
        }
        User* current = Get_User_By_ID(list, UniqueID);
        if(current->getCloudBandwidthAmountPTR() == nullptr){
            std::cout << "\nBandwidth has not been allocated yet.\n";
            return;
        }
        else if(Remove_Amount > current->getCloudBandwidthAmountAsInt()){
            std::cout << "\nCannot remove more cloud Bandwidth than the total amount of storage!\n";
            return;
        }
        current->removeCloudBandwidthAmount(Remove_Amount);
        if(current->getCloudBandwidthAmountAsInt() == 0){
            current->removeCloudBandwidthAmountAddress(current->getCloudBandwidthAmountPTR());
        }
        Server_Service::Free_Total_Storage_Amount(Remove_Amount);

        std::cout << "\nRemoved " << Remove_Amount << "TB of bandwidth from user " << current->getUsername() << std::endl;
        std::cout << "\nCurrent Amount: " << current->getCloudBandwidthAmountAsInt() << "TB\n";
        std::cout << "\nOperation completed!\n";
    }

void Modify_User_Storage_Services_Value(User_List* list, char& User_Input, int User_ID){
    while(true){
        std::cout << "\n(0) Exit; (1) Add; (2) remove;\n";
        int option = 0;
        std::cin >> option;
        if(option == 0){
            break;
        }
        else if(option == 1){
            std::cout << "\nHow much storage would you like to add? (Write in TB):\n";
            int Add_Amount = 0;
            std::cin >> Add_Amount;
            Server_Service::Add_Cloud_Storage_Amount(list, User_ID, Add_Amount);
        }
        else if(option == 2){
            std::cout << "\nHow much storage would you like to remove? (Write in TB):\n";
            int Remove_Amount = 0;
            std::cin >> Remove_Amount;
            Server_Service::Remove_Cloud_Storage_Amount(list, User_ID, Remove_Amount);
        }
        else{
            std::cout << "\nIncorrect option!\n";
        }
    }
}

void Modify_User_Database_Services_Value(User_List* list, char& User_Input, int User_ID){
    while(true){
        std::cout << "\n(0) Exit; (1) Add; (2) remove;\n";
        int option = 0;
        std::cin >> option;
        if(option == 0){
            break;
        }
        else if(option == 1){
            std::cout << "\nHow much database would you like to add? (Write in TB):\n";
            int Add_Amount = 0;
            std::cin >> Add_Amount;
            Server_Service::Add_Cloud_Database_Amount(list, User_ID, Add_Amount);
        }
        else if(option == 2){
            std::cout << "\nHow much storage would you like to remove? (Write in TB):\n";
            int Remove_Amount = 0;
            std::cin >> Remove_Amount;
            Server_Service::Remove_Cloud_Database_Amount(list, User_ID, Remove_Amount);
        }
        else{
            std::cout << "\nIncorrect option!\n";
        }
    }
}
void Modify_User_Bandwidth_Services_Value(User_List* list, char& User_Input, int User_ID){
    while(true){
        std::cout << "\n(0) Exit; (1) Add; (2) remove;\n";
        int option = 0;
        std::cin >> option;
        if(option == 0){
            break;
        }
        else if(option == 1){
            std::cout << "\nHow much bandwidth would you like to add? (Write in TB):\n";
            int Add_Amount = 0;
            std::cin >> Add_Amount;
            Server_Service::Add_Cloud_Bandwidth_Amount(list, User_ID, Add_Amount);
        }
        else if(option == 2){
            std::cout << "\nHow much bandwidth would you like to remove? (Write in TB):\n";
            int Remove_Amount = 0;
            std::cin >> Remove_Amount;
            Server_Service::Remove_Cloud_Bandwidth_Amount(list, User_ID, Remove_Amount);
        }
        else{
            std::cout << "\nIncorrect option!\n";
        }
    }
}

void Admin_Modify_Services_Value(User_List* list, char& User_Input){
    while(true){
        std::cout << "\nCurrent Service Statistics:\n";
        Server_Service::Print_Service_Statistics(list);
        std::cout << "Current users:\n";
        Display_List(list);
        std::cout << "\nSelect a user to modify services' value, (0) to exit: ";
        int count = 0;
        std::cin >> count;
        std::cout << std::endl;

        if(count == 0){
            break;
        }
        else if(count > 0 && count < User::Total_Users){
            int User_ID = count + 1;
            Read_User_Input(User_Input, 6);
            if(User_Input == '0'){
                break;
            }
            else if(User_Input == '1'){ //Change Cloud Storage Amount.
                Modify_User_Storage_Services_Value(list, User_Input, User::getCurrent_User_ID());
            }
            else if(User_Input == '2'){ //Change Cloud Database Amount.
                Modify_User_Database_Services_Value(list, User_Input, User::getCurrent_User_ID());
            }
            else if(User_Input == '3'){ //Delete Cloud Bandwidth Amount.
                Modify_User_Bandwidth_Services_Value(list, User_Input, User::getCurrent_User_ID());
            }
        }
        else {
            std::cout << "\nNo such user!\n";
            continue;
        }
    }
}

void User_Modify_Services_Value(User_List* list, char& User_Input){
    if(User::getCurrent_User_ID() == 0){
        return;
    }
    while(true){
        Server_Service::getMaximumOverallStorageAmountOfUser(list);
        Read_User_Input(User_Input, 7);
        if(User_Input == '0'){
            break;
        }
        if(User_Input == '1'){ //Storage
            Modify_User_Storage_Services_Value(list, User_Input, User::getCurrent_User_ID());
        }
        if(User_Input == '2'){ //Database
            Modify_User_Database_Services_Value(list, User_Input, User::getCurrent_User_ID());
        }
        if(User_Input == '3'){ //Bandwidth
            Modify_User_Bandwidth_Services_Value(list, User_Input, User::getCurrent_User_ID());
        }

    }
}

/*
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
}*/
