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

void process (){

}

int main()
{

    int n;
    process();
    return 0;
}
