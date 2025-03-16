#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read multiple integers from standard input
vector<int> scanNums(int len) {
    vector<int> nums(len);
    for (int i = 0; i < len; i++) {
        cin >> nums[i]; // Read a number from standard input
    }
    return nums; // Return the vector of numbers
}

// Function to calculate the first pattern
int pattern1(const vector<int>& l) {
    // Calculate the value of n using the given formula
    int n = (l[0] * l[3]) + (l[1] * l[4]);
    return n; // Return the value of n
}

// Function to calculate the second pattern
int pattern2(const vector<int>& l) {
    // Calculate the maximum of l[3] and l[4]
    int maxNum = max(l[3], l[4]);
    // Calculate the value of n using the given formula
    int n = 2 * l[2] * maxNum;
    return n; // Return the value of n
}

// Function to calculate the third pattern
int pattern3(const vector<int>& l) {
    // Calculate the minimum of l[3] and l[4]
    int minNum = min(l[3], l[4]);
    // Calculate the value of n using the given formula
    int n = 2 * l[2] * minNum + doch(l);
    return n; // Return the value of n
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(const vector<int>& l) {
    // If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        // Otherwise, return the product of l[1] and the difference between l[4] and l[3]
        return l[1] * (l[4] - l[3]);
    }
}

// Main function to read input and call the pattern functions
int main() {
    // Read the length of the input list
    int len = 5;

    // Read the input list from standard input
    vector<int> l = scanNums(len);

    // Calculate and print the minimum of the three patterns
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;

    return 0;
}

// <END-OF-CODE>
