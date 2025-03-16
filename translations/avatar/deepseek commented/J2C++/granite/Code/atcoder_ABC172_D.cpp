

#include <iostream> // Include the necessary header file for input/output operations

int main() {
    int n; // Declare an integer variable n to store the input value
    std::cin >> n; // Read an integer n from the user using std::cin

    long long ans = 0; // Initialize the variable ans to 0

    // Loop from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate a value based on the current value of i and the variable n
        long long term = (long long) n / (long long) i;
        long long sum = term * (term + 1) / 2;
        ans += (long long) i * sum;
    }

    // Print the value of ans
    std::cout << ans << std::endl; // Use std::cout to print the value of ans

    return 0; // Return 0 to indicate successful execution of the program
}

