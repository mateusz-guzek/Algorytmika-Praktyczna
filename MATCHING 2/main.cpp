#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <set>
#include <queue>

using namespace std;

int N, M, P;
vector<vector<int>> cows;
vector<int> matching;
vector<bool> used;

bool dfs(int from)
{
    if (used[from])
        return false;
    used[from] = true;
    for (int to : cows[from])
    {
        if (matching[to] == -1 || dfs(matching[to]))
        {
            matching[to] = from;
            return true;
        }
    }
    return false;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> P;

    cows.resize(N);

    while (P--)
    {
        int cow, bull;
        cin >> cow >> bull;

        cows[--cow].push_back(--bull);
    }

    matching.assign(M, -1);
    for (int v = 0; v < N; v++)
    {
        used.assign(N, false);
        dfs(v);
    }

    int a = 0;
    for (auto m : matching)
    {
        if (m != -1)
            a++;
    }
    cout << a << endl;

    return 0;
}