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
    int n;
    vector<int> kids{};
    cin >> n;
    while (n--)
    {
        int kid;
        cin >> kid;
        kids.push_back(kid);
    }

    vector<long long> candies(kids.size(), 1);

    for (int i = 1; i < candies.size(); i++) {
        if (kids[i] > kids[i - 1])
        {
            candies[i] = candies[i - 1] + 1;

        }
    }
    for (int i = candies.size() - 2; i >= 0; i--) {
        if (kids[i] > kids[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    long long sum = 0;
    for (long long candy : candies) {

        sum += candy;
    }
    cout << sum << endl;

    return 0;
}