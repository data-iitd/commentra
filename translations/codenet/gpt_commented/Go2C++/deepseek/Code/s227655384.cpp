#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

// Function to read a specified number of long lines from standard input
std::vector<std::string> ReadLongLines(int times) {
    std::vector<std::string> result(times); // Create a vector to hold the lines read
    std::string line;
    for (int i = 0; i < times; ++i) {
        std::getline(std::cin, result[i]); // Read a line from input
    }
    return result; // Return the lines read
}

// Function to print a list of integers to the console
void PrintList(const std::vector<int>& list) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (i > 0) std::cout << " "; // Print a space before subsequent elements
        std::cout << list[i]; // Print the integer
    }
    std::cout << std::endl; // Print a newline after the list
}

int main() {
    std::set<int> m; // Create a set to track unique integers
    auto lines = ReadLongLines(4); // Read 4 lines from input
    std::istringstream iss(lines[1]);
    std::string token;
    std::vector<int> a;

    // Read the second line and split into individual strings
    while (std::getline(iss, token, ' ')) {
        a.push_back(std::stoi(token)); // Convert string to integer and add to vector
    }

    std::istringstream iss2(lines[3]);
    std::vector<int> b;

    // Read the fourth line and split into individual strings
    while (std::getline(iss2, token, ' ')) {
        b.push_back(std::stoi(token)); // Convert string to integer and add to vector
    }

    // Process the integers from the fourth line
    for (int n : b) {
        if (m.find(n) != m.end()) {
            m.erase(n); // Remove it from the set if it exists
        } else {
            m.insert(n); // Add it to the set if it does not exist
        }
    }

    std::vector<int> result(m.begin(), m.end()); // Copy the set to a vector

    // Sort the result vector in ascending order
    std::sort(result.begin(), result.end());

    // Print the sorted result
    for (int n : result) {
        std::cout << n << std::endl; // Print each integer in the result
    }

    return 0;
}
