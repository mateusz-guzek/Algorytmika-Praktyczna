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
    vector<int> bulls(M);
    vector<int> cows(N);
    while (P--)
    {
        int cow, bull;
        cin >> cow >> bull;
        cows[cow] = bull;
        bulls[bull] = cow;
    }

    return 0;
}