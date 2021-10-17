#include "Console.h"

//Printing to console functions:
void Console::PTC(const std::string &Print)
{
  std::cout << Print;
}

void Console::PTC(const std::string &Print1, const std::string &Print2)
{
  std::cout << Print1 << Print2;
}

void Console::PTC(const std::string &Print1, int count, const std::string &Print2)
{
  std::cout << Print1 << count << Print2;
}

void Console::PTC(const std::string &Print1, const std::string &Print2, const std::string &Print3)
{
  std::cout << Print1 << Print2 << Print3;
}

void
Console::PTC(const std::string &Print1, int count1, const std::string &Print2, int count2, const std::string &Print3)
{
  std::cout << Print1 << count1 << Print2 << count2 << Print3;
}

void Console::PTC(int n)
{
  std::cout << n;
}

void Console::PrintUserWithCount(int Count, const std::string &Print)
{
  std::cout << "\n(" << Count << ") User: " << Print << "\n";
}

//Getting Input from User functions:
int Console::Get_Input_By_INT() //Function can return any integer.
{
  std::string input; //Crate a variable where the user can input anything.

  int converted; //Create a variable that will output only an integer.
  while (true) {
    std::cin >> input; //Request input from user.
    try {
      converted = std::stoi(input); //If conversion from string to integer is successful then break the loop.
      break;
    }
    catch (std::invalid_argument &i) { //If user entered a char or a char array throw an exception.
      PTC(i.what());
      PTC("\n!EXCEPTION!\n");
    }
    catch (std::out_of_range &i) { //If user went out of bounds of string throw an exception.
      PTC(i.what());
      PTC("\n!EXCEPTION!\n");
    }
  }
  return converted;
}

int Console::Get_Input_By_INT(int min,
                              int max) //Utilize Get_Input_By_Int function but within a minimum and a maximum parameter a user can enter.
{
  while (true) {
    int input = Get_Input_By_INT(); //Call Get_Input_By_INT function and return an integer.
    if (input >= min && input <= max) { //If input is withing min and max parameter return input.
      return input;
    } else { //If input is outside min and max, throw an exception.
      PTC("!EXCEPTION!\n");
    }
  }
}

//Printing to Console and getting output from user functions:
int
Console::Get_Input_Yes_Or_No() //Utilize Get_Input_By_INT with min and max parameters, to get a yes or a no from a user as input.
{
  PTC("Answer with: (1) Yes; (0) No.\n"); //Prompt user what input is required to continue.
  int input = Get_Input_By_INT(0, 1); //Get an integer withing min and max parameters.

  switch (input) {
    case 0: //No
      PTC("\nNo selected!\n");
      return input;
    case 1: //Yes
      PTC("\nYes selected!\n");
      return input;
    default: //Other - exception.
      PTC("\n!EXCEPTION!\n");
      break;
  }
}
//WIP
//int Console::Login_Prompt(User_List* list){
//    PTC("\nTo proceed you must login or create a new account.\n", "\n(0) To exit /or/ (1) Login in; (2) Create new account;\n");
//    int input = Get_Input_By_INT();
//
//    switch(input){
//        case 0:
//            PTC("\nExiting!\n");
//            break;
//            //return 0;
//        case 1:
//            PTC("\nLogin selected!\n");
//            UserLogin(list);
//        case 2:
//            PTC("\nCreate new account selected!\n");
//            Create_User(list);
//        default:
//            PTC("\nError!\n");
//            break;
//    }
//}
