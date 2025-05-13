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

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] != i)
        {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if (a != b)
        {
            if (rank[a] < rank[b])
            {
                parent[a] = b;
            }
            else if (rank[a] > rank[b])
            {
                parent[b] = a;
            }
            else
            {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
};

int kruskal(int vertices, vector<tuple<int,int,int>> &edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(vertices);

    int cost = 0;
    int count = 0;

    for(auto &e : edges) {
        int weight = get<0>(e);
        int from = get<1>(e);
        int to = get<2>(e);

        if(dsu.find(from) != dsu.find(to)) {
            dsu.unite(from, to);
            cost += weight;
            if(++count == vertices - 1) break;
        }
    }
    return cost;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges{};

    // tuple<weight, from, to>
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u-1, v-1});
    }

    cout << kruskal(n, edges);

    return 0;
}