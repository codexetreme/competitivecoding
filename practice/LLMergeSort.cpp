// Program to mergesort a linked list

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;




class Node {
public:
	int val;
	Node *next;
};

void half(Node*, Node**, Node**);

Node* mergeSortedList(Node*, Node*);

void insert(Node **ref, int data){
	Node *temp = new Node();
	temp->val = data;
	temp->next = (*ref);
	(*ref) = temp;
}


void append(Node **head_ref, Node **tail_ref, int data){
	
	Node *temp = new Node();
	temp->val = data;
	temp->next = NULL;

	if ((*tail_ref) == NULL){
		(*tail_ref) = temp;
		*head_ref = *tail_ref;
	}else {
		(*tail_ref)->next = temp;
		(*tail_ref) = temp;
	}
}

void print(Node *head_ref){

	while (head_ref != NULL){
		cout <<head_ref->val << " ";
		head_ref = head_ref->next;
	}
	cout<<"\n";
}

void mergeSort(Node **ref){

	Node* head = *ref;
	Node* a;
	Node* b;

	if (head == NULL||head->next == NULL){
		return;
	}

	half(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);

	Node* new_head = mergeSortedList(a, b);
	(*ref) = new_head;
}


Node* mergeSortedList(Node *a, Node *b){

	if (a == NULL){
		return (b);
	} else if (b == NULL){
		return (a);
	}


	Node *tail = NULL;
	Node *head = NULL;

	while ((a)!= NULL && (b)!= NULL){

		if ( a->val <= b-> val ){
			append(&head, &tail, a->val);
			a = a->next;
		} 
		else if ( a->val > b-> val ){
			append(&head, &tail, b->val);
			b = b->next;
		}

	}

	while (a!=NULL){
		append(&head, &tail, a->val);
		a = a->next;
	}

	while (b!=NULL){
		append(&head, &tail, b->val);
		b = b->next;
	}

	return head;
}


void half(Node* head, Node **a, Node** b){

	Node* slow = head;
	Node* fast = head->next;

	while (fast !=NULL){
		fast = fast->next;
		if (fast !=NULL){
			fast =  fast->next;
			slow = slow->next;
		}
	}

	(*a) = head;
	(*b) = slow->next;
	slow->next = NULL;

}


int main(){

	Node *head = NULL;
	Node *tail = NULL;

	std::vector<int> v({5,4,2,3,1,6,8,4});
	for (int i =0; i<v.size(); i++ ){
		append (&head, &tail, v[i]);
	}

	print (head);
	mergeSort(&head);
	print (head);


	return 0;
}