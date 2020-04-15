// detect loop in linkedList

#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>



using namespace std;

class Node {

public:
	int val;
	Node *next;
};

void append(Node** head, Node** tail, int data){


	Node* temp = new Node();
	temp->val = data;
	temp->next = NULL;


	if ((*tail) == NULL){
		(*tail) = temp;
		(*head) = (*tail);
	}
	else {
		(*tail)->next = temp;
		(*tail) = temp;
	}
}


void insert(Node **head, int data){
	Node* temp = new Node();
	temp->val = data;
	temp->next = NULL;

	if ((*head)== NULL){
		(*head) = temp;
	}
	else {
		temp->next = *head;
		(*head) = temp;
	}
}

void print (Node *head){
	while (head){
		cout <<head-> val<<" ";
		head = head->next;
	}

	cout <<"\n";
}




Node* detectLoop(Node *head){
	Node* slow = head;
	Node* fast = head;


	while (slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast){
			cout<<"loop Found\n";
			return slow;
		}
	}

	cout<<"loop NOT Found\n";
	return NULL;
}


Node* detectLoopViaHashing(Node *head){
	unordered_set<Node*> visited;

	while (true){
		if (visited.find(head) == visited.end()){
			visited.insert (head);
		}else {
			cout <<"loop Found";
			return head;
		}
		head = head->next;
	}
}

void removeLoop(Node *head){

	Node* loopNode = detectLoop(head);
	if (loopNode){
		cout<<loopNode->val;
		Node* ptr = loopNode;

		while (ptr->next != loopNode){
			ptr = ptr->next;
		}
		cout<<"removed "<<ptr->val<<endl;
		ptr->next = NULL;
	}
}

int main (){
	Node *head = NULL;
	Node *tail = NULL;
	std::vector<int> v({1,2,3,4,5,6,7});
	for (auto i : v){
		append(&head, &tail, i);
		// insert(&head, i);
	}
	// cout <<head->next->val<<endl;
	print (head);
	head->next->next->next->next->next->next = head->next->next;
	// detectLoop(head);
	// detectLoopViaHashing(head);
	removeLoop(head);
	print (head);
	return 0;
}
