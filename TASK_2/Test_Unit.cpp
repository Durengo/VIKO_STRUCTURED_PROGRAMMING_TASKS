#include "Test_Unit.h"

void setGlobalTick(int T)
{
  Global_Tick = T;
  switch (Global_Tick) {
    case 0:
      return;
    case 1:
      Console_Test();
      return;
    case 2:
      User_List_and_User_Test();
      return;
    case 3:
      Data_Management_Test();
      return;
    case 4:
      Service_Manager_Test();
      return;
    case 5:
      Interface_Test();
      return;
    case 6:
      Login_Logout_Test();
      return;
    default:
      return;
  }
}

//Tests for Console module.
void Console_Test()
{
  Console::PTC("\nHello world!\n");
  Console::PTC("\nThis is 1\n", "\nThis is 2\n");
  Console::Get_Input_By_INT();
  Console::Get_Input_By_INT(0, 10);
  Console::Get_Input_Yes_Or_No();

  Console::PTC("\nTest complete!\n");
}

//Test for User List and User.
void User_List_and_User_Test()
{
  Console::PTC("\nCreating new list.\n");
  auto *TestUserList = new User_List;

  Console::PTC("\nAdding multiple user class objects into list.\n");
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Create_User(TestUserList, "dummy1", "dummy1");
  User_List::Create_User(TestUserList, "dummy2", "dummy2");
  User_List::Create_User(TestUserList, "dummy3", "dummy3");
  User_List::Create_User(TestUserList, "dummy4", "dummy4");
  User_List::Create_User(TestUserList, "dummy5", "dummy5");

  Console::PTC("\nDisplaying all user objects:\n");
  User_List::Display_List(TestUserList);

  Console::PTC("\nCreating a user object with the same username:\n");
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Display_List(TestUserList);

  Console::PTC("\nCreating a new user object\n");
  User_List::Create_User(TestUserList, "durengo", "durengo");
  User_List::Display_List(TestUserList);

  Console::PTC("\nLength function test:\n");
  Console::PTC(TestUserList->length());

//  Console::PTC("\nDeleting head function:\n");
//  User_List::deleteHead(TestUserList);
//  User_List::Display_List(TestUserList);

  Console::PTC("\nDeleting tail function:\n");
  User_List::deleteTail(TestUserList);
  User_List::Display_List(TestUserList);

  Console::PTC("\nDelete by pos function [2nd] element\n");
  User_List::deleteByPos(TestUserList, 2);
  User_List::Display_List(TestUserList);

  Console::PTC("\nDelete pos function [3rd] element/should never be called like this/\n");
  User_List::deletePos(TestUserList, 3);
  User_List::Display_List(TestUserList);

  Console::PTC("\nTest basic logging in functionality.\n");
  User_List::UserLogin(TestUserList);
  User_List::Display_List(TestUserList);

  Console::PTC("\nDelete current user by id. Setting current user ID to 5 (dummy5)\n");
  Data_Manager::setCurrent_User_ID(5);
  User_List::Delete_Current_User_By_ID(TestUserList, Data_Manager::getCurrent_User_ID());
  User_List::Display_List(TestUserList);
  Console::PTC("\nSet current user ID to 0\n");
  Data_Manager::setCurrent_User_ID(0);

}

void Data_Management_Test()
{
  Console::PTC("\n\n");

  Console::PTC("\nCreating new list; admin; dummy.\n");
  auto *TestUserList = new User_List;
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Create_User(TestUserList, "dummy", "dummy");

  Console::PTC("\nCreating data module.\n");
  Data_Manager Main;

  Console::PTC("\nget total user: ", Main.getTotal_Users(), "\n");
  Console::PTC("\nget current user ID: ", Main.getCurrent_User_ID(), "\n");
  Console::PTC("\nget current username: ", Main.getCurrent_User_Username());


  Console::PTC("\nmaximum storage amount:\n");
  Main.getMaximumOverallStorageAmount();

  Console::PTC("\nget maximum storage amount by int :", Main.getMaximum_Overall_Storage_Amount(), "\n");

  Console::PTC("\nmaximum overall storage amount of (1) all users; (2) of a user:\n");
  Main.getMaximumOverallStorageAmountOfAllUsers(TestUserList);
  Console::PTC("\nset current user ID and username to dummy; otherwise does not work.\n");
  Data_Manager::setCurrent_User_ID(2);
  Data_Manager::setCurrent_User_Username("dummy");
  Main.getMaximumOverallStorageAmountOfUser(TestUserList);
  Console::PTC("\nset current user ID and username to null\n");
  Data_Manager::setCurrent_User_ID(0);
  Data_Manager::setCurrent_User_Username("NULL");
}

void Service_Manager_Test()
{
  Console::PTC("\nCreating new list.\n");
  auto *TestUserList = new User_List;
  Data_Manager Main; //If this is not called the constructor will not generate a storage amount!!!

  Console::PTC("\nPrint out generated storage amount\n");

  Data_Manager::getMaximumOverallStorageAmount();

  Console::PTC("\nAdding multiple user class objects into list.\n");
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Create_User(TestUserList, "dummy", "dummy");

  User_List::Display_List(TestUserList);

  Service_Manager::Print_Service_Statistics(TestUserList);

//  User_List::deleteTail(TestUserList);
//  User_List::Display_List(TestUserList);
//  Service_Manager::Print_Service_Statistics(TestUserList);

  Console::PTC("\nSet unique ID and username to dummy then execute code:\n");
  Data_Manager::setCurrent_User_ID(2);
  Data_Manager::setCurrent_User_Username("dummy");
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
//  Console::PTC("\nPrint out stats, see if works and reset ID and username.\n");
//  Service_Manager::Print_Service_Statistics(TestUserList);
//  Data_Manager::setCurrent_User_ID(0);
//  Data_Manager::setCurrent_User_Username("NULL");
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 500);
  Service_Manager::Print_Service_Statistics(TestUserList);

  Console::PTC("\nTest if heap allocation is working or not:\n");
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(),
                                               500); //should not allow.
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 100);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(),
                                               500); //should not allow.
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600); //should realloc
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(),
                                               600); //should free again.
  Console::PTC("\nSuccess!\n");
  Console::PTC("\n\n\n\n\n\n");
  Console::PTC(
          "\nTest if all three attributes of 2 different user objects work properly: mainly memory reallocation test.\n");
  Data_Manager::setCurrent_User_ID(0);
  Data_Manager::setCurrent_User_Username("NULL");
  Data_Manager::setCurrent_User_ID(2);
  Data_Manager::setCurrent_User_Username("dummy");
  //dummy test
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Add_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Add_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Add_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 500);
  Service_Manager::Add_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 500);
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 2000);
  Service_Manager::Remove_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 2000);
  Service_Manager::Remove_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Remove_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Print_Service_Statistics(TestUserList);
  Console::PTC("\n\n\n\n\n\nCreating a new user, print user list and set current id and username.");
  User_List::Create_User(TestUserList, "durengo", "durengo");
  User_List::Display_List(TestUserList);
  Data_Manager::setCurrent_User_ID(3);
  Data_Manager::setCurrent_User_Username("durengo");
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Add_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Add_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Add_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Add_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 500);
  Service_Manager::Add_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 500);
  Service_Manager::Print_Service_Statistics(TestUserList);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Storage_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 600);
  Service_Manager::Remove_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 2000);
  Service_Manager::Remove_Cloud_Database_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 2000);
  Service_Manager::Remove_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Remove_Cloud_Bandwidth_Amount(TestUserList, Data_Manager::getCurrent_User_ID(), 1000);
  Service_Manager::Print_Service_Statistics(TestUserList);
  //So far testing works well.
}

void Interface_Test()
{
  Console::PTC("\nCreating new list. Initializing Data Manager\n");
  auto *TestUserList = new User_List;
  Data_Manager Main;

  Console::PTC("\nAdding multiple user class objects into list.\n");
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Create_User(TestUserList, "dummy", "dummy");
  //set user ID the next part will cause memory problems!
  Data_Manager::setCurrent_User_ID(2);
  Data_Manager::setCurrent_User_Username("dummy");
  Service_Manager::Admin_Modify_Services_Value(TestUserList);
  User_List::Create_User(TestUserList, "durengo", "durengo");
  User_List::Display_List(TestUserList);
  Data_Manager::setCurrent_User_ID(3);
  Data_Manager::setCurrent_User_Username("durengo");
  Service_Manager::User_Modify_Services_Value(TestUserList);

  Console::PTC("\nUser account manipulation tests.\n");
  Data_Manager::setCurrent_User_ID(0);
  Data_Manager::setCurrent_User_Username("NULL");
  Service_Manager::Admin_Modify_User_Account_Info(TestUserList);
  Console::PTC("\nSetting user to durengo.\n");
  Data_Manager::setCurrent_User_ID(3);
  Data_Manager::setCurrent_User_Username("durengo");
  Service_Manager::User_Modify_User_Account_Info(TestUserList);
  //Successful tries!

}

void Login_Logout_Test()
{
  auto *TestUserList = new User_List;
  Data_Manager Main;
  Console::PTC("\nAdding multiple user class objects into list.\n");
  User_List::Create_User(TestUserList, "admin", "admin");
  User_List::Create_User(TestUserList, "dummy", "dummy");

  Interface::Login_Prompt(TestUserList);

  User_List::Display_List(TestUserList);
  C::PTC("\nCurrent user username: ", Data_Manager::getCurrent_User_Username(), "\n");
  C::PTC("\nCurrent user ID: ", Data_Manager::getCurrent_User_ID(), "\n");


}