#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

veci createDoubleArray(veci t){
    veci temp(t);
    for(int i=0; i<t.size(); i++){
        temp.push_back(t[i]);
    }
    return temp;
}


void quickRotate(veci t, int k){

    veci doubleArr = createDoubleArray(t);

    for (int i=0; i<t.size(); i++){
        cout<< doubleArr[k%t.size() + i]<< " ";
    }
    cout <<endl;
}


int main()
{

    int n;
    veci t({1,20,2,10});
    quickRotate(t, 2);

    return 0;
}
