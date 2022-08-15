#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
 
    /* Function to reverse the linked list */
    void reverse()
    {
        
        Node* current = head;
       
        std::vector<int> element ;
 
        while (current != NULL) {
            element.push_back(current->data);
            current = current->next;
         }
         
        
         current = head;
         int i=element.size()-1;
         
        while (current != NULL) {
            current->data = element[i--];
            current = current->next;
         } 
        
    }
 
   /* Function to print linked list */
  
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " "; temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
/* Driver code*/
int main()
{
   
    LinkedList ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);
    ll.push(40);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
