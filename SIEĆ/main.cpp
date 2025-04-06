#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <unordered_map>
#include <vector>
#include <functional>

using namespace std;


enum Direction {
    LEFT,
    RIGHT,
    BIDIR
};

pair<int, Direction> parseDirectionString(string input) {
    regex pattern(R"(<-([0-9]+)->|--([0-9]+)->|<-([0-9]+)--)");
    smatch match;
    
    if (regex_match(input, match, pattern)) {
        if (match[1].matched) {
            return {stoi(match[1].str()), BIDIR};
        } else if (match[2].matched) {
            return {stoi(match[2].str()), RIGHT};
        } else if (match[3].matched) {
            return {stoi(match[3].str()), LEFT};
        }
    }
}



int main() {
    int N, C, R;
    cin >> N >> C >> R;
    string garageCity;
    cin >> garageCity;

    vector<string> brokenCarCities{};

    while (C--)
    {
        string brokenCarCity;
        cin >> brokenCarCity;
        brokenCarCities.push_back(brokenCarCity);
    }
    unordered_map<string, vector<pair<string, int>>> citiesGraph;

    while (R--)
    {
        string city1, directions, city2;
        cin >> city1 >> directions >> city2;
        auto dir = parseDirectionString(directions);

        if (dir.second == RIGHT || dir.second == BIDIR) {
            citiesGraph[city1].emplace_back(city2, dir.first);
        }
        if (dir.second == LEFT || dir.second == BIDIR) {
            citiesGraph[city2].emplace_back(city1, dir.first);
        }
    }
    
    
    return 0;
}