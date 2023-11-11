
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
class linkedlist
{
	Node* head;
public:
	linkedlist()
	{
		head = NULL;
	}
	void removeDuplicates()
	{
		Node* s1 = head; Node* s2 = head->next;	Node* temp;

		int flag=0; //variable to check weather the  node is deleted or not 
		
		if (head == NULL)
		{
			cout << "linklist not found" << endl;
		}
		else {
			while (s2->next != NULL) {

				if (s1->data == s2->data) {
					temp = s2;
					s2 = s2->next;
					s1->next = temp->next;
					temp->next = NULL;
					delete temp;
					flag = 1;                    //deletion is done 
				}
				else            //if deletion not done then move forward
				{
					s1 = s1->next;
					s2 = s2->next;
				}
			}
		}
	}
	void push(int v)
	{
		Node* n = new Node;
		n->data = v;
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			Node* s=head;
			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = n;


		}
	}
		void printList()
		{
			Node* n = head;
			while ( n!= NULL) {
				cout << n->data << " -> ";
				n = n->next;
			}
		}
	};

int main()
{
	linkedlist l1;
	l1.push(7);
	l1.push(17);
	l1.push(17);
	l1.push(17);
	l1.push(47);
	l1.push(57);
	l1.push(67);
	l1.push(77);
	l1.push(87);
	l1.push(97);
	l1.push(97);
	l1.push(100);
	cout << "LINKED LIST BEFORE DELETION OF SAME NODES " << endl;
	l1.printList();
	l1.removeDuplicates();
	cout << endl;
	cout << "LINKED LIST AFTER DELETION OF SAME NODES " << endl;
	l1.printList();
	cout << endl;
	return 0;
}
