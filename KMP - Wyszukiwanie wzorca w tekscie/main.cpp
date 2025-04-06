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
    int tests;
    cin >> tests;

    while (tests--) {
        string wzorzec, tekst;

        int i;
        cin >> i;

        cin >> wzorzec >> tekst;
        // cout << wzorzec << endl << tekst << endl;

        size_t pos = tekst.find(wzorzec, 0);
        while (pos != string::npos) {
            cout << pos << endl;
            pos = tekst.find(wzorzec, pos + 1);
        }
    }

    return 0;
}