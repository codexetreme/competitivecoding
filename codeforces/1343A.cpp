
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

vector<long long> primeFactors(long long n)
{  
    vector<long long> factors;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        factors.push_back(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (long long i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            factors.push_back(i);  
            n = n/i;  
        }  
    }  
    
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        factors.push_back(n);
    return factors;
}  


void process (long long n){
    unsigned long long p2 = 2;
    while (true)
    {
        p2 *= 2;
        // cout << p2 << " ";
        if (p2 -1 >= n){
            break;
        }
    }

    // cout<<"asdfdsafdasf"<<endl;
    while (true){
        if (p2 - 1 == n){
            cout << 1 << endl;
            break;
        }
        p2 = p2/2;
        // cout<<p2<<" ";
        
        if (floor (n / (p2 - 1)) == (double)n / (p2 - 1)){
            cout << n / (p2 - 1)<<endl;
            break;
        }
    }

    // for (auto it: p){
    //     cout<< it.first<<" "<<it.second<<endl;
    // }
}

int main()
{

    int t;
    long long n;

    cin>>t;
    while (t--){
        cin>>n;
        process(n);
    }

    return 0;
}

