#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
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
            if (size[a] < size[b])
            {
                parent[a] = b;
                size[b] += size[a];
            }
            else
            {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    }
    int getSize(int i) {
        return size[find(i)];
    }
};

int main() {

    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--)
    {
        char opcode;
        cin >> opcode;
        switch (opcode)
        {
        case 'M':
            int a,b;
            cin >> a >> b;
            dsu.unite(a,b);
            break;
        case 'Q':
            int i;
            cin >> i;
            cout << dsu.getSize(i) << endl;

        }
    }
    return 0;
}