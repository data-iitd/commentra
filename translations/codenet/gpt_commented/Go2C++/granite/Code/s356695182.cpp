
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to read the next integer from standard input
int nextInt() {
    int num;
    cin >> num;
    return num;
}

// Function to read a specified number of integers from standard input and return them as a vector
vector<int> scanNums(int len) {
    vector<int> nums;
    for (int i = 0; i < len; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    return nums;
}

// Function to calculate the first pattern
int pattern1(vector<int> l) {
    int n = (l[0]*l[3]) + (l[1]*l[4]);
    return n;
}

// Function to calculate the second pattern
int pattern2(vector<int> l) {
    int n = 2 * l[2] * max(l[3], l[4]);
    return n;
}

// Function to calculate the third pattern
int pattern3(vector<int> l) {
    int n = 2*l[2]*min(l[3], l[4]) + doch(l);
    return n;
}

// Function to find the minimum value from a variable number of integer arguments
int min(vector<int> nums) {
    if (nums.empty()) {
        throw runtime_error("function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        res = min(res, nums[i]);
    }
    return res;
}

// Function to find the maximum value from a variable number of integer arguments
int max(vector<int> nums) {
    if (nums.empty()) {
        throw runtime_error("function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        res = max(res, nums[i]);
    }
    return res;
}

// Function to calculate the value based on the difference between the last two integers in the vector
int doch(vector<int> l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

int main() {
    int len = 5; // Define the number of integers to read
    vector<int> l = scanNums(len); // Read the integers into a vector
    // Print the minimum value from the three calculated patterns
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;
    return 0;
}

