#pragma once

#include <iostream>
#include <string>
#include "User_List.h"

class Console{

public:
static void PTC(const std::string& Print);
static void PTC(const std::string& Print1, const std::string& Print2);

static int Get_Input_By_INT();
static int Get_Input_By_INT(int min, int max);

static int Get_Input_Yes_Or_No();
//int Login_Prompt(User_List* list);
};
