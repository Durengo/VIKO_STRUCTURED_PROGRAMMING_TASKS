#pragma once

#include <iostream>
#include "Console.h"
#include "User_List.h"
#include "Data_Manager.h"
#include "Service_Manager.h"
#include "Interface.h"

//Test file for testing all modules and their functions.

static int Global_Tick = 0;
//Global variable for running tests.
//Global_Tick = 0 - Run nothing;
//Global_Tick = 1 - Console Module test;
//Global_Tick = 2 - User and User List test;
//Global_Tick = 3 - Data Management test;
//Global_Tick = 4 - Service Manager test;
//Global_Tick = 5 - Interface test;
//Global_Tick = 6 - General Login/Logout test;

void setGlobalTick(int T);

void Console_Test();

void User_List_and_User_Test();

void Data_Management_Test();

void Service_Manager_Test();

void Interface_Test();

void Login_Logout_Test();