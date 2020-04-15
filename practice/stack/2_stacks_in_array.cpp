#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class stacks{

std::vector<int> v;
int s1Top;
int s2Top;
public:
	stacks(int size){
		v.resize(size);
		s1Top = -1;
		s2Top = v.size();
	}

	void pushS1(int);
	void popS1();
	void topS1();

	void pushS2(int);
	void popS2();
	void topS2();

	void print (){
		for (auto &i: v){
			cout<<i<<' ';
		}
		cout<<endl;
	}


};

void stacks::pushS1(int data){
	if (s1Top+1<s2Top ){
		s1Top++;
		v[s1Top] = data;
	}
	else {
		cout<<"s1 is full";
	}
}
void stacks::pushS2(int data){
	
	if (s2Top-1>s1Top){
		s2Top--;
		v[s2Top] = data;
	}
	else {
		cout<<"s2 is full";
	}
}

void stacks::popS1(){
	if (s1Top>=0){
		s1Top--;
	}
	else {
		cout<<"s1 is already empty";
	}
}

void stacks::popS2(){
	
	if (s2Top<=v.size()-1){
		s2Top++;
	}
	else {
		cout<<"s2 is already empty";
	}
}



int main(){

	stacks s = stacks(5);

	// s.popS2();
	s.pushS1(1);
	s.pushS1(2);
	s.pushS1(3);
	s.pushS1(4);
	
	s.pushS1(5);
	s.popS1();

	s.pushS2(1);
	
	s.popS1();
	
	s.pushS2(2);
	
	// s.pushS2(3);
	s.popS2();
	
	s.pushS2(123);
	s.print();


	return 0;
}