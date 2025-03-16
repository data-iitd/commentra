#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read multiple integers from standard input
vector<int> scanNums(int len) {
    vector<int> nums(len);
    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }
    return nums;
}

// Function to calculate the first pattern
int pattern1(const vector<int>& l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Function to calculate the second pattern
int pattern2(const vector<int>& l) {
    int maxNum = max(l[3], l[4]);
    return 2 * l[2] * maxNum;
}

// Function to calculate the third pattern
int pattern3(const vector<int>& l) {
    int minNum = min(l[3], l[4]);
    return 2 * l[2] * minNum + doch(l);
}

// Function to find the minimum of a list of numbers
int min(const vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
}

// Function to find the maximum of a list of numbers
int max(const vector<int>& nums) {
    return *max_element(nums.begin(), nums.end());
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(const vector<int>& l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

// Main function to read input and call the pattern functions
int main() {
    int len = 5;
    vector<int> l = scanNums(len);
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;
    return 0;
}

