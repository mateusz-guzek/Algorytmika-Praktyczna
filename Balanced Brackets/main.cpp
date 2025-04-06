#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <stack>
#include <unordered_set>

using namespace std;

bool isOpening(char bracket) {
    if (bracket == '(' || bracket == '[' || bracket == '{') {
        return true;
    }
    return false;
}

bool isClosing(char bracket) {
    if (bracket == ')' || bracket == ']' || bracket == '}') {
        return true;
    }
    return false;
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
        (opening == '[' && closing == ']') ||
        (opening == '{' && closing == '}');
}


bool isBalanced(string& str) {
    stack<char> stck{};

    for (char character : str) {
        if (isOpening(character)) {
            stck.push(character);
        }

        if (isClosing(character)) {
            if (stck.empty()) return false;
            char stackTop = stck.top();
            stck.pop();
            if (!isMatchingPair(stackTop, character)) return false;
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
        if (isBalanced(line)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        /* code */
    }


    return 0;
}