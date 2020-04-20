#include<iostream>
#include<vector>
#include<algorithm>
#define DEBUG(x) cout<<'>'<< #x << ':'<<x<<endl; 
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


int sumVec(int st, int en, std::vector<int> v){
    int sum = 0;
    for (int i=st; i<=en; i++){
        sum += v[i];
    }   
    return sum;
}


int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int N,K,S;
    
    cin>>N;
    cin>>K;
    cin>>S;
    
    vector<int> arr(N);
    
    
    for (int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int currWindowLen = K;
    vector<pair<int,int>> subsets;
    int stIdx = 0;
    int endIdx = K-1;
    int sumWindow;
    
    if (K==1){
        auto it = find(arr.begin(), arr.end(),S);
        cout <<*it;
    }else 

    while (true){
        stIdx = 0;
        endIdx = currWindowLen-1;
        sumWindow = sumVec(stIdx, endIdx, arr);

        while (sumWindow < S && endIdx+1<N){
            stIdx ++;
            endIdx++;
            sumWindow = sumVec(stIdx, endIdx, arr);
        }
                
        if (sumWindow == S && endIdx-stIdx == currWindowLen-1){
            subsets.push_back(make_pair(stIdx,endIdx));
            break;
        }
        
        while (sumWindow >= S ){
            stIdx++;
            sumWindow = sumVec(stIdx, endIdx, arr);
        }

        subsets.push_back(make_pair(stIdx,endIdx));
        currWindowLen = K - (endIdx-stIdx+1);
        S -= sumWindow;
        // break;
    }
    
    vector<int> newArr;
    
    for (int i=0; i<subsets.size(); i++){
        auto p = subsets[i];
        for (int j= p.first; j<=p.second; j++){
            newArr.push_back(arr[j]);
        }
    }
    
    sort(newArr.begin(), newArr.end());
    
    for (int i=0; i<newArr.size(); i++){
        
        cout<<newArr[i];
    }
    
    return 0;
}