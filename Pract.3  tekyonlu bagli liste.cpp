#include <bits/stdc++.h> 
using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

void push(Node** head_ref, int new_data){
	
	//allocate node
	Node* new_node = new Node();
	
	//put in the data
	new_node->data = new_data;
	
	//make next of new node as head
	new_node->next = (*head_ref);
	
	//move to head to point to new node
	(*head_ref) = new_node;
	
}

// Given a node prev_node, insert a  
// new node after the given   
// prev_node 
void insertAfter(Node* prev_node, int new_data){
	
	if(prev_node == NULL) {
		cout<<"The given previous node cannot be NULL";
		return;
	}
	
	//allocate new node
	Node* new_node = new Node();
	
	//put in data
	new_node->data = new_data;
	
	//make next of new node as next of prev_node
	new_node->next = prev_node->next;
	
	prev_node->next = new_node;
}

// Given a reference (pointer to pointer) to the head   
// of a list and an int, appends a new node at the end  

void append(Node** head_ref, int new_data){
	//allocate node
	Node* new_node = new Node();
	
	Node *last = *head_ref;
	
	//put in data
	new_node->data = new_data;
	
	//it will be last node
	new_node->next = NULL;
	
	//if list is empty make new node as head
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	
	//else traverse till the last node
	while(last->next != NULL)
		last = last->next;
	
	//change the next of last node
	last->next = new_node;
	return;
	
}
void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  


int main(){
	/* Start with the empty list */
    Node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    append(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    push(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    push(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    append(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insertAfter(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    printList(head);  
 



	return 0;
}






