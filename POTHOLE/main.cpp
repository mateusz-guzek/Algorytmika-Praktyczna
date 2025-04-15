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
// graph.size() = sink
// pair<capacity, destination>
int max_flow(vector<vector<pair<int, int>>> graph) {

}


int main() {

    int tests;
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>{});
        for (int i = 1; i < n; i++) {
            int paths;
            cin >> paths;
            for (int _ = 0; _ < paths; _++)
            {
                int path;
                cin >> path;

                if (i == 1) {
                    graph[i].push_back(make_pair(1, path));
                }
                else if (path == n) {
                    graph[i].push_back(make_pair(1, path));
                }
                else {
                    graph[i].push_back(make_pair(FAKE_INF, path));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (auto path : graph[i]) {
                cout << path.second << " ";
            }
            cout << endl;
        }
        cout << "source: 1" << endl << "sink: " << n << endl;
    }

    return 0;
}