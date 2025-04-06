#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int n;
        cin >> n;

        int acc = 0;
        while (n >= 5) {
            acc += n / 5;
            n /= 5;
        }

        cout << acc << endl;
    }

    return 0;
}