#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

enum StackMode {
    ADDING,
    DELETING
};

bool isValid(string& word) {
    stack<char> stck;
    StackMode stckMode = StackMode::ADDING;

    for (char character : word) {
        if (!stck.empty() && stck.top() == character) {
            stckMode = StackMode::DELETING;
        }

        if (stck.empty()) {
            stckMode = StackMode::ADDING;
        }

        if (stckMode == StackMode::ADDING) {
            stck.push(character);
        }

        if (stckMode == StackMode::DELETING) {
            if (stck.top() == character) {
                stck.pop();
            }
            else {
                return false;
            }
        }
    }
    return stck.empty();

}

int main() {

    int tests;
    cin >> tests;

    while (tests--)
    {
        string line;
        cin >> line;

        if (isValid(line)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}