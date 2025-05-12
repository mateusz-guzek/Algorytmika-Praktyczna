#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <set>

using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v])
    {
        if (mt[to] == -1 || try_kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{

    int P;
    cin >> n >> k >> P;
    g.resize(n + 1);
    mt.resize(k);
    used.resize(n + 1);

    while (P--)
    {
        int cow, bull;
        cin >> cow >> bull;

        g[cow].push_back(bull);
    }

    mt.assign(k, -1);
    for (int v = 0; v < n; ++v)
    {
        used.assign(n + 1, false);
        try_kuhn(v);
    }

    int acc = 0;
    for (int i = 0; i < k; ++i)
    {
        if (mt[i] != -1)
        {
            acc++;
        }
    }
    cout << acc << endl;

    return 0;
}