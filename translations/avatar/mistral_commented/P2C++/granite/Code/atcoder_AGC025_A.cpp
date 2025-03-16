
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Take an input from the user and assign it to the variable 'n'
    std::string n;
    std::cin >> n;

    // Initialize a vector 'a' with some strings representing numbers
    std::vector<std::string> a = { "10", "100", "1000", "10000", "100000" };

    // Convert each element of the input 'n' to an integer using the'std::stoi' function
    // and then sum up all the integers using the'std::accumulate' function and assign the result to the variable 'new'
    int new = std::accumulate(n.begin(), n.end(), 0, [](int a, char b) { return a * 10 + (b - '0'); });

    // Check if the input 'n' is present in the vector 'a'
    if (std::find(a.begin(), a.end(), n)!= a.end()) {
        // If the input 'n' is present in the vector 'a', then print the number 10
        std::cout << 10 << std::endl;
    } else {
        // If the input 'n' is not present in the vector 'a', then print the value of the variable 'new'
        std::cout << new << std::endl;
    }

    return 0;
}
