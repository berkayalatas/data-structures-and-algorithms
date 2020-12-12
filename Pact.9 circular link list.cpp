#include<iostream>
using namespace std; 


// C++ program to implement  
// the above approach  
#include <bits/stdc++.h> 
using namespace std; 
  
/* structure for a node */
class Node  
{  
    public: 
    int data;  
    Node *next;  
}; 

void push(Node **head_ref , int data)
{
	Node *ptr = new Node();
	Node *temp = *head_ref;
	ptr->data = data;
	ptr->next = *head_ref;
	
	/* If linked list is not NULL then  
    set the next of last node */
	
	if(*head_ref != NULL) {
		while(temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr;	
	}
	else
	 	ptr->next = ptr; //for the first node
	
	*head_ref = ptr1; 	
	
	
}


void printList(Node *head) {
	
	 Node *temp = head;
	
	//if link list not empty
	if(head != NULL)
	{
		do{
			cout << temp->data << endl;
			temp = temp->next;
			
		}while(temp != head);
	}
	
}




int main()  
{  
    /* Initialize lists as empty */
    Node *head = NULL;  
  
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 2);  
    push(&head, 11);  
  
    cout << "Contents of Circular Linked List\n ";  
    printList(head);  
  
    return 0;  
} 
