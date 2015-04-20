#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}

// apending
void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertBehindCurrent(struct Node **head, int n) {
	Node *newNode = new Node;
	Node *list, *last, *sovhead;

	sovhead=*head;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;

	list = sovhead;
	while(list) {
		last = list;
		list = list->next;
		if (list==sovhead) break;
	}
	last->next = newNode;
}


struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
		if (cur==head) break;		// because circular
	}
	cout << "No Node " << n << " in list.\n";
}


bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;

			delete ptrDel;
			return true;

		}
		cur = cur->next;
		if (cur==*head) break;		// b\c circular
	}
	return false;
}




void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
		if (list==head) break;
	}
	cout << endl;
	cout << endl;
}

void makeItCircular(struct Node *head) {
	Node *list = head;
	Node *last;

	while(list) {
		last = list;
		list = list->next;
	}
	last->next = head;
}

int main() 
{
	struct Node *newHead;
	struct Node *head = new Node;
	
	initNode(head,10);
	cout<<"display(head)"<<endl;
	display(head);

	cout<<"addNode(head,20)"<<endl;
	addNode(head,20);
	display(head);

	cout<<"addNode(head,30)"<<endl;
	addNode(head,30);
	cout<<"display(head)"<<endl;
	display(head);

	cout<<"addNode(head,35)"<<endl;
	addNode(head,35);
	cout<<"display(head)"<<endl;
	display(head);

	cout<<"addNode(head,40)"<<endl;
	addNode(head,40);

	cout<<"makeItCircular(head)"<<endl;
	makeItCircular(head);
	cout<<"display(head)"<<endl;
	display(head);

	cout<<"insertBehindCurrent(&head,5)"<<endl;
	insertBehindCurrent(&head,5);
	cout<<"display(head)"<<endl;
	display(head);

	int numDel = 30;
	Node *ptrDelete = searchNode(head,numDel);

	cout<<"find and deleting " << ptrDelete->data<<endl;
	if(deleteNode(&head,ptrDelete)) 
		cout << "Node "<< numDel << " deleted!\n";
	display(head);

	return 0;
}