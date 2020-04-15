#include<iostream>
#include<vector>
#include<stack>
#include <climits>

using namespace std;
class StackSpl{

stack <int> s;
int min = INT_MAX;
public:
	void push (int a){
		if (s.empty()){
			min = a;
			s.push(a);
		}else if (a<=min){
			s.push(2*a-min);
			min = a;	
		}
		else {
			s.push(a);
		}
	}
	
	void pop(){
		if (s.top()<min){
			int temp = s.top();
			s.pop();
			cout<< 2*min - temp;
		}
	}



	
};



int main(int argc, char const *argv[])
{
	
	return 0;
}

