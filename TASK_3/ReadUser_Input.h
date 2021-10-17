#ifndef STRUCTURED_PROGRAMMING_TASKS_DURENGO_READUSER_INPUT_H
#define STRUCTURED_PROGRAMMING_TASKS_DURENGO_READUSER_INPUT_H

void ReadUser_Input(char& User_Input, int i) { //This is our main function to request input from the user. Using a reference pointer we ensure that we are writing and saving the users input for other components top utilize the return value.
    //int i indicates which option to use;
    //int i is set outside this function;

    if (i == 1) { //int i = 1 - Basic Yes or No input read.
        while (true) { //This is our initial loop for reading User_Input
            std::cin >> User_Input; //Await for user input.
            std::cin.ignore(100, '\n'); //Since our main input requires only 1 character we don't need to read more than 1 character for our input. That means we can set a hard limit of 1 character to be read. This way we also save memory and prevent this loop from running multiple times (looping for each character entered)
            if (User_Input == 'Y' || User_Input == 'y' || User_Input == '1' || User_Input == 'N' || User_Input == 'n' ||
                User_Input == '0') { //If user enters 'Y', 'y', '1', 'N', 'n', '0' stop break from loop and return to function call.
                break;
            }
            std::cout << "Incorrect answer! Please enter again!" << std::endl; //If user enters unspecified character run the loop again and prompt for input.
        }
    }
    if (i == 2) { //int i = 2 - Basic 1 or 2 or 3 input read.
        while (true) {
            std::cin >> User_Input;
            std::cin.ignore(100, '\n');
            if (User_Input == '1' || User_Input == '2' || User_Input == '3') {
                break;
            }
            std::cout << "Incorrect answer! Please enter again!" << std::endl;
        }
    }
    if (i == 3) { //int i = 3 - Basic 1 or 2 or 3 or 4 input.
        while (true) {
            std::cin >> User_Input;
            std::cin.ignore(100, '\n');
            if (User_Input == '1' || User_Input == '2' || User_Input == '3' || User_Input == '4') {
                break;
            }
            std::cout << "Incorrect answer! Please enter again!" << std::endl;
        }
    }
    if (i == 4) { //int i = 4 - Basic Left or Center or Right input read.
        while (true) {
            std::cin >> User_Input;
            std::cin.ignore(100, '\n');
            if (User_Input == 'L' || User_Input == 'l' || User_Input == 'C' || User_Input == 'c' || User_Input == 'R' || User_Input == 'r') {
                break;
            }
            std::cout << "Incorrect answer! Please enter again!" << std::endl;
        }
    }
}
#endif //STRUCTURED_PROGRAMMING_TASKS_DURENGO_READUSER_INPUT_H
