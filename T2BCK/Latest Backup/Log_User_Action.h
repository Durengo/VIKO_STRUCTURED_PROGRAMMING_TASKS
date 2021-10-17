#pragma once

#include <iostream>
#include <chrono>
#include <fstream>
#include <ctime>

static int Counter = 0;

void Log_User_Action(std::fstream& Log);
void Log_User_Action(const std::string& Logged_Text, std::fstream& Log);

//void Log_User_Action(std::fstream& Log);

void Read_Log(std::fstream& Log);