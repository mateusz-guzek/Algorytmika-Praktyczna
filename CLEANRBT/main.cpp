#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#include <queue>
#define INT_MAX 2147483647

using namespace std;

int room[400][400];

void clearRoom()
{
    for (int i = 0; i < 400; i++)
    {
        for (int y = 0; y < 400; y++)
        {
            room[i][y] = INT_MAX;
        }
    }
}

void distance(vector<string> &grid, pair<int, int> source, vector<pair<int, int>> dirt)
{

    int gridY = grid.size();
    int gridX = grid[0].size();

    vector<vector<int>> distances(20, vector<int>(20, -1));

    distances[source.second][source.first] = 0;

    queue<pair<int, int>> Q;
    Q.push(source);

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    while (!Q.empty())
    {

        auto top = Q.front();
        Q.pop();

        int x = top.first;
        int y = top.second;

        for (int i = 0; i < 4; i++)
        {
            int nX = x + dx[i];
            int nY = y + dy[i];

            if (
                nY >= 0 && nX >= 0 && nX < gridX && nY < gridY && distances[nY][nX] < 0 && grid[nY][nX] != 'x')
            {
                distances[nY][nX] = distances[y][x] + 1;
                Q.push({nX, nY});
            }
        }
    }
    for (int y = 0; y < gridY; y++)
    {
        for (int i = 0; i < gridX; i++)
        {
            cout << setw(3) << distances[y][i];
        }
        cout << endl;
    }
    cout << endl;
    vector<pair<pair<int, int>, int>> out{};
    for (auto dirtPatch : dirt)
    {
        room[dirtPatch.second * 20 + dirtPatch.first][source.second * 20 + dirtPatch.first] = distances[dirtPatch.second][dirtPatch.first];
    }
}

int main()
{
    clearRoom();
    const int MAX_INT = numeric_limits<int>::max();

    int x, y;
    pair<int, int> vacuum;
    vector<string> graph{};
    vector<pair<int, int>> dirt{};

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
                dirt.push_back({xpos, y1});
                xpos = line.find('*', xpos + 1);
            }

            int xvpos = line.find('o', 0);
            if (xvpos != string::npos)
            {
                dirt.push_back({xvpos, y1});
                vacuum.first = xvpos;
                vacuum.second = y1;
            }

            graph.push_back(line);
            cout << line << endl;
        }

        for (auto dirtPartch : dirt)
        {
            distance(graph, dirtPartch, dirt);
        }

        for (int i = 0; i < 400; i++)
        {
            for (int y = 0; y < 400; y++)
            {
                if (room[i][y] < INT_MAX)
                {
                    cout << room[i][y] << " ";
                }
            }
        }
        cout << "\n================" << endl;

        for (int k = 0; k < 400; k++)
        {
            for (int i = 0; i < 400; i++)
            {
                for (int j = 0; j < 400; j++)
                {
                    if(room[i][j] > room[i][k] + room[k][j])
                        room[i][j] = room[i][k] + room[k][j];
                }
            }
        }
        for (int i = 0; i < 400; i++)
        {
            for (int y = 0; y < 400; y++)
            {
                if (room[i][y] < INT_MAX)
                {
                    cout << room[i][y] << " ";
                }
            }
        }
        

        clearRoom();
        graph.clear();
        dirt.clear();
    }

    return 0;
}