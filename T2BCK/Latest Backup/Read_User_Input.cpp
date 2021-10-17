#include "Read_User_Input.h"

/*This "Read_User_Input" header file includes the Read_User_Input which will be used to read all user input and provide the needed feedback for the user to successfully operate the program.
 * There is only one function which takes User_Input for the main character to interact with and takes in an <int> f - this <int> dictates which <if> statement to execute:
 * int f = 1 - Basic I/O for yes or no.
 * int f = 2 - Log in as (1) Admin or (2) Create new account - this if runs only once (when the program starts) so that the user is prompted to create a new user
 * int f = 3 - Log in as (1) Admin or (2) User - this if runs all the time after the user has created a new account.*/

void Read_User_Input(char& User_Input, int f){
    if(f == 1){ //Basic yes or no prompt.
        while(true){
            std::cout << "Answer with: (1) Yes; (0) No.\n";
            std::cin >> User_Input; //Read user input.
            std::cin.ignore(100000000, '\n'); //Ignore every character, but not the first one. This is done to prevent the loop from breaking and reading anything past the first character (basically to not waste the execution time).

            if(User_Input == '1'){
                std::cout << "\nYes selected!\n";
                break;
            }
            else if(User_Input == '0'){
                std::cout << "\nNo selected!\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 2){ //Login Prompt CUI
        while(true){
            std::cout << "To proceed you must login or create a new account.\n\n";
            std::cout << "(0) To exit /or/ (1) Login in; (2) Create new account; ";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nExiting!\n";
                break;
            }
            else if(User_Input == '1'){
                std::cout << "\nLogin selected!\n";
                break;
            }
            else if(User_Input == '2'){
                std::cout << "\nCreate new account selected!\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 3){ //CUI for Admin user.
        while(true){
            std::cout << "(0) Log out; (1) See Log; (2) See services' usage statistics; (3) Modify User Services' Values; (4) Modify user account(-s).\n";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nLogging out.\n";
                User::setCurrent_User_ID(0);
                break;
            }
            if(User_Input == '1'){
                std::cout << "\nOpening log.\n";
                break;
            }
            if(User_Input == '2'){
                std::cout << "\nOpening statistics.\n";
                break;
            }
            if(User_Input == '3'){
                std::cout << "\nEntering user info modification.\n";
                break;
            }
            if(User_Input == '4'){
                std::cout << "\nEntering user configuration.\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 4){ //CUI for Standard user.
        while(true){
            std::cout << "(0) Log out; (1) See and modify my account information; (2) See my services' usage statistics; (3) Buy Services\n";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nLogging out.\n";
                User::setCurrent_User_ID(0);
                break;
            }
            if(User_Input == '1'){
                std::cout << "\nEntering user configuration.\n";
                break;
            }
            if(User_Input == '2'){
                std::cout << "\nOpening usage statistics.\n";
                break;
            }
            if(User_Input == '3'){
                std::cout << "\nEntering services manipulation.\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 5){ //Interface for choosing what to do with the user (part of f == 6).
        while(true){
            std::cout << "\n(0) Exit; (1) change username; (2) change password; (3) delete account.\n";
            std::cout << "Select: ";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nExiting this menu.\n";
                break;
            }
            else if(User_Input == '1'){
                std::cout << "\nChanging username menu selected\n";
                break;
            }
            else if(User_Input == '2'){
                std::cout << "\nChanging password menu selected\n";
                break;
            }
            else if(User_Input == '3'){
                std::cout << "\nDeleting account menu selected\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 6){ //Interface for choosing what to do with the user (part of f == 6).
        while(true){
            std::cout << "\nWhich service do you want to modify?\n";
            std::cout << "(0) Exit; (1) Cloud Storage Amount; (2) Cloud Database Amount; (3) Cloud Bandwidth Amount:\n";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nExiting this menu.\n";
                break;
            }
            else if(User_Input == '1'){
                std::cout << "\nChange storage amount selected.\n";
                break;
            }
            else if(User_Input == '2'){
                std::cout << "\nChanging storage database amount selected\n";
                break;
            }
            else if(User_Input == '3'){
                std::cout << "\nDeleting storage bandwidth amount selected\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    if(f == 7){ //Interface for choosing which service to modify.
        while(true){
            std::cout << "\n(0) to exit; (1) Buy or refund Cloud Storage; (2) Buy or refund Cloud Database; (3) Buy or refund Cloud Bandwidth.\n";
            std::cin >> User_Input;
            std::cin.ignore(100000000, '\n');

            if(User_Input == '0'){
                std::cout << "\nExiting this menu.\n";
                break;
            }
            if(User_Input == '1'){
                std::cout << "\nCloud Storage menu selected.\n";
                break;
            }
            if(User_Input == '2'){
                std::cout << "\nCloud Database menu selected.\n";
                break;
            }
            if(User_Input == '3'){
                std::cout << "\nCloud Bandwidth selected.\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }
    /*if(f == 8){
        while(true){
            std::cout << "\nSelect a user to modify username\n";
            std::cout << "Select: ";
            int count;
            std::cin >> User_Input;
            //std::cin.ignore(100000000, '\n');
            count = (int)User_Input;

            if(User_Input == 0){
                std::cout << "\nExiting this menu.\n";
                break;
            }
            else if(User_Input == '1'){
                std::cout << "\nChanging username menu selected\n";
                break;
            }
            else if(User_Input == '2'){
                std::cout << "\nChanging password menu selected\n";
                break;
            }
            else if(User_Input == '3'){
                std::cout << "\nDeleting account menu selected\n";
                break;
            }
            else {
                std::cout << "\nIncorrect answer!\n";
            }
        }
    }*/

    if(f != 1 && f != 2 && f != 3 && f != 4 && f != 5 && f != 6 && f != 7){ //For debugging.
        std::cout << "\nException! Wrong function selected for Read_User_Input!\n";
    }
}