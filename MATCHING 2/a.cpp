#include <iostream>
#include <vector>

using namespace std;

bool try_kuhn(int v, vector<vector<int>> &edges, vector<int> &mt, vector<bool> &used) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : edges[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to], edges, mt, used)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<vector<int>> edges(N + 1);
    vector<int> mt(M + 1, -1);
    vector<bool> used(N + 1);

    for (int i = 0; i < P; ++i) {
        int cow, bull;
        cin >> cow >> bull;
        edges[cow].push_back(bull);
    }

    for (int i = 1; i <= N; ++i) {
        for (int to : edges[i]) {
            if (mt[to] == -1) {
                mt[to] = i;
                used[i] = true;
                break;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (used[i])
            continue;
        fill(used.begin(), used.end(), false);
        try_kuhn(i, edges, mt, used);
    }

    int acc = 0;
    for (int i = 1; i <= M; ++i) {
        if (mt[i] != -1)
            ++acc;
    }

    cout << acc << endl;
    return 0;
}
