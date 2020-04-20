//https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
#include<iostream>
#include<vector>
#include<algorithm>
#define DEBUG(x) cout<< "> "<< #x <<": "<< x <<endl;

using namespace std;

typedef vector<int> veci;
 

void calcMax(veci t){
    int maxS;

    int rotSum = 0;
    int arrSum = 0;
    for (int i=0; i<t.size(); i++){
        rotSum += t[i]*i;
        arrSum += t[i];
    }

    maxS = rotSum;

    for (int j=1 ; j<t.size(); j++){
        int rotJSum = arrSum - t.size()*t[t.size()-j] + rotSum;
        
        
        if (rotJSum > maxS){
            maxS = rotJSum;
        }

        rotSum = rotJSum;

    }
    cout << maxS<<endl;
}


int main(){

    int n;

    veci t({1,20,2,10});
    veci t1({10, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    calcMax(t);
    calcMax(t1);



    return 0;

}
