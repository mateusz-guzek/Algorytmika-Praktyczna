#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <regex>
#include <unordered_map>
#include <vector>

using namespace std;

enum Color { NONE, BLACK, WHITE };

bool BFS(vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> colors(graph.size(), NONE);

    for (size_t i = 0; i < graph.size(); i++) {
        if (colors[i] != NONE) continue;

        colors[i] = BLACK;
        q.push(i);

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto &v : graph[u]) {
                if (colors[v] == NONE) {
                    if (colors[u] == BLACK) {
                        colors[v] = WHITE;
                    } else {
                        colors[v] = BLACK;
                    }
                    q.push(v);
                }
                if (colors[v] == colors[u]) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main() {
    int scenariosNo;
    cin >> scenariosNo;
    int n = scenariosNo;

    while (scenariosNo--) {
        int bugsNo, relationsNo;
        cin >> bugsNo >> relationsNo;
        vector<vector<int>> bugsGraph(bugsNo + 1, vector<int>{});

        int x, y;
        while (relationsNo--) {
            cin >> x >> y;
            //cout << x << " " << y << endl;
            bugsGraph[x].push_back(y);
            bugsGraph[y].push_back(x);
        }
        auto isHomo = BFS(bugsGraph);
        cout << "Scenario #" << n-scenariosNo << ":" << endl;
        if (isHomo) {
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }
    }

    return 0;
}