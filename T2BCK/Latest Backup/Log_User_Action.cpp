#include "Log_User_Action.h"

void Log_User_Action(std::fstream& Log){

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    Log << Counter << " " << std::ctime(&end_time);
    Log << "Program initialization." << " " << std::endl << "------------------------------------------------" << std::endl;
    Counter++;
}
void Log_User_Action(const std::string& Logged_Text, std::fstream& Log){
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    Log << Counter << " " << std::ctime(&end_time);
    Log << Logged_Text << " " << std::endl << "------------------------------------------------" << std::endl;
    Counter++;
}

/*void Log_User_Action(std::fstream& Log){
    Log.open("Log.txt", std::ios::out);
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    Log << asctime(timeinfo);
    int i = 0;
    Log << "Some crap here: " << i;
    i++;
    Log.close();
}*/

void Read_Log(std::fstream& Log){
    Log.open("Log.txt", std::ios::in);

    std::string Whole_Log;

    int i = 0;
    while(getline(Log, Whole_Log)){
        std::cout << i << " " << Whole_Log << std::endl;
        i++;
    }

    Log.close();
}