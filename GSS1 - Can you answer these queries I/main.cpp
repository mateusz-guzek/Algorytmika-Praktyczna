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

const ll LL_MIN = -20025;

struct Node
{
    ll total;
    ll presum;
    ll suffsum;
    ll maxsum;

    Node(ll val = 0)
    {
        total = val;
        presum = val;
        suffsum = val;
        maxsum = val;
    }
};

class GSS1
{

private:
    ll base;
    vector<Node> array;

    Node merge(Node &l, Node &r)
    {
        Node res;
        res.total = l.total + r.total;
        res.presum = max(l.presum, l.total + r.presum);
        res.suffsum = max(l.suffsum + r.total, r.suffsum);
        res.maxsum = max({l.maxsum, r.maxsum, l.suffsum + r.presum});
        return res;
    }

    ll closest2power(ll n)
    {
        ll l = 1;
        while (l < n)
            l *= 2;
        return l;
    }

public:
    GSS1(vector<ll> &arr)
    {
        
        base = closest2power(arr.size())+1;
        array.resize(1000000);

        for (int i = 0; i < arr.size(); i++)
        {
            array[i+1 + base] = Node(arr[i]);
        }

        for (int i = base; i >= 1; i--)
        {
            array[i] = merge(array[i * 2], array[i * 2 + 1]);
        }
    }

    Node query(int left, int right)
    {
        left += base;
        right += base;

        Node leftRes = Node(LL_MIN);
        Node rightRes = Node(LL_MIN);

        leftRes.total = 0;
        rightRes.total = 0;

        while (left <= right)
        {
            if (left % 2 == 1)
            {
                leftRes = (leftRes.maxsum == LL_MIN) ? array[left] : merge(leftRes, array[left]);
                left++;
            }

            if (right % 2 == 0)
            {
                rightRes = (rightRes.maxsum == LL_MIN) ? array[right] : merge(array[right], rightRes);
                right--;
            }

            left /= 2;
            right /= 2;
        }
        return merge(leftRes, rightRes);
    }
};

int main()
{

    int N;
    cin >> N;
    vector<ll> A{};
    while (N--)
    {
        ll num;
        cin >> num;
        A.push_back(num);
    }
    GSS1 gss1(A);
    ll M;
    cin >> M;
    while (M--)
    {
        ll start, end;
        cin >> start >> end;
        cout << gss1.query(start, end).maxsum << endl;
    }

    return 0;
}