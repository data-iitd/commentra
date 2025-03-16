
#include<iostream>

int main() {
    // Declare an integer variable to store user input
    int n;

    // Read an integer value from the user
    std::cin >> n;

    // Check if the number is even
    if (n % 2 == 0) {
        // If the number is even, print half of the number
        std::cout << n / 2 << std::endl;
    } else {
        // If the number is odd, print half of the number plus one
        std::cout << (n / 2) + 1 << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
