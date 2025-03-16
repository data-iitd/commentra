#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Reads a single integer from standard input.
int nextInt() {
    int t;
    cin >> t;
    return t;
}

// Reads a vector of integers from standard input.
vector<int> scanNums(int len) {
    vector<int> nums(len);
    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }
    return nums;
}

// Computes a value using the first two and last two elements of the input vector.
int pattern1(const vector<int>& l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Computes another value using the third element and the maximum of the last two elements.
int pattern2(const vector<int>& l) {
    return 2 * l[2] * max(l[3], l[4]);
}

// Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
int pattern3(const vector<int>& l) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

// Calculates a specific value based on the input vector.
int doch(const vector<int>& l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

// Returns the minimum value among the given integers.
int min(int a, int b) {
    return std::min(a, b);
}

int min(int a, int b, int c) {
    return std::min({a, b, c});
}

int main() {
    int len = 5;
    vector<int> l = scanNums(len);
    cout << min(pattern1(l), pattern2(l), pattern3(l)) << endl;
    return 0;
}

// <END-OF-CODE>
