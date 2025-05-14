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

int calculate(vector<string> &room, pair<int, int> source)
{
    int width = room[0].size();
    int height = room.size();

    vector<vector<int>> grid(height, vector<int>(width, 0));
    int id = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            switch (room[y][x])
            {
            case '.':
                grid[y][x] = 0;
                break;
            case '*':
                grid[y][x] = id++;
                break;
            case 'x':
                grid[y][x] = -1;
                break;
            }
        }
    }

    vector<vector<vector<int>>> visited(1 << id, vector<vector<int>>(height, vector<int>(width, 0)));
    queue<tuple<int, int, int>> Q;

    visited[0][source.second][source.first] = 1;
    Q.push({0, source.first, source.second});

    int distance = 0;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!Q.empty())
    {

        int qSize = Q.size();
        for (int i = 0; i < qSize; i++)
        {

            auto top = Q.front();
            Q.pop();

            int mask = get<0>(top);
            int x = get<1>(top);
            int y = get<2>(top);

            if (mask == (1 << id) - 1)
            {
                return distance;
            }

            for (int k = 0; k < 4; k++)
            {
                int nX = x + dx[k];
                int nY = y + dy[k];

                if (nX >= 0 && nX < width && nY >= 0 && nY < height && grid[nY][nX] != -1)
                {
                    if (room[nY][nX] == '*')
                    {

                        int newMask = mask | (1 << grid[nY][nX]);

                        if (visited[newMask][nY][nX])
                            continue;

                        visited[newMask][nY][nX] = 1;

                        Q.push({newMask, nX, nY});
                    }
                    else
                    {
                        if (visited[mask][nY][nX])
                            continue;

                        visited[mask][nY][nX] = 1;
                        Q.push({mask, nX, nY});
                    }
                }
            }
        }
        distance++;
    }
    return -1;
}

int main()
{
    int x, y;
    pair<int, int> vacuum;
    vector<string> graph{};

    while (!!!false)
    {
        cin >> x >> y;
        if (x == 0 && y == 0)
            return 0;

        for (int y1 = 0; y1 < y; y1++)
        {
            string line;
            cin >> line;

            int xvpos = line.find('o', 0);
            if (xvpos != string::npos)
            {
                vacuum.first = xvpos;
                vacuum.second = y1;
            }

            graph.push_back(line);
        }

        cout << calculate(graph, vacuum) << endl;

        graph.clear();
    }

    return 0;
}