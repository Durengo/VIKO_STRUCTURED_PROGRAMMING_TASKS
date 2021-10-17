#pragma once

#include <iostream>
#include "User.h"
//#include "Console.h"

/*This "Read_User_Input" header file includes the Read_User_Input which will be used to read all user input and provide the needed feedback for the user to successfully operate the program.
 * There is only one function which takes User_Input for the main character to interact with and takes in an <int> f - this <int> dictates which <if> statement to execute:
 * int f = 1 - Basic I/O for yes or no.
 * int f = 2 - Log in as (1) Admin or (2) Create new account - this if runs only once (when the program starts) so that the user is prompted to create a new user
 * int f = 3 - Log in as (1) Admin or (2) User - this if runs all the time after the user has created a new account.*/

void Read_User_Input(char& User_Input, int f);