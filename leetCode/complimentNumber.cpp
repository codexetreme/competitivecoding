#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

string getBin(int s){
        
        string bin = "";
        for (; s>=1; s = s/2){
            bin.append(s%2 == 0? "0": "1");
        }
        reverse(bin.begin(), bin.end());
        return bin;
        
    }
    
string complement(string s){
        
    string bin = "";
    for (int i=0; i<s.size(); i++){
        bin.append(s[i] == '1'? "0": "1");
    }
    return bin;
    
}
int getDec(string s){
        
    int dec = 0;
    cout <<s<<endl;
    for (int i=0; i<s.size(); i++){
        // cout<<"pw "<< pow(2,i)<<endl;
        // cout<<"pw "<<int (s[s.size()-1-i]) <<endl;
        dec += s[s.size()-1-i] == '1'? pow(2,i): 0;
    }
    return dec;
    
}

int findComplement(int num) {
    string p = getBin(num);
    // cout << p <<endl;
    string s = complement(p);
    // cout << s <<endl;
    return getDec(s);
    
}


int main(){
    cout<<findComplement(5);
    return 0;
}