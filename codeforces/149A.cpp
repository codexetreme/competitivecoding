#include<iostream>

#include <vector>
#include <algorithm>
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


template <typename T, typename K> 
ostream& operator<<(ostream& os, const pair<T,K>& v) 
{ 
    os << "( ";
    os << v.first; 
    os << ", "; 
    os << v.second; 
    os << " )"; 
    os << "]\n"; 
    return os; 
} 

int main(int argc, char const *argv[])
{
    int n, i=0;
    cin >> n;
    if (n==0) {
        cout <<0;
        return 0;
    }
    
    std::vector<int> v(12);
    while (i<12){
        cin>> v[i++];
    }
    
    sort (v.rbegin(), v.rend());
    i=0;
    int s = 0;
    while (i<12){
        // cout<<i<<" "<<v[i]<<" "<<s<<endl ;
        if (v[i]+s >=n){
            break;
        }
        s +=v[i++];
    }
    if (i==12 && s<n){
        cout << -1;
        return 0 ;
    }
    // cout << v<<endl;
    cout << i+1 <<endl;

    return 0;
}
