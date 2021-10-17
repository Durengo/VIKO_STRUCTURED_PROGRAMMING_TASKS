#include "Console.h"

//void ITC()

void Console::PTC(const std::string& Print){
    std::cout << Print;
}
void Console::PTC(const std::string& Print1, const std::string& Print2){
    std::cout << Print1 << Print2;
}

int Console::Get_Input_By_INT() {
    std::string input;

    int converted;
    while(true){
        std::cin >> input;
        try{
            converted = std::stoi(input);
            break;
        }
        catch (std::invalid_argument& i){
            PTC(i.what());
        }
        catch (std::out_of_range& i){
            PTC(i.what());
        }

    }
    return converted;
}
int Console::Get_Input_By_INT(int min, int max){
    while(true){
        int input = Get_Input_By_INT();
        if(input >= min && input <= max){
            return input;
        }
    }
}

int Console::Get_Input_Yes_Or_No(){
    PTC("Answer with: (1) Yes; (0) No.\n");
    int input = Get_Input_By_INT(0, 1);

    switch(input){
        case 0:
            PTC("\nNo selected!\n");
            return input;
        case 1:
            PTC("\nYes selected!\n");
            return input;
        default:
            PTC("\n\n");
            break;
    }
}
/*

int Console::Login_Prompt(User_List* list){
    PTC("\nTo proceed you must login or create a new account.\n", "\n(0) To exit /or/ (1) Login in; (2) Create new account;\n");
    int input = Get_Input_By_INT();

    switch(input){
        case 0:
            PTC("\nExiting!\n");
            break;
            //return 0;
        case 1:
            PTC("\nLogin selected!\n");
            UserLogin(list);
        case 2:
            PTC("\nCreate new account selected!\n");
            Create_User(list);
        default:
            PTC("\nError!\n");
            break;
    }
}*/
