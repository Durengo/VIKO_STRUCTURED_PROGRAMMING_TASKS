#include "User_List.h"

User_List::User_List()
        : head(nullptr), tail(nullptr)
{
  Console::PTC("\nUser List constructed!\n");
}

void User_List::Display_List(User_List *list)
{
  int count = 1; //Keep count of every user object.
  User *current; //Temporary pointer
  current = list->head->next; //Do not print "Admin"
  while (current != nullptr) { //While head (current element) is not equal nullptr (0), continue printing users.
    Console::PrintUserWithCount(count, current->getUsername()); //Call console module to print users.
    count++; //Increment count.
    current = current->next; //Set current element to point to the next element in the list.
  }
}

void User_List::Create_User(User_List *list, const std::string &username, const std::string &password)
{ //Function for creating a new User class object and inserting it into a linked list. Pass by an instantiated list, along with username and password.
  if (Data_Manager::getTotal_Users() >= 1) { //After the admin is created this if is executed everytime.
    if (!Search_For_Username_Duplicate(list,
                                       username)) { //Call function Search_ForUsername_Duplicate; This function checks for duplicate usernames; if false is returned we stop creating a new user.
      Console::PTC("\nCannot create a new user with an already used username!\n"); //Prompt user.
      return;
    }
  }
  User *New_User = new User; //Create a new user object and allocate it to heap.
  New_User->setUsername(username); //Set new object username to given username.
  New_User->setPassword(password); //Set new object username to given password.
  New_User->next = nullptr; //We always insert a new element into the terminal (tail) point of our list, so we set the new element to be the new terminal (tail) point by assigning the pointer to nullptr.

  if (list->head != nullptr) { //This code runs after the very first element in a linked list has been created.
    list->tail->next = New_User; //Set the next pointer of terminal (tail) pointer to point to nullptr (0).
    list->tail = New_User; //Set the terminal (tail) pointer to point to the newly created object.
  } else { //This if runs only once for any newly created linked list.
    list->head = New_User; //Set initial (head) pointer to point to newly created User class object.
    list->tail = New_User; //Set terminal (tail) pointer to point to newly created User class object.
  }
}

bool User_List::Search_For_Username_Duplicate(User_List *list,
                                              const std::string &username) //This function will check for duplicate username <strings>; this function can will only be called by Create_User(); this function can only be called after the admin user object has been created.
{
  User *current = nullptr; //Declare and initialize pointer current to nullptr.
  current = list->head; //Set current pointer to the initial (head) element of a linked listed.
  while (current != nullptr) { //While the current pointer is not the last element (element->next == nullptr), continue.
    if (username ==
        current->getUsername()) { //If the new username matches the username of an element we return false and stop executing.
      return false;
    }
    current = current->next; //If the username does not match with the current element goto next element.
  }
  return true; //If username does not match any element in a linked list, return true and allow a new User class object to be created.
}

int User_List::length() const
{ //Function for counting the length of a linked list.
  int length = 0; //Declare and initialize length to 0, so that we don't access randomly allocated memory.
  User *current; //Declare a pointer of user class.
  current = head; //Initialize pointer to the initial (head) element in the list.
  while (current != nullptr) { //While current pointer element does not equal to nullptr (0) keep counting.
    current = current->next; //Set current element to the next element in the linked list.
    length++; //Increment length variable.
  }
  return length; //Once counting is finished return the value of length (total amount of elements in a linked list).
}

void User_List::deleteHead(User_List *list)
{ //Function to delete the initial (head) pointer.
  User *New; //Declare a new pointer
  New = list->head->next; //Initialize this pointer to point to the next element of the initial (head) point.
  delete list->head; //Delete the current initial (head) pointer; Free memory.
  list->head = New; //Set the initial (head) pointer to New pointer.
}

void User_List::deleteTail(User_List *list)
{ //Function to delete the terminal (tail) pointer.
  User *current; //Declare current pointer.
  User *previous; //Declare previous pointer.
  current = list->head; //Set current pointer to point to the initial (head) point of the list.
  while (current->next !=
         nullptr) { //While the next pointer of current pointer is not pointing to nullptr (0), continue.
    previous = current; //Set the previous pointer to point to the current pointer.
    current = current->next; //Set the current pointer to point to the next element in the list.
  } //Once the next element of current pointer is nullptr (0) we continue.
  previous->next = nullptr; //Set the element before the terminal (tail) element to be the last element by setting the next pointer of previous to nullptr (0).
  list->tail = previous; //Set pointer previous to terminal (tail) element of the linked list.
  delete current;
}

void User_List::deleteByPos(User_List *list, int position)
{ //Function for deleting an element in a linked listed by a given position.
  if (position > list->length() || position <=
                                   0) { //First we must check if the entered position exceeds the total amount of elements in a linked list; if true we throw an exception and return to the function call.
    std::cout << "\n\n!EXCEPTION! TRYING TO DELETE AN OUT OF BOUNDS VALUE\n\n";
    return;
  } else if (position ==
             1) { //If the entered position is 1, that means we want to delete the initial (head) element of the linked list.
    std::cout << "\n\n!EXCEPTION! CANNOT DELETE ADMIN\n\n"; //User Admin cannot be deleted.
    //deleteHead(list); //Call deleteHead function.
  } else if (list->length() ==
             position) { //If the entered position is the last element in the linked list, that means we want to delete the terminal (tail) element of the linked list.
    deleteTail(list); //Call deleteTail function.
  } else { //If we want to delete any element in between the initial (head) and the terminal (tail) elements we continue.
    deletePos(list, position); //Call the deletePos function.
  }
}

void User_List::deletePos(User_List *list, int position)
{ //This function only runs if it is called by deleteByPos function. This function only runs if the specified position is not the first or the last element in a given linked list.
  User *current; //Declare a current pointer.
  User *previous; //Declare a previous pointer.
  current = list->head; //Set current pointer to point to the initial (head) element.
  for (int i = 1; i <
                  position; i++) { //Start from the first initial (head) element of linked list and loop until the given position.
    previous = current; //Set the previous pointer to point to the current element in the linked list.
    current = current->next; //Set the current pointer to point to the next element in the linked list.
  } //Once we find the next element of the element that we want to delete from the list, we continue.
  previous->next = current->next; //Set the next pointer of the previous element to point to the next element of the current pointer.
  delete current; //Delete current element.
}

bool User_List::UserLogin(User_List *list)
{ //When this function is called it checks the User object Username and Password; if they are correctly entered return true.
  std::string username; //Declare a string username.
  std::string password; //Declare a string password.

  Data_Manager::setCurrent_User_ID(0);

  std::cout << "\nEnter Username: "; //Prompt user to enter a username for a new User class object.
  std::cin >> username;
  std::cout << "\nEnter Password: "; //Prompt user to enter a password for a new User class object.
  std::cin >> password;


  if (Search_For_User_Login(list, username,
                            password)) { //Call the Search_For_User_Login function; if the function returns true, continue.
    std::cout << "\nLogin successful.\n";
    return true;
  } else { //If the Search_For_User_Login function fails, we return.
    std::cout << "\nNo such user found.\n";
    return false;
  }
}

bool User_List::Search_For_User_Login(User_List *list, std::string &username,
                                      std::string &password) //This function is called by UserLogin function. It checks all elements of the linked list to find if the entered username and password is correct.
{
  User *current = list->head;
  for (int i = 0; i <
                  Data_Manager::getTotal_Users(); i++) { //Run this loop until the inputted username and password are correct or until the total number of users is reached.
    if (username == current->getUsername() &&
        password == current->getPassword()) { //Check if the username and password are correct.
      Data_Manager::setCurrent_User_ID(current->getUniqueId());
      Data_Manager::setCurrent_User_Username(current->getUsername());
      return true;
    }
    current = current->next; //If username and password do not match the object's data we go to the next element in the linked list.
  }
  return false; //If username and password don't match, return false.
}

void User_List::Delete_Current_User_By_ID(User_List *list, int Current_UserID)
{
  if (Current_UserID == 0) {
    std::cout << "\n\n!EXCEPTION! CANNOT DELETE ADMIN\n\n";
    return;
  }
  int count = 0;
  User *current = list->head;
  while (current != nullptr) {
    count++;
    if (current->getUniqueId() == Current_UserID) {
      deleteByPos(list, count);
      break;
    }
    current = current->next;
  }
}

User *User_List::Get_User_By_ID(User_List *list, int UniqueID)
{
  User *current = list->head;
  while (current != nullptr) {
    if (current->getUniqueId() == UniqueID) {
      return current;
    }
    current = current->next;
  }
}