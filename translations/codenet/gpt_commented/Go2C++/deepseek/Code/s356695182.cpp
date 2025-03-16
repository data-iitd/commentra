#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Function to read integers from standard input
vector<int> scanNums(int len) {
    vector<int> nums;
    int num;
    for (int i = 0; i < len; i++) {
        cin >> num;
        nums.push_back(num);
    }
    return nums;
}

// Function to calculate the first pattern
int pattern1(const vector<int>& l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Function to calculate the second pattern
int pattern2(const vector<int>& l) {
    return 2 * l[2] * max(l[3], l[4]);
}

// Function to calculate the third pattern
int pattern3(const vector<int>& l) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

// Function to find the minimum value from a list of integers
int min(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

// Function to find the maximum value from a list of integers
int max(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = max(res, num);
    }
    return res;
}

// Function to calculate the value based on the difference between the last two integers
int doch(const vector<int>& l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

// Main function where the program execution begins
int main() {
    int len = 5;
    vector<int> l = scanNums(len);
    // Print the minimum value from the three calculated patterns
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;
    return 0;
}

