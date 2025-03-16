#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to read a line from standard input and remove trailing whitespace
std::string rs() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Function to read an integer from standard input
int ri() {
    std::string line = rs();
    return std::stoi(line);
}

// Function to read a line from standard input and return a list of strings
std::vector<std::string> rs_() {
    std::string line = rs();
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

// Function to read a line from standard input and return a list of integers
std::vector<int> ri_() {
    std::vector<std::string> stringList = rs_();
    std::vector<int> result;
    for (const std::string& str : stringList) {
        result.push_back(std::stoi(str));
    }
    return result;
}

int main() {
    // Read the integer N from input
    int N = ri();

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Loop through each integer from 1 to N (inclusive)
    for (int i = 1; i <= N; ++i) {
        // Calculate the contribution of the current integer i to the answer
        ans += static_cast<long long>(i) * (N / i) * (N / i + 1) / 2;
    }

    // Print the final result
    std::cout << ans << std::endl;

    return 0;
}
