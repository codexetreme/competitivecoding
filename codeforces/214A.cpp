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
    int n,m,i=0;
    cin >> n>>m;
    
    // eq1 a^2 + b = n
    // eq2 a + b^2 = m

    std::vector<pair<int,int>> v;
    for (int a=0; a<=n; a++){
        for (int b =0; b<=n; b++){
            if (a*a + b == n){
                v.push_back(make_pair(a,b));
            }
        }
    }
    int ctr = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        if(i->first + i->second * i->second == m){
            ctr ++;
        }    
         
    }

    // cout << v<<endl;
    cout << ctr<<endl;

    return 0;
}
