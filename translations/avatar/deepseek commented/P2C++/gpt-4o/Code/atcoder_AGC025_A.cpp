#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    std::string n;  // Taking an input from the user and storing it in the variable `n`.
    std::cin >> n;  // Read input from the user.

    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};  // Defining a list `a` containing string representations of numbers.

    int new_sum = 0;  // Variable to store the sum of the digits.
    for (char digit : n) {  // Loop through each character in the string `n`.
        new_sum += digit - '0';  // Convert the character to an integer and add it to `new_sum`.
    }

    // Checking if the input `n` is in the list `a`.
    if (std::find(a.begin(), a.end(), n) != a.end()) {  
        std::cout << 10 << std::endl;  // If `n` is in `a`, print the number 10.
    } else {  // Otherwise...
        std::cout << new_sum << std::endl;  // Print the value of `new_sum`.
    }

    return 0;  // Return 0 to indicate successful completion.
}

// <END-OF-CODE>
