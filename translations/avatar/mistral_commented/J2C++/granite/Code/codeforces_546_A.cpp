
// Importing the iostream library for input/output operations
#include <iostream>

// Main function is the entry point of the C++ application
int main() {
    // Declaring and initializing variables for pandu, vundu, urdu and counter c
    long long pandu, vundu, urdu, c = 0;

    // Reading the values of pandu, vundu and urdu from the console using cin
    std::cin >> pandu >> vundu >> urdu;

    // Using a for loop to calculate the sum of the series and store it in the variable c
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu;
        // Comment: Calculating the sum of the series using the formula: c = c + i * pandu
    }

    // Checking if the calculated sum is less than vundu
    if (c < vundu) {
        // Comment: If the calculated sum is less than vundu, then print "0"
        std::cout << "0";
    } else {
        // Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
        std::cout << c - vundu;
    }

    // End of code
    return 0;
}

