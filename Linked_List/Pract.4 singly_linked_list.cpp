// A complete working C++ program to 
// demonstrate deletion in singly  
// linked list with class  
#include <bits/stdc++.h> 
using namespace std; 

class Node {
	public:
		int data;
		Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next =(*head_ref);
	(*head_ref) = new_node;
}
  
// Given a reference (pointer to pointer) 
// to the head of a list and a key, deletes 
// the first occurrence of key in linked list  
void deleteNode(Node** head_ref , int key)
{
	//store head node
	Node* temp = *head_ref;
	Node* prev = NULL;
	
	// If head node itself holds 
    // the key to be deleted 
    while(temp !=NULL && temp->data !=key)
    {
    	prev = temp;
    	temp = temp->next;
	}
	// If key was not present in linked list 
	if(temp == NULL)
		return;
		
	// Unlink the node from linked list 
	prev->next = temp->next;

	  // Free memory 
    delete temp; 		
}

void printList(Node* node)
{
	while(node != NULL) {
		cout << node->data<< endl;
		node = node->next;
	}
}


int main() {
	
	Node* head = NULL;
	
	push(&head,7);
	push(&head,1);
	push(&head,8);
	push(&head,3);
	push(&head,2);
	
	puts("Created Linked List ");
	printList(head);
	
	deleteNode(&head,1);
	puts("\nLinked lists after deletion of 1");
	
	printList(head);
	
	return 0;
}



