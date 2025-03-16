#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate

int main() {
    std::string n;
    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};
    std::cin >> n; // Taking an input from the user and storing it in the variable `n`.
    int new_value = std::accumulate(n.begin(), n.end(), 0, [](int sum, char c) { return sum + (c - '0'); });
    // Converting the input `n` to a list of its digits, summing them up, and storing the result in `new`.
    if (std::find(a.begin(), a.end(), n) != a.end()) {
        // Checking if the input `n` is in the list `a`.
        std::cout << 10 << std::endl; // If `n` is in `a`, print the number 10.
    } else {
        // Otherwise...
        std::cout << new_value << std::endl; // Print the value of `new`.
    }
    return 0;
}
