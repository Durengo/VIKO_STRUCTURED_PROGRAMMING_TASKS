#include <iostream>

#include "Node.h"

void CreateNewUser(){

}

int main(){

    Node* head = nullptr;
    Append_Node(&head, 1);

    Print_Nodes(head);

    Append_Node(&head, 2);
    Append_Node(&head, 3);
    Append_Node(&head, 4);
    Append_Node(&head, 5);

    Print_Nodes(head);

    Delete_Node(&head, 3);

    Print_Nodes(head);

    std::cout << "Total ammount of nodes: "<< Count_Nodes(head) << std::endl;

    Delete_All_Nodes(&head);

    return 0;
}