#include<iostream> 
#include<cstdlib>
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 


Node *newNode(int data) 
{ 
Node *temp = new Node; 
temp->next = temp; 
temp->data = data; 
} 

void Josephus(int n, int toplam_kisi) 
{ 
 // circular linked list olustur. 
	Node *head = newNode(1); 
	Node *prev = head; 
	for (int i = 2; i <= toplam_kisi; i++) 
	{ 
		prev->next = newNode(i); 
		prev = prev->next; 
	} 
	prev->next = head; 

	Node *ptr1 = head, *ptr2 = head; 
	
	/* while sadece bir node kalana kadar
    linked list*/
	while (ptr1->next != ptr1) 
	{ 
		// n. node bul. 
		int count = 1; 
		while (count != n) 
		{ 
			ptr2 = ptr1; 
			ptr1 = ptr1->next; 
			count++; 
		} 

		/* n. node Sil */
		ptr2->next = ptr1->next; 
		free(ptr1); 
		ptr1 = ptr2->next; 
	} 

	printf ("Sona kalan %d. asker",ptr1->data); 
} 

int main() 
{ 
	int n,m;
	cout<<"Toplam Kisi Sayisi: ";
	cin>>n;
	cout<<"Her Seferinde Daireden n.cikacak Kisi: n'yi giriniz :";
	cin>>m; 
	Josephus(m, n); 
	return 0; 
} 
