//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}



typedef vector<int> veci;

void process(veci t){
    veci profit(t.size(),0);
    int min_so_far = t[0];
    for(int i=1; i<t.size(); i++){
        if (t[i] < min_so_far) min_so_far = t[i];

        profit[i] = max(profit[i-1], t[i]-min_so_far);

    }   
    DEBUG(profit);

    int max_so_far = t[t.size()-1];
    for (int i = t.size()-2; i >= 0; i--){
        if (t[i] > max_so_far)
            max_so_far = t[i];

        profit[i] = max(profit[i + 1], profit[i]+max_so_far-t[i]);
    }
    DEBUG(profit);
}


int main()
{

    veci t({10, 22, 5, 75, 65, 80});
    veci t2({2, 30, 15, 10, 8, 25, 80});

    process (t);
    process (t2);


    return 0;
}



