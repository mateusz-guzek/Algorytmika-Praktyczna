#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY roads
 *  2. INTEGER_ARRAY machines
 */

vector<int> machines;
vector<vector<int>> roads;

vector<int> parent;
vector<int> has_machine;

int find(int i)
{
    if (parent[i] != i)
    {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void unite(int x, int y)
{
    int a = find(x);
    int b = find(y);

    if (a != b)
    {
        parent[b] = a;
        has_machine[a] = has_machine[b] || has_machine[a];
        // has_machine[b] = has_machine[b] || has_machine[a];
    }
}

int minTime(vector<vector<int>> roads, vector<int> machines, int n, int k)
{
    parent.resize(n + 1);
    has_machine.resize(n + 1, false);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto machine : machines)
    {
        has_machine[machine] = true;
    }

    sort(roads.begin(), roads.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] > b[2]; });

    int cost = 0;
    for (auto road : roads)
    {
        int city_a = road[0];
        int city_b = road[1];
        int distance = road[2];
        int root_a = find(city_a);
        int root_b = find(city_b);

        if (has_machine[root_a] && has_machine[root_b])
        {
            cost += distance;
        }
        else
        {
            unite(root_a, root_b);
        }
    }
    return cost;
}

int main()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);
    roads.resize(n - 1);
    machines.resize(k);

    for (int i = 0; i < n - 1; i++)
    {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++)
        {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    for (int i = 0; i < k; i++)
    {
        string machines_item_temp;
        getline(cin, machines_item_temp);

        int machines_item = stoi(ltrim(rtrim(machines_item_temp)));

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines, n, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
