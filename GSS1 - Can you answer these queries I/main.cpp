#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <limits>

using namespace std;

struct Node {
    long long value;
    Node* left;
    Node* right;
};

// use segment tree

// kadane
long long maxSubarray(vector<long long>& array, size_t start, size_t end) {
    long long best_sum = numeric_limits<long long>::min();
    long long current_sum = 0;
    for (size_t i = start; i <= end; i++) {
        current_sum = max(array[i], current_sum + array[i]);
        best_sum = max(best_sum, current_sum);
    }
    return best_sum;
}


int main() {

    int N;
    cin >> N;
    vector<long long> A{};
    while (N--)
    {
        long long num;
        cin >> num;
        A.push_back(num);
    }
    long long M;
    cin >> M;
    while (M--)
    {
        long long start, end;
        cin >> start >> end;
        cout << maxSubarray(A, start - 1, end - 1);
    }


    return 0;
}