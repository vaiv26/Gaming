//
//  main.cpp
//  LinkedLists
//
//  Created by vaibhav kumar on 9/20/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    int data;
    Node* next;
};
void insert(int newdata,Node** head);
void deleteNode(int position,Node** head);
void printList(Node* head);

int main() {
    Node* head = nullptr;
    
    insert(3, &head);
    insert(4, &head);
    insert(5, &head);
    insert(6, &head);
    insert(7, &head);
    insert(8, &head);
    
    cout<<"The list:";
    printList(head);
    cout<<endl;
    
    cout<<"Deletion of a node"<<endl;
    deleteNode(5,&head);
    cout<<"The list after deletion:";
    printList(head);
    cout<<endl;
    return 0;
}

void insert(int newdata,struct Node** head)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = *head;
    *head = newnode;
}

void deleteNode(int position,struct Node** head)
{
    if(*head == nullptr)
        return;
    
    struct Node* temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    
    for(int i = 0; temp != nullptr && i < position-1; i++)
    {
        temp = temp->next;
    }
    if(temp == nullptr||temp->next == nullptr)
        return;
    
    struct Node* currnode = temp->next->next;
    free(temp->next);
    temp->next = currnode;
}

void printList(struct Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<",";
        head = head->next;
    }
}
