// Insertion in linked list c++
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data){
    if(prev_node == NULL){
        cout<<"previous node cannot be null";
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node **head_ref, int new_data){
    Node * new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void PrintList(Node *node){
    while(node != NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    append(&head, 6);
    Push(&head, 7);
    Push(&head, 1);
    append(&head,4);
    insertAfter(head->next, 8);
    
    cout<<"The created Linkedlist is : ";
    PrintList(head);

    return 0;
}
