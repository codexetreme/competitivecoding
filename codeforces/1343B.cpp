#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

void process(int n){


    if ((n/2)%2 != 0) {
        cout <<"NO"<<endl;
        return;
    }

    int grp = n/2;

    veci e,o;

    for (int i=1; i<grp; i++){
        e.push_back(i*2);
        o.push_back(i*2 -1);
    }

    e.push_back(grp*2);
    o.push_back(grp*2+(grp-1));

    cout<<"YES"<<endl;
    for(auto i: e){

        cout<<i<<" ";
    }
    for (auto i :o)
    {

        cout << i << " ";
    }
    cout<<endl;
}




int main()
{

    int n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        process(n);
    }

    return 0;
}
