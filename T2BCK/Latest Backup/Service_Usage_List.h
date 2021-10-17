/*
#pragma once

#include "Server_Service.h"
#include "User_List.h"
#include "User.h"

class Service_Usage_List{ //Struct for User_List. This is a linked list which moves in only one direction, hence it has an initial point and a terminal point. Here we declare the head (initial) point of our list and the tail (terminal) point of our list.
    User* head = nullptr; //Initialize head pointer to nullptr
    User* tail = nullptr; //Initialize tail pointer to nullptr

    int length() const { //Function for counting the length of a linked list.
        int length = 0; //Declare and initialize length to 0, so that we don't access randomly allocated memory.
        User* current; //Declare a pointer of user class.
        current = head; //Initialize pointer to the initial (head) element in the list.
        while(current != nullptr){ //While current pointer element does not equal to nullptr (0) keep counting.
            current = current->next; //Set current element to the next element in the linked list.
            length++; //Increment length variable.
        }
        return length; //Once counting is finished return the value of length (total amount of elements in a linked list).
    }
};*/
