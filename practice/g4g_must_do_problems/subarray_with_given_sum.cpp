#include<iostream>
#include<vector>
#include<unordered_map>
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

pair<int,int> getIndces(){	
	int n,s;
	cin>>n>>s;
	vector<int> nums(n);
	
	for (int i=0; i<n; ++i){
		cin>>nums[i];
	}


	int currSum = 0;
	unordered_map<int,int> visited;
	for (int i=0; i<nums.size(); ++i){
		currSum +=nums[i];
		if (currSum - s == 0){
			return make_pair(0,i);
		}
		if (visited.find(currSum-s)!=visited.end()){
			return make_pair(visited[currSum-s]+1,i);
		}
		visited[currSum] = i;
	}

	return make_pair(-1,-1);
}


int main(){
	
	int T;
	cin>>T;

	while (T--){
		auto p = getIndces();
		if(p.first!=-1)
			cout << p.first + 1 << " " << p.second + 1<< endl;
		else 
			cout << "-1"<<endl;
	}
}