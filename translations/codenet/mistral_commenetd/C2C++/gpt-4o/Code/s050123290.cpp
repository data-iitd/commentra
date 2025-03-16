#include <iostream>
#include <vector>

#define N 1000  // Define a constant N with the value 1000

int main() {
    std::vector<char> su(N); // Declare a character vector 'su' of size N
    int susum = 0; // Initialize an integer variable 'susum' to zero

    while (true) { // Start an infinite loop
        int j = 0; // Initialize an integer variable 'j' to zero
        for (j = 0; j < N; j++) { // Iterate through each index of the vector 'su'
            std::cin.get(su[j]); // Read a character from the standard input and store it in the vector 'su' at the current index
            if (su[j] == '\n') break; // If the character read is a newline character, break out of the loop
            susum += (su[j] - '0'); // Add the ASCII value of the character (after subtracting '0') to the variable 'susum'
        }
        if (su[0] == '0') break; // If the first character of the vector 'su' is '0', break out of the loop
        std::cout << susum << std::endl; // Print the sum of the digits read from the standard input
        susum = 0; // Reset the variable 'susum' to zero for the next iteration
    }
    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
