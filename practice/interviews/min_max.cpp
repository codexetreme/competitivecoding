#include<iostream>
#include<algorithm>
#include<vector>
#define DEBUG(x) cout << "> "<< #x << ": "<<x<<endl;
using namespace std;

int main(){

    vector<int> a({10, 20, 1, 23,43, 1232,432,123});
    int k = 4;

    vector<int> mins;

    for (int i=0; i<a.size(); i++){
        if (i + k -1 >= a.size()) break;
        int m = min_element(a.begin()+ i,a.begin()+ i + k -1) - a.begin();
        mins.push_back(a[m]);
    }

for(auto i: mins) cout<<i<<" ";

    int m = max_element(mins.begin(), mins.end()) - mins.begin();

    DEBUG(mins[m]);
    return 0;

}