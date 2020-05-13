#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

int main()
{


    veci t({4, -8, 9, -4, 1, -8, -1, 6});

    int maxTillHere  = 0, max_sum=INT_MIN;   

    for (int i=0; i<t.size(); i++){
        
        maxTillHere += t[i];
        
        if (maxTillHere < 0 ){
            maxTillHere = 0;
        }
        
        if (max_sum < maxTillHere){
            max_sum = maxTillHere;
        }
    }

    DEBUG(maxTillHere);


    return 0;
}



