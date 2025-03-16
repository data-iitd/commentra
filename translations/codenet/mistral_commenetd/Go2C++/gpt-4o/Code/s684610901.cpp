// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

// Define constants
const int64_t INF = 1e8; // Infinite value for some calculations

// Function to read an integer from input
int64_t readInt() {
    int64_t x;
    std::cin >> x;
    return x;
}

// Main function
int main() {
    // Read input A, B, and C
    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        std::cout << "Yes" << std::endl; // Print "Yes" if condition is true
    } else {
        std::cout << "No" << std::endl;  // Print "No" if condition is false
    }

    return 0;
}

// Helper functions can be added here if needed

// Function to convert string to int64
int64_t s2i(const std::string& s) {
    return std::stoll(s);
}

// Function to convert int64 to string
std::string i2s(int64_t i) {
    return std::to_string(i);
}

// Function to get the absolute value of an integer
int64_t abs(int64_t i) {
    return std::abs(i);
}

// Function to get the maximum value from a list of integers
int64_t max(std::initializer_list<int64_t> values) {
    return *std::max_element(values);
}

// Function to get the minimum value from a list of integers
int64_t min(std::initializer_list<int64_t> values) {
    return *std::min_element(values);
}

// Function to get the sum of elements in a vector of integers
int64_t sum(const std::vector<int64_t>& nums) {
    return std::accumulate(nums.begin(), nums.end(), 0LL);
}

// Function to split a string into a vector of strings using space as delimiter
std::vector<std::string> split(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> result((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    return result;
}

// Function to convert a vector of strings to a vector of integers
std::vector<int64_t> strAry2intAry(const std::vector<std::string>& strs) {
    std::vector<int64_t> nums;
    for (const auto& str : strs) {
        nums.push_back(s2i(str));
    }
    return nums;
}

// Function to convert a vector of integers to a vector of strings
std::vector<std::string> intAry2strAry(const std::vector<int64_t>& nums) {
    std::vector<std::string> strs;
    for (const auto& num : nums) {
        strs.push_back(i2s(num));
    }
    return strs;
}

// Function to join a vector of strings into a single string using space as delimiter
std::string ary2str(const std::vector<std::string>& strs) {
    std::ostringstream oss;
    for (size_t i = 0; i < strs.size(); ++i) {
        oss << strs[i];
        if (i < strs.size() - 1) {
            oss << " ";
        }
    }
    return oss.str();
}

// Function to reverse the order of elements in a vector
std::vector<int64_t> reverse(const std::vector<int64_t>& res) {
    std::vector<int64_t> reversed(res);
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to reverse the order of elements in a vector of strings
std::vector<std::string> reverseStr(const std::vector<std::string>& res) {
    std::vector<std::string> reversed(res);
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to initialize the first element of a vector with a given value
void ini(std::vector<int>& res, int init) {
    if (!res.empty()) {
        res[0] = init;
    }
}

// <END-OF-CODE>
