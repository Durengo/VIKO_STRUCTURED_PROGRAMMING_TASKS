#pragma once

//This module is going to interact with the user (acquire user input) and provide the user with user-friendliness.
//This module will interact with all other modules by calling their functions - character user interface (CUI).

#include <iostream> //Include basic printing from standard library.
#include <string>
#include <iomanip>
#include <fstream>

#include "Logging.h"

#define C Console

class Console {
private:
  //Logging* logfilePTR;

public:

  //Console(Logging* PTR);
  //Logging* logfilePTR = new Logging;
//  std::fstream* log{};
//
//  Console();
//
//  void getLogFromLogging(std::fstream* log);

  //Printing to Console functions:
  static void PTC(const std::string &Print); //Function prints 1 input to console

  static void
  PTC(const std::string &Print1, const std::string &Print2); //Function can print 2 different outputs to console

  static void PTC(const std::string &Print1, int count,
                  const std::string &Print2); //Function that cna print a string>an int>a string.

  static void PTC(const std::string &Print1, int count,
                  const std::string &Print2, const std::string &Print3,
                  const std::string &Print4); //Function that prints 4 strings and an int in this order: sisss

  static void PTC(const std::string &Print1, const std::string &Print2,
                  const std::string &Print3); //Function that prints 3 strings.

  static void PTC(const std::string &Print1, const std::string &Print2,
                  const std::string &Print3, const std::string &Print4,
                  const std::string &Print5); //Function that prints 5 strings.

  static void PTC(const std::string &Print1, int count1, const std::string &Print2, int count2,
                  const std::string &Print3); //Function that prints 3 strings and 2 ints in such an order: string, int, string, int, string.

  static void PTC(const std::string &Print1, const std::string &Print2, const std::string &Print3, int count,
                  const std::string &Print4); // Function that prints 4 strings and an int in this order: sssis

  static void PTC(int n); //Function that prints an int to console.

  static void PTC(float float1); //Function for printing float values.

  static void
  PTC(float float1, int setPrecision); //Function for printing float values and setting decimal point precision.

  static void PTC(float float1, int setPrecision, const std::string &Print1);

  static void PrintUserWithCount(int Count,
                                 const std::string &Print); //Function to be used with User_List Module to loop through each user and count them.

  //Getting Input from user functions:
  static void GIBS(std::string &string); //Function for getting a string input from the user.

  static int Get_Input_By_INT(); //Function can get input from user - only by INT.

  static int Get_Input_By_INT(int min,
                              int max); //Function can get input from user - only by INT and only withing min and max parameters.

  //Printing to console and getting input from user functions:
  static int Get_Input_Yes_Or_No(); //Function for getting yes or no from user input.
};
