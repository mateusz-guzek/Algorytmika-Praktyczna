#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

int main() {



    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<int>> edges(N);
    while (P--) {
        int cow, bull;
        cin >> cow >> bull;
        edges[cow].push_back(bull);
    }
    

    return 0;
}