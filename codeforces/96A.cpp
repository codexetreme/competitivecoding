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
    int k=0;
    string a;
    cin >> a;
    
    int cc = 0;

    for (int i=0; i<a.size(); i++){
        if (a[i]=='0'){
            if (cc==0){
                k+=1;
            }
            if (cc == 1){
                k=1;
                cc = 0;
            }
        }
        if (a[i]=='1'){
            if (cc==1){
                k+=1;
            }
            if (cc == 0){
                k=1;
                cc = 1;
            }
        }
        if (k == 7){
            cout <<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}