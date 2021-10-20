cmake_minimum_required(VERSION 3.20)
project(structured-programming-tasks-Durengo)

set(CMAKE_CXX_STANDARD 11)

add_executable(task_1 "TASK_1/TASK_1.cpp")
add_executable(T2 TASK_2/TASK_2.cpp TASK_2/User_List.cpp TASK_2/User.cpp TASK_2/Data_Manager.cpp TASK_2/Console.cpp TASK_2/Logging.cpp TASK_2/Test_Unit.cpp TASK_2/Service_Manager.cpp TASK_2/Interface.cpp)
add_executable(task_3 "TASK_3/TASK_3.cpp")
#add_executable(task_4 "TASK_4.cpp") #reserved for future task


#libraries for linux compilers!!!!!!
#must disable this if not on linux!!
target_precompile_headers(T2
        PUBLIC
        /usr/include/c++/9/iostream
        /usr/include/c++/9/iomanip
        /usr/include/c++/9/string
        /usr/include/c++/9/chrono
        /usr/include/c++/9/fstream
        /usr/include/c++/9/ctime
        /usr/include/c++/9/cstdlib
        )