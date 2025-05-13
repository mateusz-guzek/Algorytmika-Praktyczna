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

class Fastmax
{

private:
    ll base;
    vector<ll> array;

    ll closest2power(ll n)
    {
        ll l = 1;
        while (l < n)
            l *= 2;
        return l;
    }

public:
    Fastmax(int n)
    {
        base = closest2power(n);
        array.resize(10000000, 0);
    }

    void update(ll n, ll i)
    {

        i += base;
        array[i] = n;
        while (i != 1)
        {
            i /= 2;
            array[i] = max(array[i * 2], array[i * 2 + 1]);
        }
    }

    ll query(int left, int right)
    {
        left += base;
        right += base;

        ll ml = array[left];
        ll mr = array[right];

        while (left / 2 != right / 2)
        {
            if (left % 2 == 0)
                ml = max(ml, array[left + 1]);
            if (right % 2 == 1)
                mr = max(mr, array[right - 1]);

            left /= 2;
            right /= 2;
        }
        return max(ml, mr);
    }


};

int main()
{

    ll N, R;
    cin >> N >> R;
    Fastmax fmax(N);

    while (R--)
    {
        ll q, a, b;
        cin >> q >> a >> b;
        if (q == 1)
        {
            fmax.update(b, a);
        }
        else
        {
            cout << fmax.query(a, b) << endl;
        }
    }

    return 0;
}