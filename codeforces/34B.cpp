#include<iostream>

#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
    int n,m,i=0;
    cin >> n>>m;
    vector<int> p(n);
    while (n--) cin>> p[i++];

    sort(p.begin(), p.end());
    int sum = 0;
    while (m--){
        if (p[m]<0){
            sum += p[m];
        }
    }

    cout << sum*-1<<endl;

    return 0;
}
