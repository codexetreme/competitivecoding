#include <iostream>

using namespace std;


class Node {

public:
	int val;
	Node *next;
};

void insert(Node **head_ref, int data){

	Node *temp = new Node();
	temp->val  = data;
	temp->next = (*head_ref);
	(*head_ref) = temp;

}
void print(Node *head_ref){

	while (head_ref != NULL){
		cout <<head_ref->val << " ";
		head_ref = head_ref->next;
	}
	cout<<"\n";
}


Node* reverse(Node *ref){


	Node *prev = NULL;
	Node *curr = ref;

	Node *next = NULL;


	while (curr){

		next = curr->next;

		curr->next = prev;
		
		prev = curr;
		curr = next;
		
	}

	return prev;	

}



int main(int argc, char const *argv[])
{
	
	Node *head = NULL;

	insert (&head, 123);
	insert (&head, 124);
	insert (&head, 125);
	insert (&head, 126);
	insert (&head, 127);
	insert (&head, 128);
	insert (&head, 129);

	print (head);

	auto p = reverse(head);

	print (p);

	return 0;
}