#include <iostream>
#include <vector>
#include <string>
#include <numeric> // for std::accumulate

int main() {
    std::string n;
    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};

    // Read input from the user
    std::cin >> n;

    // Convert each character of the input 'n' to an integer using the 'map' function
    // and then sum up all the integers using the 'accumulate' function and assign the result to the variable 'new'
    int new_value = std::accumulate(n.begin(), n.end(), 0, [](int sum, char c) {
        return sum + (c - '0');
    });

    // Check if the input 'n' is present in the list 'a'
    if (std::find(a.begin(), a.end(), n) != a.end()) {
        // If the input 'n' is present in the list 'a', then print the number 10
        std::cout << 10 << std::endl;
    } else {
        // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
        std::cout << new_value << std::endl;
    }

    return 0;
}
