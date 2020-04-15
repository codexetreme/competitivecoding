#include<iostream>
#include<stack>

using namespace std;

class Queue{
private:
	stack<int> s1;
	stack<int> s2;
public:
	Queue();
	void enQu(int);
	void deQu();
	void printTop();

};


Queue::Queue(){

};

void Queue::enQu(int data){
	while (!s1.empty()){
		int temp = s1.top();
		s2.push(temp);
		s1.pop();
	}
	s1.push(data);
	while (!s2.empty()){
		int temp = s2.top();
		s1.push(temp);
		s2.pop();
	}
}

void Queue::printTop(){
	if (!s1.empty()){

		cout<<s1.top()<<"\n";
	}

}


void Queue::deQu(){


	if (!s1.empty()){
		s1.pop();
	}

}
int main(){
	Queue q = Queue();

	q.deQu();
	q.enQu(1);
	q.enQu(2);
	q.enQu(3);
	q.printTop();
	q.deQu();
	q.printTop();
	q.deQu();
	q.printTop();
	q.deQu();
	q.printTop();

}