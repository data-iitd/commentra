#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to read a single line from standard input and strip any trailing whitespace characters.
std::string rs() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Function to read an integer from standard input.
int ri() {
    return std::stoi(rs());
}

// Function to read a list of strings from standard input.
std::vector<std::string> rs_() {
    std::string line = rs();
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read a list of integers from standard input.
std::vector<int> ri_() {
    std::vector<std::string> tokens = rs_();
    std::vector<int> numbers;
    for (const std::string& token : tokens) {
        numbers.push_back(std::stoi(token));
    }
    return numbers;
}

int main() {
    // Read the integer value of N from standard input.
    int N = ri();

    // Initialize the variable ans to 0.
    long long ans = 0;

    // Start a loop that iterates from 1 to N + 1.
    for (int i = 1; i <= N; ++i) {
        // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
    std::cout << ans << std::endl;

    return 0;
}
