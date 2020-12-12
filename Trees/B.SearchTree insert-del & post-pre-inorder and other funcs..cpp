#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode {
	public:
		int value;
		TreeNode * left;
		TreeNode * right;
		
		TreeNode()
		{
			value = 0;
			left = NULL;
			right = NULL;
		}
		TreeNode(int v)
		{
			value = v;
			left = NULL;
			right = NULL;
		}
};

class BST {
	public:
		TreeNode* root;
		
		BST()
		{
			root = NULL;
		}
		
		bool isEmpty()
		{
			if(root == NULL)
				return true;
			else
				return false;	
		}
	
	void insertNode(TreeNode *new_node)
	{
		if(root==NULL)
		{
			root = new_node;
			cout<<"Value inserted as root node!"<<endl;	
		}
		else
		{
			TreeNode *temp = root;
			while(temp!=NULL)
			{
				if(new_node->value == temp->value)	
				{
					cout<<"Value Already exist"<<
					"Insert another value"<<endl;
					return;
				}
				else if((new_node->value < temp->value) && temp->left==NULL)
				{
					temp->left = new_node;
					cout<<"Value Inserted to the left"<<endl;
					break;
				}
				
				else if(new_node->value < temp->value)
				{
					temp = temp->left;
				}
				else if((new_node->value > temp->value) && (temp->right == NULL))
				{
					temp->right = new_node;
					cout<<"Value inserted to the right" <<endl;
					break;
				}
				else
				{
					temp = temp->right ;
				}
						
			}	
		}	
	}	
		
		
	void print2D(TreeNode *r , int space)
	{
		if(r == NULL ) //base case
			return;
		space += SPACE;
		print2D(r->right,space);
		cout<<endl;
		for(int i = SPACE ; i< space ; i++)		
			cout << " ";
		cout << r->value<<"\n";
		print2D(r->left,space); //Progress left child	
	}
	//PREORDER
	void printPreorder(TreeNode* r) //data left right
	{
		if(r == NULL )	
			return;
			
		//first print data of node
		cout << r->value << " ";
		
		//then recur on the left subtree
		printPreorder(r->left);
		
		//recur on the right subtree
		printPreorder(r->right);
				
	}	
	
	//INORDER
	void printInorder(TreeNode* r) //left data right
	{
		if(r == NULL )
			return;
		printInorder(r->left);
		cout << r->value << " ";
		printInorder(r->right);	
	}
		
	//POSTORDER	
	void printPostorder(TreeNode *r) //left right data
	{
		if(r == NULL)
			return;
		printPostorder(r->left);
		printPostorder(r->right);
		cout<< r->value << " ";		
	}
	
	//SEARCH DATA (VALUE-NODE)
	TreeNode* iterativeSearch(int val) 
	{
		if(root == NULL)
			return root;
		else
		{
			TreeNode *temp = root;
				
			while( temp != NULL)
			{
				if(val == temp->value)
					return temp;
					
				else if	(val < temp->value)
					temp = temp->left;
					
				else // val > temp->value
					temp = temp->right;	
			}	
						
			return NULL;				
		}					
	}
	
	int height (TreeNode* r) 
	{
		if(r == NULL )
			return -1;
		else 
		{
			//compute the height of the each subtree	
			int lheight = height(r->left);
			int	rheight = height(r->right);
			
			//use larger one ( left or right )
			if( lheight > rheight )
				return (lheight + 1);
			else 
				return ( rheight+1 );	
			}	
	}
	
	// print nodes at a given level
	void printGivenLevel(TreeNode* r, int level)
	{
		if(r == NULL)
			return;
		else if (level == 0)
			cout << r->value << " ";
		else
		{
			printGivenLevel(r->left, level-1);
			printGivenLevel(r->right, level-1);	
		}	
	}
	
	//Breadth First Search
	void printLevelOrderBFS(TreeNode* r)
	{
		int h = height(r);
		
		for(int i=0 ; i<=h ; i++)
			printGivenLevel(r,i);	
	}
		
	
	//Min Value Node
	TreeNode* minValueNode(TreeNode* node)
	{
		TreeNode* current = node;
	// loop down to find the leftmost lead
		while(current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}
	
	//delete node
	TreeNode* deleteNode(TreeNode* r, int val)
	{
		//base case
		if( r == NULL)
			return NULL;
		
		//if the key to be deleted is smaller than the root's key 
		else if (val < r->value)
			r->left = deleteNode(r->left, val);
		
		//if the key to be deleted is greater than root's key
		else if(val > r->value)
			r->right = deleteNode(r->right,val);
		
		//if the key is same as root's key, then is the node to be deleted
		else // if value matches
		{
			//node with only one child or no child
			if(r->left == NULL)
			{
				TreeNode *temp = r->right;
				delete r;
				return temp;
			}
			//node with only left child
			else if(r->right == NULL)
			{
				TreeNode *temp = r->left;
				delete r;
				return temp;
			}
			else
			{
			    //node with 2 chilren:Get the smallest in the right subtree
			    TreeNode *temp = minValueNode(r->right);
			     
			    //copy the inorder successor's content to this node
			    r->value = temp->value; 
				
				//delete the inorder successor
				r->right = deleteNode(r->right , temp->value);		    
			}
		}
		
		return r;
	}
	

		
};


int main(){
	BST obj;
	int option,val;
	
	do 
	{
		cout << "Choose Operation? "
		<<"Select Option number.Enter 0 to Exit"<< endl;
		
		cout << "1.Insert Node"<<endl;
		cout << "2.Search Node" <<endl;
		cout << "3.Delete Node" <<endl;
		cout << "4.Print BST values" <<endl;
		cout << "5.Print Height of the Tree" << endl;
		cout << "6.Clear Screen" <<endl;
		cout << "0.Exit Program" <<endl; 
		
		cin >> option;
		TreeNode *new_node = new TreeNode();
		
		switch(option)
		{
			case 0:
				break;
			
			//Insert	
			case 1 :
				cout<<"Insert"<<endl;
				cout<<"Enter value of the tree node to insert BST: ";
				cin >> val;
				new_node->value = val;
				obj.insertNode(new_node);
				cout<<endl;
				break;
				
			//Search	
			case 2 :
				cout<<"Search"<<endl;
				cout << "Enter Value of Tree Nde to SEARCH in BST: ";
				cin >> val;
				new_node = obj.iterativeSearch(val); // because return address of searched val
				
				if(new_node != NULL)
					cout << "Value found" <<endl;
				else
					cout << "Value NOT found" << endl;					
				break;
				
			//Delete	
			case 3 :
				cout<<"Delete"<<endl;
				cout << "Enter value of the tree node to DELETE in BST: ";
				cin >> val;
				new_node = obj.iterativeSearch(val);
				
				if(new_node != NULL)
				{
					obj.deleteNode(obj.root, val);
					cout<< "Value Deleted" << endl;
				}
				else
					cout << "Value NOT Found" <<endl;
				break;
			
			//Print and Travers  //preorder, inorder, postorder
			case 4 :
				cout<<"Print and Traverse"<<endl;
				obj.print2D(obj.root,5);
				cout<< "PREORDER: ";
				obj.printPreorder(obj.root);
				cout<<endl;
				cout<< "INORDER: ";
				obj.printInorder(obj.root);
				cout<<endl;
				cout<< "POSTORDER: ";
				obj.printPostorder(obj.root);
				cout << endl;
				obj.printLevelOrderBFS(obj.root);
				cout << endl;
				break;
				
			//Tree Height
			case 5:
				cout<< "Tree Height" << endl;
				cout << "Height: " << obj.height(obj.root) <<endl;
				break;
			
			//Clear the screen		
			case 6 :
				system("cls");
				break;
				
			default:
				cout << "Enter Proper Option Number" << endl;
		}
		
	}while(option !=0 );
	
	
	
	return 0;
}
