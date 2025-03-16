#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
std::string rs() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Function to read a single integer from standard input
int ri() {
    return std::stoi(rs());
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
std::vector<int> ri_() {
    std::string line = rs();
    std::vector<int> numbers;
    std::stringstream ss(line);
    int number;
    while (ss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

int main() {
    // Read the number of test cases from standard input
    int N = ri();

    // Initialize the answer to 0
    long long ans = 0;

    // Iterate through all numbers from 1 to N
    for (int i = 1; i <= N; ++i) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the answer
    std::cout << ans << std::endl;

    return 0;
}
