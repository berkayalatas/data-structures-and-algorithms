#include<iostream>

struct Node {
	int data;
	Node* prev;
	Node* next;
};


class Doubly_Linked_List 
{
	Node *front;
	Node *end;
	public:
		Doubly_Linked_List()
		{
			front= NULL;
			end = NULL;
		}
		void add_front(int new_data);
	void add_after(Node *n , int new_data);
	void add_before(Node *n ,int new_data);
	void add_end(int new_data );
	void delete_node(Node* n);
	void forward_traverse();
	void backward_traverse();
};

void Doubly_Linked_List:: add_front(int new_data)
{
	Node *temp;
	temp = new Node();
	temp->data = new_data;
	temp->prev = NULL;
	temp->next = front;
	
	if(front==NULL)
		end=temp;
	else
		front->prev = temp;
		
	front = temp;		
}


// IN C 
/*
 Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. 
   
void push(struct Node** head_ref, int new_data) 
{ 
 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
     2. put in the data  
    new_node->data = new_data; 
  
     3. Make next of new node as head and previous as NULL 
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
     4. change prev of head node to new node 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 

     5. move the head to point to the new node 
    (*head_ref) = new_node; 
}

*/

void Doubly_Linked_List :: add_before(Node *n ,int new_data){
	
	Node *temp;
	temp = new Node();
	temp->data = new_data;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;
	
	if(n->prev == NULL)
	front = temp;
}
//C
/*

Given a node as prev_node, insert a new node after the given node 
void insertAfter(struct Node* prev_node, int new_data) 
{ 
    1. check if the given prev_node is NULL 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
     2. allocate new node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
     3. put in the data  
    new_node->data = new_data; 
  
     4. Make next of new node as next of prev_node 
    new_node->next = prev_node->next; 
  
     5. Make the next of prev_node as new_node 
    prev_node->next = new_node; 
  
     6. Make prev_node as previous of new_node 
    new_node->prev = prev_node; 
  
     7. Change previous of new_node's next node 
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
} 

*/

void Doubly_Linked_List ::add_after(Node *n , int new_data)
{
	Node *temp;
	temp = new Node();
	temp->data = new_data;
	temp-> prev = n;
	temp->next = n->next;
	n->next = temp;
	
	if(n->next == NULL)
		end = temp;
}

void Doubly_Linked_List :: add_end(int new_data)
{
	Node *temp;
	temp = new Node();
	temp->data = new_data;
	temp->prev = end;
	temp->next= NULL;
	
	if(end == NULL)
		front = temp;
	else
		end->next = temp;
	end = temp;	
}

/*
void append(struct Node** head_ref, int new_data) 
{ 
     1. allocate node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref;  used in step 5
  
     2. put in the data  
    new_node->data = new_data; 
  
    3. This new node is going to be the last node, so 
          make next of it as NULL
    new_node->next = NULL; 
  
     4. If the Linked List is empty, then make the new 
          node as head 
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
     5. Else traverse till the last node 
    while (last->next != NULL) 
        last = last->next; 
  
     6. Change the next of last node 
    last->next = new_node; 
  
     7. Make last node as previous of new node 
    new_node->prev = last; 
  
    return; 
} 
*/

void Doubly_Linked_List :: delete_node(Node *n)
{
	//if node to be deleted is first node of list
	if(n->prev == NULL) {
		front = n->next ; //the next node will be front of list
		front->prev == NULL;
	}
	//if node to be deleted is last of the list
	else if(n->next == NULL) {
		end = n->prev; // the previous node will be last of list
		end->next = NULL;
	}
	else {
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);
}

//Forward Traversal
void Doubly_Linked_List :: forward_traverse() {
	Node *trav;
	trav = front;
	while(trav != NULL) {
		cout <<trav->data <<endl;
		trav = trav->next;
	}
}

//backward Traversal
void Doubly_linked_list :: backward_traverse() {
	Node *traverse;
	traverse = end;
	
	while(trav != NULL) {
		cout<<trav->data <<endl;
		trav = trav->prev;
	}
}

int main(){
	
	
	return 0;
}






