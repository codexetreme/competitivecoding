//https://www.geeksforgeeks.org/rearrange-array-arri/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define DEBUG(x) cout << "> " << #x << ": " << x << endl;

using namespace std;

typedef vector<int> veci;

void process (veci t){
    unordered_set<int> a;

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] != -1)
            a.insert(t[i]);
    }
    veci p;
    for (int i = 0; i < t.size(); i++)
    {
        if (a.find(i) != a.end())
        {
            p.push_back(i);
        }
        else
        {
            p.push_back(-1);
        }
    }

    for (auto i : p)
        cout << i << " ";
}

int main()
{

    int n;
    veci t({-1, -1, 6, 1, 9, 3, 2, -1, 4, -1});
    veci t1({19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4});

    process(t);
    cout <<endl;
    process(t1);
   
    return 0;
}
