// Importing required headers
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

// Function to read a line of integers from stdin and return a vector of integers
std::vector<int> NextIntsLine() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> integers;
    int number;
    while (iss >> number) {
        integers.push_back(number);
    }
    return integers;
}

// Function to find the maximum integer among input integers
int Max(const std::vector<int>& integers) {
    if (integers.empty()) {
        throw std::invalid_argument("Max requires at least one argument");
    }
    int m = integers[0];
    for (size_t i = 1; i < integers.size(); ++i) {
        if (m < integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// Function to find the minimum integer among input integers
int Min(const std::vector<int>& integers) {
    if (integers.empty()) {
        throw std::invalid_argument("Min requires at least one argument");
    }
    int m = integers[0];
    for (size_t i = 1; i < integers.size(); ++i) {
        if (m > integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// Function to calculate integer power
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw std::invalid_argument("PowInt does not accept negative integers");
    }
    return static_cast<int>(std::pow(static_cast<double>(a), static_cast<double>(e)));
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
    return std::abs(a);
}

// Function to delete an element from a vector
std::vector<int> DeleteElement(std::vector<int>& s, int i) {
    if (i < 0 || i >= s.size()) {
        throw std::out_of_range("Index out of range");
    }
    s.erase(s.begin() + i);
    return s;
}

// Function to concatenate two vectors
std::vector<char> Concat(const std::vector<char>& s, const std::vector<char>& t) {
    std::vector<char> n(s);
    n.insert(n.end(), t.begin(), t.end());
    return n;
}

// Main function
int main() {
    // Reading integers from stdin as a line text
    std::vector<int> tmp = NextIntsLine();
    // Assigning the first integer to variable x
    int x = tmp[0];
    // Initializing sum variable as zero
    int sum = 0;
    // Initializing index variable as one
    int i = 1;
    // Looping until the sum is greater than or equal to x
    while (true) {
        // Adding current index to sum
        sum += i;
        // Checking if sum is greater than or equal to x
        if (sum >= x) {
            // Breaking the loop
            break;
        }
        // Incrementing index
        i++;
    }
    // Printing the index
    std::cout << i << std::endl;
    return 0;
}

// <END-OF-CODE>
