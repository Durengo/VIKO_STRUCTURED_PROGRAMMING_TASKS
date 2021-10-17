#include <iostream>

#include "User.h"
#include "Linked_List.h"

int main(){

    auto* UserList = new User_List;

    Create_User(UserList, "admin", "admin");
    Create_User(UserList, "durengo", "durengo");

    Display_List(UserList->head);

    Create_User(UserList, "dummy", "dummy");
    Create_User(UserList, "dummy2", "dummy");
    Create_User(UserList, "dummy3", "dummy");
    Create_User(UserList, "dummy4", "dummy");
    Create_User(UserList, "dummy5", "dummy");

    Display_List(UserList->head);

    if(UserLogin(UserList->head)){
        std::cout << "\nbool true\n";
    }

    std::cout << "\nwsdawdwadwadawdaw\n";

    std::cout << UserList->length();

/*
    deleteTail(list);

    Display_List(list->head);

    deleteTail(list);

    Display_List(list->head);*/

/*
    deleteHead(list);

    Display_List(list->head);

    deleteHead(list);

    Display_List(list->head);
*/


    deleteByPos(UserList, 2);


    Display_List(UserList->head);
    deleteByPos(UserList, 3);

    Display_List(UserList->head);
    //while(!UserLogin(list->head));

    //Delete_User_By_Unique_ID(list, list->head, 3);

    //Display_List(list->head);

    return 0;
}