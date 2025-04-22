#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>
#define ll long long

using namespace std;

const ll LL_MIN = numeric_limits<ll>::min();

ll Closest2Power(ll n)
{
    ll l = 1;
    while (l < n)
        l *= 2;
    return l;
}

void updateTree(vector<ll> &tree, const ll number, ll index)
{

    tree[index] = number;
    while (index != 0)
    {
        ll parent = (index - 1) / 2;
        ll left = 2 * parent + 1;
        ll right = 2 * parent + 2;
        tree[parent] = max(tree[left], tree[right]);

        index = parent;
    }
}

ll getMaxBetween(const vector<ll> &tree, const ll a, const ll b)
{

    ll parentA = (a - 1) / 2;
    ll parentB = (b - 1) / 2;
    while (parentA != parentB)
    {
        // cout << parentA << " " << parentB << endl;
        parentA = (parentA - 1) / 2;
        parentB = (parentB - 1) / 2;
    }

    return tree[parentA];
}

int main()
{

    ll N, R;
    cin >> N >> R;
    ll leafCount = Closest2Power(N);
    ll treeSize = 2 * leafCount - 1;
    ll leafStart = leafCount - 1;

    vector<ll> tree(treeSize, LL_MIN);

    while (R--)
    {
        ll q, a, b;
        cin >> q >> a >> b;
        if (q == 1)
        {
            updateTree(tree, b, leafStart + a);
        }
        else
        {
            cout << getMaxBetween(tree, leafStart + a, leafStart + b) << endl;
        }
    }

    return 0;
}