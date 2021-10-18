#include "Interface.h"

void Interface::Login_Prompt(User_List *list)
{
  Data_Manager::setCurrent_User_ID(0);
  Data_Manager::setCurrent_User_Username("NULL");
  std::string username;
  std::string password;
  bool istrue = true;
  while (istrue) {
    PTC("\nTo proceed you must login or create a new account.\n",
        "\n(0) To exit /or/ (1) Login in; (2) Create new account;\n");
    int input = Get_Input_By_INT(0, 2);

    switch (input) {
      case 0:
        PTC("\nExiting!\n");
        istrue = false;
        break;
      case 1:
        PTC("\nLogin selected!\n");
        User_List::UserLogin(list);
//        if(User_List::UserLogin(list)){
//          istrue = false;
//        }
        break;
      case 2:
        PTC("\nCreate new account selected!\n");
        PTC("\nEnter a username:");
        std::cin >> username;
        PTC("\n\nEnter a password:");
        std::cin >> password;
        User_List::Create_User(list, username, password);
        break;
      default:
        break;
    }
    if (Data_Manager::getCurrent_User_ID() == 1) {
      Admin_CUI(list);
    } else if (Data_Manager::getCurrent_User_ID() > 1) {
      User_CUI(list);
    }
  }
}

void Interface::Admin_CUI(User_List *list)
{
  bool istrue = true;
  while (istrue) {
    PTC("(0) Log out; (1) See Log; (2) See services' usage statistics; (3) Modify User Services' Values; (4) Modify user account(-s).\n");
    int input = Get_Input_By_INT(0, 4);

    switch (input) {
      case 0:
        PTC("\nLogging out!\n");
        Data_Manager::setCurrent_User_ID(0);
        istrue = false;
        break;
      case 1:
        //std::cout << "\nOpening log.\n";
        PTC("\nLogs are not implemented yet!\n");
        //
        break;
      case 2:
        PTC("\nOpening statistics.\n");
        Data_Manager::getMaximumOverallStorageAmountOfAllUsers(list);
        break;
      case 3:
        PTC("\nEntering user info modification.\n");
        Service_Manager::Admin_Modify_Services_Value(list);

        break;
      case 4:
        PTC("\nEntering user configuration.\n");
        Service_Manager::Admin_Modify_User_Account_Info(list);
        break;
      default:
        break;
    }
  }
}

void Interface::User_CUI(User_List *list)
{
  bool istrue = true;
  while (istrue) {
    PTC("(0) Log out; (1) See and modify my account information; (2) See my services' usage statistics; (3) Buy Services\n");
    int input = Get_Input_By_INT(0, 3);

    switch (input) {
      case 0:
        PTC("\nLogging out!\n");
        Data_Manager::setCurrent_User_ID(0);
        istrue = false;
        break;
      case 1:
        PTC("\nEntering user configuration.\n");
        Service_Manager::User_Modify_User_Account_Info(list);
        if (Data_Manager::getCurrent_User_ID() == 0) {
          std::cout << "\n\nYou have been automatically logged out!\n\n";
          istrue = false;
          break;
        }
        break;
      case 2:
        PTC("\nOpening usage statistics.\n");
        Data_Manager::getMaximumOverallStorageAmountOfUser(list);
        break;
      case 3:
        PTC("\nEntering services manipulation.\n");
        Service_Manager::User_Modify_Services_Value(list);
        break;
      default:
        break;
    }
  }
}

int Interface::Service_Manager_For_Admin()
{
  PTC("\nWhich service do you want to modify?\n",
      "(0) Exit; (1) Cloud Storage Amount; (2) Cloud Database Amount; (3) Cloud Bandwidth Amount:\n");
  int input = C::Get_Input_By_INT(0, 3);

  switch (input) {
    case 0:
      PTC("\nExiting this menu.\n");
      return input;
    case 1:
      PTC("\nChange storage amount selected.\n");
      return input;
    case 2:
      PTC("\nChanging storage database amount selected\n");
      return input;
    case 3:
      PTC("\nDeleting storage bandwidth amount selected\n");
      return input;
    default:
      PTC("\nIncorrect answer!\n");
  }
}

int Interface::Service_Manager_For_User()
{
  PTC("\n(0) to exit; (1) Buy or refund Cloud Storage; (2) Buy or refund Cloud Database; (3) Buy or refund Cloud Bandwidth.\n");
  int input = C::Get_Input_By_INT(0, 3);

  switch (input) {
    case 0:
      PTC("\nExiting this menu.\n");
      return input;
    case 1:
      PTC("\nCloud Storage menu selected.\n");
      return input;
    case 2:
      PTC("\nCloud Database menu selected.\n");
      return input;
    case 3:
      PTC("\nCloud Bandwidth selected.\n");
      return input;
    default:
      PTC("\nIncorrect answer!\n");
  }
}

int Interface::Exit_Add_Remove()
{
  PTC("\n(0) Exit; (1) Add; (2) remove;\n");
  int input = C::Get_Input_By_INT(0, 2);

  switch (input) {
    case 0:
      PTC("\nExiting this menu.\n");
      return input;
    case 1:
      PTC("\nHow much storage would you like to add? (Write in TB):\n");
      return input;
    case 2:
      PTC("\nHow much storage would you like to remove? (Write in TB):\n");
      return input;
    default:
      PTC("\nIncorrect answer!\n");
  }
}

//Admin and User Service manipulation:

void Service_Manager::Admin_Modify_Services_Value(User_List *list)
{
  while (true) {
    std::cout << "\nCurrent Service Statistics:\n";
    Print_Service_Statistics(list);
    std::cout << "Current users:\n";
    User_List::Display_List(list);
    std::cout << "\nSelect a user to modify services' value, (0) to exit: ";
    int count = 0;
    std::cin >> count;
    std::cout << std::endl;

    if (count == 0) {
      break;
    } else if (count > 0 && count < Data_Manager::getTotal_Users()) {
      int User_ID = count + 1;
      int input = Interface::Service_Manager_For_Admin();
      switch (input) {
        case 0:
          break;
        case 1:
          Modify_User_Storage_Services_Value(list, User_ID);
          break;
        case 2:
          Modify_User_Database_Services_Value(list, User_ID);
          break;
        case 3:
          Modify_User_Bandwidth_Services_Value(list, User_ID);
          break;
        default:
          continue;
      }
    } else {
      std::cout << "\nNo such user!\n";
      continue;
    }
  }
}

void Service_Manager::User_Modify_Services_Value(User_List *list)
{
  if (Data_Manager::getCurrent_User_ID() == 0) {
    return;
  }
  bool istrue = true;
  while (istrue) {
    Data_Manager::getMaximumOverallStorageAmountOfUser(list);
    int input = Interface::Service_Manager_For_User();
    switch (input) {
      case 0:
        istrue = false;
        break;
      case 1:
        Modify_User_Storage_Services_Value(list, Data_Manager::getCurrent_User_ID());
        break;
      case 2:
        Modify_User_Database_Services_Value(list, Data_Manager::getCurrent_User_ID());
        break;
      case 3:
        Modify_User_Bandwidth_Services_Value(list, Data_Manager::getCurrent_User_ID());
        break;
      default:
        break;
    }
  }
}

void Service_Manager::Modify_User_Storage_Services_Value(User_List *list, int User_ID)
{
  while (true) {
    int input = Interface::Exit_Add_Remove();
    int Add_Amount = 0;
    int Remove_Amount = 0;
    switch (input) {
      case 0:
        break;
      case 1:
        Add_Amount = C::Get_Input_By_INT();
        Add_Cloud_Storage_Amount(list, User_ID, Add_Amount);
        break;
      case 2:
        Remove_Amount = C::Get_Input_By_INT();
        Remove_Cloud_Storage_Amount(list, User_ID, Remove_Amount);
        break;
      default:
        break;
    }
    break;
  }
}

void Service_Manager::Modify_User_Database_Services_Value(User_List *list, int User_ID)
{
  while (true) {
    int input = Interface::Exit_Add_Remove();
    int Add_Amount = 0;
    int Remove_Amount = 0;
    switch (input) {
      case 0:
        break;
      case 1:
        Add_Amount = C::Get_Input_By_INT();
        Add_Cloud_Database_Amount(list, User_ID, Add_Amount);
        break;
      case 2:
        Remove_Amount = C::Get_Input_By_INT();
        Remove_Cloud_Database_Amount(list, User_ID, Remove_Amount);
        break;
      default:
        break;
    }
    break;
  }
}

void Service_Manager::Modify_User_Bandwidth_Services_Value(User_List *list, int User_ID)
{
  while (true) {
    int input = Interface::Exit_Add_Remove();
    int Add_Amount = 0;
    int Remove_Amount = 0;
    switch (input) {
      case 0:
        break;
      case 1:
        Add_Amount = C::Get_Input_By_INT();
        Add_Cloud_Bandwidth_Amount(list, User_ID, Add_Amount);
        break;
      case 2:
        Remove_Amount = C::Get_Input_By_INT();
        Remove_Cloud_Bandwidth_Amount(list, User_ID, Remove_Amount);
        break;
      default:
        break;
    }
    break;
  }
}

//Admin and User Account information manipulation:

int Interface::Account_Information_Manager_For_Admin_And_User()
{
  C::PTC("\n(0) Exit; (1) change username; (2) change password; (3) delete account.\n");
  int input = C::Get_Input_By_INT(0, 3);

  switch (input) {
    case 0:
      PTC("\nExiting this menu.\n");
      return input;
    case 1:
      PTC("\nChanging username menu selected\n");
      return input;
    case 2:
      PTC("\nChanging password menu selected\n");
      return input;
    case 3:
      PTC("\nDeleting account menu selected\n");
      return input;
    default:
      PTC("\nIncorrect answer!\n");
  }
}

void Service_Manager::Admin_Modify_User_Account_Info(User_List *list)
{
  while (true) {
    std::cout << "\nCurrent users:\n";
    User_List::Display_List(list);
    std::cout << "\nSelect a user to modify, (0) to exit: ";
    int count = 0;
    std::cin >> count;
    std::cout << std::endl;

    if (count == 0) {
      break;
    } else if (count > 0 && count < Data_Manager::getTotal_Users()) {
      int Current_UserID = count + 1;
      bool istrue = true;
      while (istrue) {
        int input = Interface::Account_Information_Manager_For_Admin_And_User();
        switch (input) {
          case 0:
            istrue = false;
            break;
          case 1:
            Modify_Username(list, Current_UserID);
            break;
          case 2:
            Modify_Password(list, Current_UserID);
            break;
          case 3:
            Delete_Account(list, Current_UserID);
            istrue = false;
            break;
          default:
            break;
        }
      }
    } else {
      std::cout << "\nNo such user!\n";
      continue;
    }
  }
}

void Service_Manager::User_Modify_User_Account_Info(User_List *list)
{
  if (Data_Manager::getCurrent_User_ID() == 0) {
    return;
  }
  //int count = User::Current_User_ID;
  User *CurrentUser = User_List::Get_User_By_ID(list, Data_Manager::getCurrent_User_ID());
  std::cout << "\nUsername: " << CurrentUser->getUsername() << "\n";
  std::cout << "\nPassword: " << CurrentUser->getPassword() << "\n";
  std::cout << "\nUnique ID: " << CurrentUser->getUniqueId() << "\n";
  Current_User_ID = CurrentUser->getUniqueId();
  bool istrue = true;
  while (istrue) {
    int input = Interface::Account_Information_Manager_For_Admin_And_User();
    switch (input) {
      case 0:
        istrue = false;
        break;
      case 1:
        Modify_Username(list, Current_User_ID);
        break;
      case 2:
        Modify_Password(list, Current_User_ID);
        break;
      case 3:
        Delete_Account(list, Current_User_ID);
        istrue = false;
        break;
      default:
        break;
    }
  }
}

void Service_Manager::Modify_Username(User_List *list, int Current_UserID)
{
  User *GetUser = User_List::Get_User_By_ID(list, Current_UserID);

  std::string new_username;
  std::cout << "\nEnter new username: ";
  std::cin >> new_username;
  std::cout << "\nChange " << GetUser->getUsername() << " to " << new_username << " ?\n";
  bool istrue = true;
  while (istrue) {
    int input = C::Get_Input_Yes_Or_No();
    switch (input) {
      case 0:
        istrue = false;
        break;
      case 1:
        std::cout << "\n" << GetUser->getUsername() << " changed to " << new_username << "\n";
        GetUser->setUsername(new_username);
        istrue = false;
        break;
      default:
        break;
    }
  }
}

void Service_Manager::Modify_Password(User_List *list, int Current_UserID)
{
  User *GetUser = User_List::Get_User_By_ID(list, Current_UserID);

  std::string new_password;
  std::cout << "\nEnter new password: ";
  std::cin >> new_password;
  std::cout << "\nChange " << GetUser->getPassword() << " to " << new_password << " ?\n";
  bool istrue = true;
  while (istrue) {
    int input = C::Get_Input_Yes_Or_No();
    switch (input) {
      case 0:
        istrue = false;
        break;
      case 1:
        std::cout << "\n" << GetUser->getPassword() << " changed to " << new_password << "\n";
        GetUser->setPassword(new_password);
        istrue = false;
        break;
      default:
        break;
    }
  }
}

void Service_Manager::Delete_Account(User_List *list, int Current_UserID)
{
  User *GetUser = User_List::Get_User_By_ID(list, Current_UserID);

  std::cout << "\nAre you sure you want to delete " << GetUser->getUsername() << "; Unique ID: "
            << GetUser->getUniqueId() << "?\n";
  bool istrue = true;
  while (istrue) {
    int input = C::Get_Input_Yes_Or_No();
    switch (input) {
      case 0:
        istrue = false;
        break;
      case 1:
        std::cout << "\n" << GetUser->getUsername() << " has been deleted! \n";
        User_List::Delete_Current_User_By_ID(list, Current_UserID);
        Data_Manager::setCurrent_User_ID(0);
        istrue = false;
        break;
      default:
        break;
    }
  }
  if (Current_UserID != 1) {
    Current_UserID = 0;
  }
}