#include<iostream>
#include<vector>
#include<unordered_set>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
using namespace std;

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
} 


int test(){
	int n;
	cin>>n;
	std::vector<int> v(n);

	unordered_set<int> vis;

	for (int i=0; i<n; i++){
		cin>>v[i];
	}

	for (auto i: v){
		vis.insert(v[i]);
	}
	int ctr = 0;

	for (auto i: v){
		for (auto j: v){
			if (vis.find(i+j)!=vis.end()){
				ctr++;
			}
		}
	}
	return ctr>0?ctr: -1;
}

int main(){
	
	int T;
	cin>>T;

	while (T--){
		int t = test();
		cout <<t<<endl;
	}
}