// https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
#include <iostream>
#include <vector>
#include <algorithm>
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

    int maxE = *max_element(t.begin(), t.end());
    int minE = *min_element(t.begin(), t.end());
    
    
    
    for (int i =0; i<t.size(); i++){
        
    }
}


int main()
{

    veci t({1, 5, 15, 10});
    process(t);
    return 0;
}
