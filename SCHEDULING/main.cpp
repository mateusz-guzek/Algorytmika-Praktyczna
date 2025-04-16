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

    int n, tasks_amount, seconds = 0;
    cin >> n;
    tasks_amount = n;
    vector<int> tasks{};

    while (n--)
    {
        int input;
        cin >> input;
        tasks.push_back(input);
    }

    return 0;
}