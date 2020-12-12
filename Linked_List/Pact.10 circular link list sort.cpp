// C++ program for sorted insert 
// in circular linked list 
#include <bits/stdc++.h> 
using namespace std; 
  
/* structure for a node */
class Node  
{  
    public: 
    int data;  
    Node *next;  
};

void sortedInsert(Node** head_ref, Node* new_node)
{
	Node* current = *head_ref;
	
	if(current == NULL) 
	{
		new_node->next = new_node;
		*head_ref = new_node;
	}
	
	else if(current->data >= new_node->data){
		while(current->next != *head_ref)
			current = current->next;
		current->next = new_node;
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	
	else {
		/* Locate the node before the point of insertion */
		while(current->next != *head_ref && current->next->data < new_node->data)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;	
	}
}
	/* Function to print nodes in a given linked list */
void printList(Node *start)  
{  
    Node *temp;  
      
    if(start != NULL)  
    {  
        temp = start;  
        do {  
        cout<<temp->data<<" ";  
        temp = temp->next;  
        } while(temp != start);  
    }  
}  
  
/* Driver code */
int main()  
{  
    int arr[] = {12, 56, 2, 11, 1, 90};  
    int list_size, i;  
      
    /* start with empty linked list */
    Node *start = NULL;  
    Node *temp;  
      
    /* Create linked list from the array arr[].  
        Created linked list will be 1->2->11->12->56->90 */
    for (i = 0; i< 6; i++)  
    {  
        temp = new Node(); 
        temp->data = arr[i];  
        sortedInsert(&start, temp);  
    }  
      
    printList(start);  
      
    return 0;  
}  
  


