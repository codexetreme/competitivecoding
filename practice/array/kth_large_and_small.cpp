#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;
int main()
{
    vector<int> a({1,2,2,3,44,4,5,5});

    priority_queue<int, vector<int>,greater<int> > q;
    priority_queue<int, vector<int> > q_largest;

    for (int i=0 ; i<a.size(); i++){
        q.push(a[i]);
    }

    int k = 3;

    while (--k){
        cout << k;
        q.pop();

    }
cout<<q.top();
return 0;

}
