#pragma once

bool Search_For_User_Login(User* head, std::string& username, std::string& password); //Function Prototype

struct User_List{
    User* head = nullptr;
    User* tail = nullptr;

    int length() const {
        int length = 0;
        User* temp;
        temp = head;
        while(temp != nullptr){
            temp = temp->next;
            length++;
        }
        return length;
    }
};

void Display_List(User* head){
    while(head != nullptr){
        std::cout << head << " " << "Username: " << head->getUsername() << " " << head->next << std::endl;
        std::cout << head << " " << "Password: " << head->getPassword() << " " << head->next << std::endl;
        head = head->next;
    }
}

void Create_User(User_List* list, const std::string& username, const std::string& password){
    User* temp = new User;
    temp->setUsername(username);
    temp->setPassword(password);
    temp->next = nullptr;

    if(list->head == nullptr){
        list->head = temp;
        list->tail = temp;
    }
    else{
        list->tail->next = temp;
        list->tail = temp;
    }
}

void deleteHead(User_List* list){
    User* temp;
    temp = list->head->next;
    delete list->head;
    list->head = temp;
}

void deleteTail(User_List* list){
    User* current;
    User* previous;
    current = list->head;
    while(current->next != nullptr){
        previous = current;
        current = current->next;
    }
    previous->next = nullptr;
    list->tail = previous;
}

void deletePos(User_List* list, int position){
    User* current;
    User* previous;
    current = list->head;
    for(int i = 1; i < position; i++){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
}

void deleteByPos(User_List* list, int position){
    if(position > list->length() || position <= 0){
        std::cout << "\n\nEXCEPTION!\n\n";
        return;
    }
    else if(position == 1){
        deleteHead(list);
    }
    else if(list->length() == position){
        deleteTail(list);
    }
    else{
        deletePos(list, position);
    }
}

bool UserLogin(User* head){ //When this function is called it checks the User object Username and Password; if they are correctly entered return true.
    std::string username;
    std::string password;

    std::cout << "\nEnter Username: ";
    std::cin >> username;
    std::cout << "\nEnter Password: ";
    std::cin >> password;


    if (Search_For_User_Login(head, username, password)) {
        std::cout << "\nLogin successful.\n";
        return true;
    } else {
        std::cout << "\nNo such user found.\n";
        return false;
    }
}

bool Search_For_User_Login(User* head, std::string& username, std::string& password) //Function definition
{

    for(int i = 0; i < User::getTotalUsers(); i++){
        if(username == head->getUsername() && password == head->getPassword()){
            return true;
        }
        head = head->next;
    }
    return false;
}

/*void Delete_User_By_Unique_ID(List* list, User* head, int RequestedUserID) {
    while (true) {
        if (RequestedUserID > User::Total_Users) {
            break;
        } else if (head->next->next->getUniqueId() != RequestedUserID) {
            std::cout << head->getUsername() << " " << head->getUniqueId() << std::endl;
            head = head->next;
        } else {
            std::cout << head->getUsername() << " " << head->getUniqueId() << "Selected!" << std::endl;
            break;
        }
    }
}*/