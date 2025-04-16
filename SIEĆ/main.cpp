#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <unordered_map>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

enum Direction
{
    LEFT,
    RIGHT,
    BIDIR
};

pair<int, Direction> parseDirectionString(string input)
{
    regex pattern(R"(<-([0-9]+)->|--([0-9]+)->|<-([0-9]+)--)");
    smatch match;

    if (regex_match(input, match, pattern))
    {
        if (match[1].matched)
        {
            return {stoi(match[1].str()), BIDIR};
        }
        else if (match[2].matched)
        {
            return {stoi(match[2].str()), RIGHT};
        }
        else if (match[3].matched)
        {
            return {stoi(match[3].str()), LEFT};
        }
    }
    return {0, LEFT}; // ??
}

int distance(unordered_map<string, vector<pair<string, int>>> &citiesGraph, string source, string destination)
{

    const int INT_MAX = numeric_limits<int>::max();
    unordered_map<string, int> distances;

    for (const auto &city : citiesGraph)
    {
        // first = city
        // second = neighbors

        distances[city.first] = INT_MAX;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> Q;
    // { dystans, miasto }
    Q.push({0, source});

    while (!Q.empty())
    {
        auto top = Q.top();
        Q.pop();

        int distance = top.first;
        string city = top.second;

        if (city == destination)
        {
            return distance;
        }

        if (distance > distances[city])
            continue;

        auto neighbors = citiesGraph[city];

        for (auto neighbor : neighbors)
        {
            int alt = distance + neighbor.second;
            if (alt < distances[neighbor.first])
            {
                distances[neighbor.first] = alt;
                Q.push({alt, neighbor.first});
            }
        }
    }
    return distances[destination];
}

int main()
{
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

        if (dir.second == RIGHT || dir.second == BIDIR)
        {
            citiesGraph[city1].emplace_back(city2, dir.first);
        }
        if (dir.second == LEFT || dir.second == BIDIR)
        {
            citiesGraph[city2].emplace_back(city1, dir.first);
        }
    }

    int accum = 0;
    for (auto &carCity : brokenCarCities)
    {
        accum += distance(citiesGraph, garageCity, carCity);
        accum += distance(citiesGraph, carCity, garageCity);
    }

    cout <<"1. " << accum << endl;

    return 0;
}