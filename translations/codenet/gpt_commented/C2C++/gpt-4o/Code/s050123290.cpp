#include <iostream>
#include <vector>

#define N 1000  // Define a constant N to represent the maximum size of the input array

int main() {
    char su[N] = {'0'};  // Declare a character array to store the input, initialized with '0'
    int susum = 0;       // Initialize a variable to hold the sum of the digits

    // Infinite loop to continuously read input until a specific condition is met
    while (true) {
        int j = 0;  // Initialize a counter variable for the loop

        // Loop to read characters into the array until a newline is encountered or the limit is reached
        for (j = 0; j < N; j++) {
            std::cin.get(su[j]);  // Read a character from standard input
            if (su[j] == '\n') break;  // Break the loop if a newline character is encountered
            susum += (su[j] - '0');  // Convert the character to an integer and add it to the sum
        }

        // Check if the first character is '0', which indicates the end of input
        if (su[0] == '0') break;  // Exit the loop if the first character is '0'

        std::cout << susum << std::endl;  // Print the sum of the digits read
        susum = 0;  // Reset the sum for the next input
    }

    return 0;  // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
