#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <sstream>
#include <queue>

using namespace std;

string vec2str(vector<vector<int>>& vec) {
    stringstream stream;

    for (auto& row : vec)
    {
        //stream << "[ ";
        for (int& element : row) {
            stream << element << " ";
        }
        stream << "\n";
    }
    return stream.str();
}

vector<vector<int>> calc_distance(vector<vector<int>>& vec, vector<pair<int, int>>& whites) {
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    vector<vector<bool>> visited(vec.size(), vector<bool>(vec[0].size(), false));
    vector<vector<int>> distance(vec.size(), vector<int>(vec[0].size(), -1));
    queue<pair<int, int>> Q{};
    for (auto source : whites) {
        visited[source.first][source.second] = true;
        distance[source.first][source.second] = 0;
        Q.push(source);
    }

    while (!Q.empty())
    {
        auto point = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++) {

            auto nb_point = make_pair(point.first + dx[i], point.second + dy[i]);


            if (nb_point.first < 0 || nb_point.first > vec.size() - 1 || nb_point.second < 0 || nb_point.second > vec[0].size() - 1) continue;
            if (visited[nb_point.first][nb_point.second]) continue;

            visited[nb_point.first][nb_point.second] = true;
            distance[nb_point.first][nb_point.second] = distance[point.first][point.second] + 1;
            Q.push(nb_point);
        }
    }

    return distance;
}



int main() {

    int tests;
    cin >> tests;
    while (tests--)
    {
        vector<vector<int>> matrix{};
        vector<pair<int, int>> whites{};
        int rows, cols;
        cin >> rows;
        cin >> cols;

        matrix.reserve(rows);
        for (int i = 0; i < rows; i++)
        {
            vector<int> row{};
            string line;
            cin >> line;
            for (int y = 0; y < cols; y++)
            {
                int character = line[y];
                row.push_back(character - '0');
                if ((character - '0') == 1) {
                    whites.push_back(make_pair(i, y));
                }
            }
            matrix.push_back(row);
        }
        auto dist_matrix = calc_distance(matrix, whites);
        //cout << vec2str(matrix) << endl;
        cout << vec2str(dist_matrix);

    }
    return 0;
}