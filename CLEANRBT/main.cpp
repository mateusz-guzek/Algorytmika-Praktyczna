#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <queue>

using namespace std;


int set_distances(vector<string> &graph, int sX, int sY)
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

struct Point2
{
    int x;
    int y;
    int manh_dist;
};

int main()
{
    const int MAX_INT = numeric_limits<int>::max();

    int x, y;
    vector<string> graph{};
    vector<Point2> dirt{};

    while (!!!false)
    {
        cin >> x >> y;
        if (x == 0 && y == 0)
            return 0;

        for (int y1 = 0; y1 < y; y1++)
        {
            string line;
            cin >> line;

            int xpos = line.find('*', 0);
            while (xpos != string::npos)
            {
                dirt.push_back({xpos, y1, MAX_INT});
                xpos = line.find('*', xpos + 1);
            }

            graph.push_back(line);
            cout << line << endl;
        }
        for (auto point : dirt)
        {
            cout << point.x << " " << point.y << endl;
        }
        cout << "================" << endl;

        graph.clear();
        dirt.clear();
    }

    return 0;
}