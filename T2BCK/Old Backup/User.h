#pragma once

/*This "User" header file includes the User class which will be used alongside Server_Service class (from "Server_Service" header file).
 * 1st goal of this class is to create an Admin object which will have more functionality than a standard user in the Server_Service class.
 * 2nd goal of this class is to enable the Admin or the User to successfully log into their account by checking the entered Username and Password.
 * 3rd goal of this class is to store information from the Server_Service class main object such as: (for standard user) the total amount of storage used with the provided service(-s);
 * (for admin) see and access all the information about the standard user and also see all their taken actions (i.e. every action of the standard user is logged).*/

class User {
private:
    std::string Username; //Create a string for user username.
    std::string Password; //Create a string for user password.

private:
    int* Cloud_Storage_Amount;
    int* Cloud_Database_Amount;
    int* Cloud_Bandwidth_Amount;

public:
    static int Total_Users; /*Log the total amount of total user. !The main intention here was to use a dynamic list and create as many accounts as the user wants, but that proved to be
 * too difficult at the moment so that idea has been scrapped, but I might come back and redo this later, once I have more knowledge!*/

    User() //Call the User constructor and initialize with basic information. Also add to the total amount of users each time an object is called.
    : Username("\"Not set\""), Password("user"), Cloud_Storage_Amount(nullptr), Cloud_Database_Amount(nullptr), Cloud_Bandwidth_Amount(nullptr)
    {
        Total_Users++;
    }
    static int getTotalUsers(){ //For debugging.
        return Total_Users;
    }

    int getCloudStorageAmountAsInt() {
        return *Cloud_Storage_Amount;
    }

    void getCloudStorageAmount() const;

    void AddCloudStorageAmount(int cloudStorageAmount);

    void FreeCloudStorageAmount(int cloudStorageAmount);

    void setUsername(const std::string &username) { //Setter for Username.
        Username = username;
    }
    const std::string &getUsername() const { //Getter for Username.
        return Username;
    }
    void setPassword(const std::string &username) { //Setter for Password.
        Password = username;
    }
    const std::string &getPassword() const { //Getter for Password. !Not necessary for now, so it might be removed in the future!
        return Password;
    }
    bool UserLogin(){ //When this function is called it checks the User object Username and Password. If they are correctly entered return true.
        std::string username;
        std::string password;

        std::cout << "\nEnter Username: ";
        std::cin >> username;
        std::cout << "\nEnter Password: ";
        std::cin >> password;
        while(true){
            if(username == Username && password == Password){
                std::cout << "\nLogin successful.\n";
                return true;
            }
            else{
                std::cout << "\nIncorrect!\n";
                return false;
            }
        }
    }
};

int User::Total_Users = 0;

/*void User::setCloudStorageAmount(int *cloudStorageAmount) {
    Cloud_Storage_Amount = cloudStorageAmount;
}*/

void Create_New_User(User* Standard_User){ //Sets the Username and Password of Standard_User object.

    std::string username;
    std::string password;

    std::cout << "\nEnter a new username for new account: ";
    std::cin >> username;
    std::cout << "\nEnter a new password for new account: ";
    std::cin >> password;

    Standard_User->setUsername(username);
    Standard_User->setPassword(password);

    std::cout << "\nNew account " << username << " created!\n"; //User feedback.
}

//The idea for this function was to manage dynamic user creation and deletion. !Not used!
/*void Delete_User(User* Standard_User){

    std::cout << Standard_User->getUsername() << " has been deleted!";

    delete Standard_User;

}*/