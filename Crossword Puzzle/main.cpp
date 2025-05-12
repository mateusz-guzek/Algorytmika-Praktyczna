#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

struct Slot {
    int x, y;
    char dir; // 'H' or 'V'
    int length;
};

vector<Slot> findSlots(const vector<string>& grid) {
    vector<Slot> slots;

    for (int i = 0; i < 10; ++i) {
        int j = 0;
        while (j < 10) {
            if (grid[i][j] == '-') {
                int start = j;
                while (j < 10 && grid[i][j] == '-') j++;
                int len = j - start;
                if (len > 1) {
                    slots.push_back({i, start, 'H', len});
                }
            } else {
                ++j;
            }
        }
    }

    for (int j = 0; j < 10; ++j) {
        int i = 0;
        while (i < 10) {
            if (grid[i][j] == '-') {
                int start = i;
                while (i < 10 && grid[i][j] == '-') i++;
                int len = i - start;
                if (len > 1) {
                    slots.push_back({start, j, 'V', len});
                }
            } else {
                ++i;
            }
        }
    }

    return slots;
}


vector<string> splitWords(const string &s)
{
    vector<string> result;
    string word;
    for (char c : s)
    {
        if (c == ';')
        {
            if (!word.empty())
                result.push_back(word);
            word.clear();
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
        result.push_back(word);
    return result;
}

int main()
{
    vector<string> grid;
    vector<string> words;
    vector<Slot> slots;

    for (int i = 0; i < 10; i++)
    {
        string line;
        cin >> line;
        grid.push_back(line);
    }
    string line;
    cin >> line;
    words = splitWords(line);
    slots = findSlots(grid);

    return 0;
}
