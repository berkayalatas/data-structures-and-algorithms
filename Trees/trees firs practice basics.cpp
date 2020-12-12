#include<iostream>
using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
	
	//val is the key or the value that
	//has to be added to the data part
	Node(int val)
	{
		data = val;
		right = NULL;
		
	}
};

int main(){
	
	// create root
	struct Node*  root = new Node(1);
	
	root->left = new Node(2);
	root -> right = Node (3);
	
	root->left->left = new Node(4);	
	
	return 0;
}
