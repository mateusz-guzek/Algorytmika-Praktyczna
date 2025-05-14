#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <queue>
#define FAKE_INF 2147483647

using namespace std;

// graph 1-indexed
// 1 = source
// n = sink
// edmonds-karp

int bfs(int s, int t, vector<int> &parent, vector<vector<int>> &graph, vector<vector<int>> &capacity)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> Q;
    Q.push({s, FAKE_INF});

    while (!Q.empty())
    {
        int node = Q.front().first;
        int flow = Q.front().second;
        Q.pop();

        for (int next : graph[node])
        {
            if (parent[next] == -1 && capacity[node][next])
            {
                parent[next] = node;
                int newFlow = min(flow, capacity[node][next]);
                if (next == t)
                    return newFlow;
                Q.push({next, newFlow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t, vector<vector<int>> &graph, vector<vector<int>> &capacity)
{
    int flow = 0;
    vector<int> parent(graph.size());
    int newFlow;

    newFlow = bfs(s, t, parent, graph, capacity);

    while (newFlow)
    {
        flow += newFlow;
        int current = t;
        while (current != s)
        {
            int previous = parent[current];
            capacity[previous][current] -= newFlow;
            capacity[current][previous] += newFlow;
            current = previous;
        }

        newFlow = bfs(s, t, parent, graph, capacity);
    }

    return flow;
}

int main()
{

    int tests;
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<vector<int>> capacity(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < n; i++)
        {
            int paths;
            cin >> paths;
            for (int j = 0; j < paths; j++)
            {
                int path;
                cin >> path;

                if (i == 1 || path == n)
                {
                    graph[i].push_back(path);
                    graph[path].push_back(i);
                    capacity[i][path] = 1;
                }
                else
                {
                    graph[i].push_back(path);
                    graph[path].push_back(i);
                    capacity[i][path] = FAKE_INF;
                }
            }
        }

        cout << max_flow(1, n, graph, capacity) << endl;
        graph.clear();
        capacity.clear();
    }

    return 0;
}