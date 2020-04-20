//https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

void getRotCount(veci t){
    for(int i=0; i<t.size()-1; i++){
        if (t[i+1]<t[i]){
            cout << i+1<<endl;
            break;
        }
    }
}


int main()
{

    int n;
    veci t({15, 18, 2, 3, 6, 12}); // sorted array rot 2 times
    veci t1({7, 9, 11, 12, 5});    // sorted array rot 4 times

    getRotCount(t);
    getRotCount(t1);



    return 0;
}
