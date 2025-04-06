#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <unordered_map>

using namespace std;



int main() {

    unordered_map<char, int> letters;


    string line;
    cin >> line;
    for (char character : line) {
        letters[character]++;
    }

    unordered_map<int, int> frequencies;
    for (auto x : letters) {
        frequencies[x.second]++;
    }


    if (frequencies.size() == 1) {
        cout << "YES" << endl;
    }
    else if (frequencies.size() == 2) {
        auto it = frequencies.begin();

        int freq1 = it->first;
        int count1 = it->second;
        ++it;
        int freq2 = it->first;
        int count2 = it->second;

        if ((count1 == 1 && (freq1 == 1 || abs(freq1 - freq2) == 1)) ||
            (count2 == 1 && (freq2 == 1 || abs(freq2 - freq1) == 1))) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}