#include<iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
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
    os << " ), \n"; 
    return os; 
} 

int main(int argc, char const *argv[])
{
    int k;
    string a;
    cin >> k>>a;
    unordered_map<char, int> m;

    for (int i=0; i<a.size(); i++){
        auto search = m.find(a[i]);
        if (search != m.end()){
            ++m[a[i]];    
        }
        else {
            m[a[i]] = 1;
        }
    }

    string p = "";
    string _="";
    for (auto &i: m){
        // cout <<i;
        if (i.second % k !=0){
            cout <<"-1";
            return 0;
        }
        int times = i.second/k;
        while (times--) p+=i.first;
    }
    // cout<<p<<endl<<k;
    while (k--) _+=p;
    cout <<_;
    return 0;
}