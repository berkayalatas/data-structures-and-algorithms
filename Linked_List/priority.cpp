#include<iostream> 
#include<cstdlib>
//ilk giren ilk cikar. 8 elemandan ilk 4'ü cikar.
using namespace std; 

typedef struct node 
{ 
	int data; 

	int priority; 

	struct node* next; 

} Node; 

//function to create new node
Node* newNode(int new_data, int p) 
{ 
	Node* temp = (Node*)malloc(sizeof(Node)); 
	temp->data = new_data; 
	temp->priority = p; 
	temp->next = NULL; 

	return temp; 
} 

//return the value at head
int peek(Node** head) 
{ 
	return (*head)->data; 
} 

//removes the element with the
// highest priority form the list
void pop(Node** head) 
{ 
	Node* temp = *head; 
	(*head) = (*head)->next; 
	free(temp); 
} 

void push(Node** head, int d, int p) 
{ 
	Node* start = (*head); 

   // Create new Node 
	Node* temp = newNode(d, p); 
	
// Special Case: The head of list has  
    // lesser priority than new node. So  
    // insert newnode before head node  
    // and change head node. 
	if ((*head)->priority > p) 
	{ 
		
		temp->next = *head; 
		(*head) = temp; 
	} 
	else
	{ 
		// Traverse the list and find a 
        // position to insert new node 
		while (start->next != NULL && 
			start->next->priority < p) 
		{ 
			start = start->next; 
		} 
// Either at the ends of the list 
        // or at required position 
		temp->next = start->next; 
		start->next = temp; 
	} 
} 
// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
	return (*head) == NULL; 
} 

int main() 
{ 
	int a,b,c,d,e,f,g,h;
	
	cout<<"8 rakam giriniz: "<<endl;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	cin>>f;
	cin>>g;
	cin>>h;
	
	Node* pq = newNode(a, e);
	push(&pq, b, f);
	push(&pq, c, g);
	push(&pq, d, h);
	
	/*
		// Create a Priority Queue 
	    // 7->4->5->6 
	    
	    Node* pq = newNode(4, 1); 
	    push(&pq, 5, 2); 
	    push(&pq, 6, 3); 
	    push(&pq, 7, 0); 
	*/

	while (!isEmpty(&pq)) 
	{ 
		cout << " " << peek(&pq); 
		pop(&pq); 
	} 
	return 0; 
} 
