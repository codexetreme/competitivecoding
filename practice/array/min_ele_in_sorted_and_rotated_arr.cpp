//https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

int binarySearch(veci t){

    int mid = (t.size()-1)/2;
    if (t[t.size()-1]-t[0]> 0) return t[0]; /// for the not rotated case
    if ( t[mid-1]>t[mid]) return t[mid];

    else{
        if (t[mid]> t[t.size()-1]){
            veci temp(t.begin()+ mid, t.end());
            binarySearch(temp);
        }
        else {
            veci temp(t.begin(), t.begin() + mid);
            binarySearch(temp);
        }

    }


}



int main()
{

    int n;
    veci t({5, 6, 1, 2, 3, 4});
    veci t1({1, 2, 3, 4});
    cout << binarySearch(t)<<endl;
    cout << binarySearch(t1)<<endl;
    return 0;
}
