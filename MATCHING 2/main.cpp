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

#include <iomanip> // for std::setw

void prettyPrintAdjList(const std::vector<std::vector<std::pair<int, int>>>& graph) {
    for (size_t u = 0; u < graph.size(); ++u) {
        std::cout << u << ":";
        for (const auto& [v, w] : graph[u]) {
            std::cout << " -> (" << v << ", " << w << ")";
        }
        std::cout << "\n";
    }
}



int main()
{

    int N, M, P;
    cin >> N >> M >> P;
    // edges[0] = source
    // edges[N+M+1] = sink
    const int SOURCE = 0;
    const int SINK = N + M + 1;
    //                node, capacity
    vector<vector<pair<int, int>>> edges(N + M + 2);

    set<int> cows, bulls;
    while (P--)
    {
        int cow, bull;
        cin >> cow >> bull;

        cows.insert(cow);
        bulls.insert(N + bull);

        //edges[SOURCE].push_back({cow, 1});
        //edges[SINK].push_back({N + bull, 1});

        edges[cow].push_back({N + bull, 1});
        edges[N + bull].push_back({cow, 1});
    }

    for(auto cow : cows) {
        edges[SOURCE].push_back({cow, 1});
    }
    for(auto bull : bulls) {
        edges[SINK].push_back({bull, 1});
    }
    

    prettyPrintAdjList(edges);

    return 0;
}