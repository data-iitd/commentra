#include <iostream>  // Include iostream for input-output operations
#include <vector>    // Include vector for dynamic array functionality

// Main function where the execution of the program begins
int main() {
    int A, B, C, X;  // Declare variables to store the number of each coin type and the target sum
    int kosu = 0;    // Declare and initialize a counter for the number of combinations

    // Read the number of each coin type and the target sum from the user
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cin >> X;

    // Normalize the target sum X by dividing it by 50
    X = X / 50;

    // Nested loops to iterate over all possible combinations of the coins
    for (int i = 0; i <= A; i++) {  // Loop over the number of 500 yen coins
        for (int j = 0; j <= B; j++) {  // Loop over the number of 100 yen coins
            for (int k = 0; k <= C; k++) {  // Loop over the number of 50 yen coins
                if (X == (10 * i) + (2 * j) + k) {  // Check if the sum of the coin values equals the normalized target sum
                    kosu++;  // Increment the counter if the condition is met
                }
            }
        }
    }

    // Print the final count of combinations
    std::cout << kosu << std::endl;

    return 0;  // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
