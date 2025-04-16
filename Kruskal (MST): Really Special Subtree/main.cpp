#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <queue>

using namespace std;

int main()
{
    // chyba nie o ten algorytm chodzilo

    int n, m, start;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cin >> start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<bool> visited(n + 1, false);
    int output = 0;


    // w kolejce waga to x.first a node to x.second
    Q.push({0, start});

    while (!Q.empty())
    {
        auto vertex = Q.top();
        Q.pop();

        int neighbor = vertex.second;
        int weight = vertex.first;

        if (visited[neighbor]) continue;

        output += weight;
        visited[neighbor] = true;

        for (auto nnbor : graph[neighbor])
        {
            if (!visited[nnbor.first])
            {
                Q.push({nnbor.second, nnbor.first});
            }
        }
    }

    cout << output << endl;

    return 0;
}