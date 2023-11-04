#include <iostream>
#include <algorithm>
#include <climits>  // Include this for INT32_MAX
#include <vector>
#include <cstdint>
using namespace std;

int path(vector<vector<int>> e, int s)
{
    vector<int> ver;
    for (int i = 0; i < e.size(); i++)
    {
        if (i != s)
            ver.push_back(i);
    }
    int val = INT32_MAX;

    do
    {
        int temp_val = 0;
        int k = s;
        for (int i = 0; i < ver.size(); i++)
        {
            temp_val += e[k][ver[i]];
            k = ver[i];
        }
        temp_val += e[k][s];
        val = min(val, temp_val);

    } while (next_permutation(ver.begin(), ver.end()));

    return val;
}

int main()
{
    vector<vector<int>> e;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        e.push_back(v);
    }
    cout << path(e, 0) << endl;

    return 0;  // Added return statement for main function
}
