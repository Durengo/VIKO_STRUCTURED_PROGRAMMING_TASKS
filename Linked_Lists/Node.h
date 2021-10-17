#pragma once

class Node{
public:
    int data;
    Node* next;

    Node()
    : data(0), next(nullptr)
    {
        std::cout << "\nConstructor has been called!\n" << std::endl;
    };
    ~Node()
    {
        std::cout << "\nDeconstruct has been called!\n" << std::endl;
    }


};

void Append_Node(Node** head_ref, int new_data)
{

    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr)
        last = last->next;

    last->next = new_node;
}

void Print_Nodes(Node *node)
{
    while (node != nullptr)
    {
        std::cout<<" "<<node->data;
        node = node->next;
    }
}

void Delete_Node(Node **head_ref, int position)
{
    if (*head_ref == nullptr)
        return;
    Node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i = 0; temp != nullptr && i < position - 1; i++)
        temp = temp->next;
    if (temp == nullptr || temp->next == nullptr)
        return;
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void Delete_All_Nodes(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete(current);
        current = next;
    }
    *head_ref = nullptr;
    std::cout << "\n\nAll nodes have been deleted.\n\n";
}

int Count_Nodes(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != nullptr)
    {
        count++;
        std::cout << current->data;
        current = current->next;
    }
    return count;
}

/*
void Delete_Node(Node** head_ref, int key)
{

    Node* temp = *head_ref;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    else
    {
        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;
        delete temp;
    }
}*/
