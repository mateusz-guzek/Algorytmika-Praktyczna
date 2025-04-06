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

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> Q;
    visited[startX][startY] = true;
    distance[startX][startY] = 0;
    Q.push(make_pair(startX, startY));

    while (!Q.empty())
    {
        auto v = Q.front();
        Q.pop();

        if (v.first == goalX && v.second == goalY) {
            return distance[goalX][goalY];
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = v.first + dx[dir];
            int ny = v.second + dy[dir];
            while (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() && grid[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    distance[nx][ny] = distance[v.first][v.second] + 1;
                    Q.push({ nx, ny });
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }


    }

    return distance[goalX][goalY];



}

int main() {
    int n;
    cin >> n;
    vector<string> grid;

    while (n--)
    {
        string line;
        cin >> line;
        grid.push_back(line);
    }
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;

    cout << minimumMoves(grid, startX, startY, goalX, goalY) << endl;

    return 0;
}