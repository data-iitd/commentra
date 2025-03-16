

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;  // Taking an input from the user and storing it in the variable `n`.
    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};  // Defining a vector `a` containing string representations of numbers.
    int new = std::accumulate(n.begin(), n.end(), 0) - '0';  // Converting the input `n` to a vector of its digits, summing them up, and storing the result in `new`.
    if (std::find(a.begin(), a.end(), n)!= a.end()) {  // Checking if the input `n` is in the vector `a`.
        std::cout << 10;  // If `n` is in `a`, print the number 10.
    } else {  // Otherwise...
        std::cout << new;  // Print the value of `new`.
    }
    return 0;
}

