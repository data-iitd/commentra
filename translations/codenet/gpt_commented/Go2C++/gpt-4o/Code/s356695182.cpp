#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to read a specified number of integers from standard input and return them as a vector
vector<int> scanNums(int len) {
    vector<int> nums(len);
    for (int i = 0; i < len; i++) {
        cin >> nums[i]; // Read an integer from standard input
    }
    return nums; // Return the vector of integers
}

// Function to calculate a specific pattern based on the first five integers in the vector
int pattern1(const vector<int>& l) {
    return (l[0] * l[3]) + (l[1] * l[4]); // Calculate the result based on the formula
}

// Function to calculate another pattern based on the maximum of the last two integers
int pattern2(const vector<int>& l) {
    return 2 * l[2] * max(l[3], l[4]); // Calculate the result using the maximum value
}

// Function to calculate a third pattern that combines the minimum value and a function call
int pattern3(const vector<int>& l) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l); // Calculate the result using the minimum value and doch function
}

// Function to calculate a value based on the difference between the last two integers in the vector
int doch(const vector<int>& l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]); // Return the product if the fourth integer is greater
    } else {
        return l[1] * (l[4] - l[3]); // Return the product if the fifth integer is greater
    }
}

// Main function where the program execution begins
int main() {
    int len = 5; // Define the number of integers to read
    vector<int> l = scanNums(len); // Read the integers into a vector
    // Print the minimum value from the three calculated patterns
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
