#include <iostream> // Step 1: Include necessary headers

int main() { // Step 2: Define the main function
    int N = 0; // Step 3: Declare variables
    int R = 0;

    std::cin >> N >> R; // Step 4: Read input values

    if(N >= 10) { // Step 5: Implement conditional logic
        std::cout << R << std::endl; // If true, print the value of R
    } else {
        std::cout << R + 100 * (10 - N) << std::endl; // Otherwise, calculate and print the adjusted value of R
    }

    return 0; // Step 6: Return statement
}

// <END-OF-CODE>
