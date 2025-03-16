
#include <iostream>
#include <cmath>

int main() {
    // Create a Scanner object to read input from the user
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read an integer N from user input
    int N;
    std::cin >> N;

    // Initialize count to track the number of digits in N
    int count = 0;

    // Temporary variable to manipulate the value of N
    int temp = N;

    // Variable to store the final answer
    int ans = 0;

    // Count the number of digits in N
    while (temp > 0) {
        temp /= 10; // Remove the last digit from temp
        count++; // Increment the digit count
    }

    // Loop through each digit position from 1 to count
    for (int i = 1; i <= count; i++) {
        // Check if we are at the last digit position
        if (i == count) {
            // If the last digit position is odd, calculate the contribution to ans
            if (i % 2 == 1) {
                ans += (N - pow(10, i - 1) + 1);
            }
        } else {
            // Handle contributions for positions other than the last
            if (i == 1) {
                // For the first digit position, there are 9 possibilities (1-9)
                ans += 9;
            } else if (i % 2 == 1) {
                // For odd digit positions, calculate the range of numbers
                ans += (pow(10, i) - pow(10, i - 1));
            }
        }
    }

    // Output the final answer
    std::cout << ans << std::endl;

    return 0;
}
