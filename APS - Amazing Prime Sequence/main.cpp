#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

vector<long long> spfVector() {
    int n = 10000001;
    vector<long long> arr(n, 0);

    for (int i = 2;i < n; i++) {
        if (arr[i] == 0) {

            for (int j = i; j < n; j += i) {
                if (arr[j] == 0) arr[j] = i;
            }
        }

    }
    return arr;

}




int main() {

    vector<long long> spf = spfVector();
    vector<long long> a(10000001);
    int n;
    cin >> n;
    vector<int> inputs{};

    while (n--)
    {
        int num;
        cin >> num;
        inputs.push_back(num);
    }
    int max_n = *max_element(inputs.begin(), inputs.end());

    for (int i = 2;i <= max_n; i++) {
        a[i] = a[i - 1] + spf[i];
    }

    for (int i = 0; i < inputs.size(); i++) {
        cout << a[inputs[i]] << endl;
    }
    return 0;
}