#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> cities(n);
    for (int i = 0; i < n; i++)
    {
        int city1, city2, time;
        cin >> city1 >> city2 >> time;
        cities[city1].push_back({city2, time});
        cities[city2].push_back({city1, time});
    }
    vector<int> machines(k);
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        machines.push_back(c);
    }

    cout << "hello ludzie" << endl;
    return 0;
}