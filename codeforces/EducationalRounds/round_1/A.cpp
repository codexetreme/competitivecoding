#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;


template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}



typedef vector<int> veci;


bool isPow2(int x){
    return x ^ x - 1;
}

void process(int n) {
    long sum = 0;

    for(int i=0; i<n; i++) {
        if (isPow2(i)){
            sum -=i;
        }
        else {
            sum +=1;
        }
    }
    cout << sum;
}

int main()
{

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        process(n);
    }

    return 0;
}
