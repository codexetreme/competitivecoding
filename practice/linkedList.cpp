#include <iostream>
using namespace std;

class Node {
	public:
		int val;
		Node *next;
};

Node *head;


void insertNode(int data){
	Node *a;
	a = new Node();
	a->val = data;
	
	a->next = head;
	head = a;
}

void printNode(Node* head){
	while (head!=NULL){
		cout << head->val<< " ";
		head = head ->next;
	}
}

void popNode(){
	head = head->next;
}

int length(Node *head,int len=0){
	if (head == NULL){
		return len;
	}
	return length(head->next,len+1);
}


int swapNodes(int a, int b){
	Node *aNode = NULL, *aPrevNode = NULL;
	Node *bNode = NULL, *bPrevNode = NULL;
	Node *head1 = head;
	
	while (head1!=NULL){
		if (head1 && head1->val != a){
			aPrevNode = head1;
			aNode = head1->next;
		}
		else if (head1 && head1->val != b){
			bPrevNode = head1;
			bNode = head1->next;
		}
		head1 = head1->next;
	}
	
	if (aNode == NULL || bNode == NULL){
			return -1;
	}
	if (aPrevNode != NULL){
		aPrevNode->next = bNode;
	}
	else {
		head = bNode;
	}
	
	if (bPrevNode != NULL){
		bPrevNode->next = aNode;
	}
	else {
		head = aNode;
	}
	
	bPrevNode->next = aNode;
	
	Node *temp = aNode->next;
	aNode->next = bNode->next;
	bNode->next = temp;
	return 0;
}


int main(){
	
	insertNode(123);
	insertNode(124);
	//popNode();
	insertNode(125);
	insertNode(126);
	insertNode(127);
	insertNode(128);
	insertNode(129);
	insertNode(130);
	printNode(head);
	int p = length(head);
	cout<<p;
	
	swapNodes(124,129);
	cout << "after swap\n";
	printNode(head);
	return 0;
}
