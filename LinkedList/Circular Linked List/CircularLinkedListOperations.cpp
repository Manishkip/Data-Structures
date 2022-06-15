//Circular linked list program creation, display, insertion, deletion, traversal

//header files
#include<stdio.h>
#include<stdlib.h>

//defining data type
struct node{
	int data;
	struct node *next;
}*tail;

//function creates a circular linked list using a tail pointer
void createCLL(){
	int choice = 1;
	struct node *newnode;
	tail = 0;
	while(choice){
		newnode = (struct node*)malloc(sizeof(struct node)); //newnode is created
		printf("Enter data : ");
		scanf("%d", &newnode->data);
		newnode->next = 0;
		if(tail==0){          //means list is empty
			tail = newnode;
			tail->next = newnode;
		}
		else{				 //newnode points to tail->next and tail points to newnode
			newnode->next = tail->next;
			tail->next = newnode;
			tail = newnode;
		}
		printf("Do you want to continue (0,1) : "); //Asking the user if he wants to continue the creation of the 
		scanf("%d", &choice);
	}
//	tail->next->data;
}

//function gets the length of the circular linked list
int getLength(){
	struct node *temp = tail->next;
	int count = 0;
	if(tail==0){
		printf("List is empty!");
	}
	else{
		do{
			count++;
			temp = temp->next;
		}while(temp != tail->next);
	}
//	printf("\nThe length od the linked list is %d ", count);
	return count;
}

//function inserts a node at the beginning
void insertatBeg(){
	struct node *newnode;
	newnode =(struct node*)malloc(sizeof(struct node)); //newnode creation
	printf("Element to be inserted at the beginning\n");
	printf("Enter the data : ");                        //taking user input
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if(tail==0){          //means list is empty so tail points newnode and stores address of newnode
		tail = newnode;
		tail->next = newnode;
	}
	else{                  //newnode stores the address of first node and tail stores address of newnode
		newnode->next = tail->next;
		tail->next = newnode;
	}
}

//function inserts a node at the end
void insertatEnd(){
	struct node *newnode;
	newnode =(struct node*)malloc(sizeof(struct node)); //newnode creation
	printf("Element to be inserted at the end\n");
	printf("Enter the data : ");                        //taking user input
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if(tail==0){          //means list is empty so tail points newnode and stores address of newnode
		tail = newnode;
		tail->next = newnode;
	}
	else{                  //newnode stores the address of first node and tail points to newnode
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
}

//function inserts a node at a specified position
void insertatPos(){
	struct node *newnode, *temp;  //two pointers declared
	int pos, i = 1, l;
	printf("\nNode to be inserted at a given position \n");
	printf("Enter the position : ");   //taking user input
	scanf("%d", &pos);
	l  = getLength();             //variable l stores the length of the list
	if(pos < 0 || pos > l){        //condition for valid position input
		printf("Invalid Position! ");
	}
	else if(pos == 1){            //means at the first
		insertatBeg();
	}
	else{
		newnode = (struct node*)malloc(sizeof(struct node));    //newnode is created
		printf("Enter the data : ");                          //taking user input
		scanf("%d", &newnode->data); 
		newnode->next = 0;
		temp = tail->next;                     //temp points to first node
		while(i < pos - 1){          //condition to traverse at the given position
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;    //newnode stores the address of temp->next 
		temp->next = newnode;        //temp points to newnode
	}
}

//Deletion from Circualar Linked List

//function deletes a node from the beginning
void delfromBeg(){
	struct node *temp = tail->next;   //temp pointer points to first node

	if(tail==0){    
		printf("List is empty!");
	}
	else if(temp->next == temp){      //means only one node is present
		tail = 0;
		free(temp);
	} 
	else{                      
		tail->next = temp->next;   //tail pointer stores address of 2nd node
		free(temp);
	}
	printf("\nAfter deletion of first node, the list is : ");
}

//function deletes a node from the end
void delfromEnd(){
	struct node *current, *previous;  //two pointer nodes declared
	current = tail->next;              //current points to first node
	if(tail==0){
		printf("List is empty!");
	}
	else if(current->next == current){    //means only one node is present
		tail = 0;
		free(current);
	}
	else{
		while(current->next != tail->next){       //condition
			previous = current;
			current = current->next;
		}
		previous->next = tail->next;         //previous node stores address of first node
		tail = previous;                     //tail points to previous node
		free(current);                      //last node is deleted
	}
	printf("\nAfter deletion of the last node, the list is : ");
	
}

//function deletes a node from a specified position
void delfromPos(){
	struct node *current, *nextnode;   //two nodes as a pointer declared
	int pos, i = 1, l;                 
	l = getLength();				 // variable l stores the length of the list
	current = tail->next;            //current points to first node
	printf("Enter the position where you want to delete the node : ");
	scanf("%d", &pos);              //taking user input
	if(pos < 0 || pos > l){         //condition for valid position input
		printf("Invalid Position! ");
	}
	else if(pos == 1){             //means at the beginning
		delfromBeg();              //delfromBeg function is called
	} 
	else{
		while(i < pos -1){         //condition to traverse one node before the specified position
			current = current->next;
			i++;
		}
		nextnode = current->next;     //nextnode stores the address of the node to be deleted
		current->next = nextnode->next;  //current stores the address of the node next to nextnode;
		free(nextnode);               //nextnode is deleted using free function in c
	} 
	printf("\nAfter deletion of node from the given position, the list is : ");
}

//functions reverses the linked list
void reverse(){
	struct node *current, *prev, *nextnode;  // three node pointers declared
	current = tail->next;                    //current points to first node
	nextnode = current->next;
	if(tail==0){
		printf("List is empty!");
	}
	else{
		while(current != tail){        //condition
			prev = current;            //prev points to current
			current = nextnode;        //since nextnode points to current->next
			nextnode = current->next;   //before updating the link nextnode points to next node
			current->next = prev;        
		}
		nextnode->next = tail;        //after the loop the first and the last nodes are updated
		tail = nextnode;
	}
	printf("\nThe reverse linked list is : ");
}

//function displays the elements of the linked list
void display(){
	struct node *temp = tail->next;
	if(tail==0){    
		printf("List is empty!");
	}
	else{
		while(temp->next != tail->next){ //condition
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);        //since temp pointer stops before the tail pointer, the last element is printed at the end
	}
}
//Another method to print the list
void printList(){
	struct node *temp = tail->next;
	if(tail==0){
		printf("List is empty!");
	}
//	else{
//		temp = tail->next;
//	}
	do{                         
		printf("%d ", temp->data);
		temp = temp->next;
	}while(temp != tail->next);  //condition
}

//main function
int main(){
	createCLL();
//	display();
//	insertatBeg();
//	insertatEnd();
    printList();
//	insertatPos();
//	delfromBeg();
	delfromEnd();
//	delfromPos();
	printList();
//	display();
//	getLength();
	
	return 0;
}
