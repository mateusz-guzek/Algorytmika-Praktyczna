#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <regex>
#include <unordered_map>
#include <vector>
#define MAX_NUM_SIZE 256

using namespace std;

void zero_array(int* array) {
    for (size_t i = 0; i < MAX_NUM_SIZE; i++) {
        array[i] = 0;
    }
}

void str2array(string str_num, int* array) {
    zero_array(array);

    int last_array_index = MAX_NUM_SIZE - 1;
    int last_str_num_index = str_num.size() - 1;

    for (size_t i = 0; i < str_num.size(); i++) {
        int digit = str_num[last_str_num_index - i] - '0';
        array[last_array_index - i] = digit;
    }
}

void add(int* array1, int* array2) {
    int carry = 0;

    for (int i = MAX_NUM_SIZE - 1; i >= 0; i--) {
        int a = array1[i];
        int b = array2[i];
        int sum = a + b + carry;
        carry = sum / 10;
        array1[i] = sum % 10;
    }
}

void sub(int* array1, int* array2) {
    int carry = 0;

    for (int i = MAX_NUM_SIZE - 1; i >= 0; i--) {
        int a = array1[i];
        int b = array2[i];

        int diff = a - b - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        array1[i] = diff;
    }
}

void div2(int* array) {
    int carry = 0;

    for (int i = 0; i < MAX_NUM_SIZE; i++) {
        int current = array[i] + carry * 10;
        array[i] = current / 2;
        carry = current % 2;
    }
}

void array_println(int* array) {
    bool leading_zero = true;
    for (size_t i = 0; i < MAX_NUM_SIZE; i++) {
        if (array[i] != 0) {
            leading_zero = false;
        }
        if (!leading_zero) {
            cout << array[i];
        }
    }
    if (leading_zero) {
        cout << 0;
    }
    cout << endl;
}

int main() {
    string line;
    while (cin >> line) {

        if (line == "1") {
            cout << "1" << endl;
        }
        else {

            int n[MAX_NUM_SIZE]{};
            int diff[MAX_NUM_SIZE]{};

            str2array(line, n);
            str2array("2", diff);
            add(n, n);
            sub(n, diff);
            array_println(n);
        }
    }

    return 0;
}