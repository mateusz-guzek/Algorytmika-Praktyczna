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

    long long n, tasks_amount, seconds = 0;
    cin >> n;
    tasks_amount = n;
    vector<pair<long long, long long>> tasks{};

    while (n--)
    {
        long long input;
        cin >> input;
        tasks.push_back(make_pair(input, 0));
    }
    while (true) {
        bool allFinished = true;
        for (auto& task : tasks) {
            if (task.first > 0) {
                task.first--;
                seconds++;
                task.second = seconds;
                allFinished = false;
            }

        }

        if (allFinished) break;
    }
    for (auto& task : tasks) {
        cout << task.second << endl;

    }



    return 0;
}