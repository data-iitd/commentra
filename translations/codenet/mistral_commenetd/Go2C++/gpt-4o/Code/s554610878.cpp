#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

const int mod = 1e9 + 7;

// Function to read a string input
std::string getString() {
    std::string s;
    std::cin >> s;
    return s;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return std::abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return static_cast<int>(std::pow(base, exp));
}

// Function to find the minimum of given numbers
int min(std::vector<int> nums) {
    if (nums.empty()) {
        throw std::invalid_argument("min() requires at least one argument");
    }
    int minVal = nums[0];
    for (int num : nums) {
        if (num < minVal) {
            minVal = num;
        }
    }
    return minVal;
}

// Function to find the maximum of given numbers
int max(std::vector<int> nums) {
    if (nums.empty()) {
        throw std::invalid_argument("max() requires at least one argument");
    }
    int maxVal = nums[0];
    for (int num : nums) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    std::vector<std::string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    // Read input string
    std::string s = getString();

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < week.size(); i++) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, throw an error
    if (index == -1) {
        throw std::invalid_argument("Invalid day of the week");
    }

    // Calculate the number of days until Sunday and print the result
    int daysUntilSunday = 7 - index;
    std::cout << daysUntilSunday << std::endl;

    return 0;
}

// <END-OF-CODE>
