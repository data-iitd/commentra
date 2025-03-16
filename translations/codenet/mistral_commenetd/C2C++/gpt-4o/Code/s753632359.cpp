#include <iostream>

int main() {
    // Declare variables N and D of integer type
    // N and D should be positive integers less than or equal to 20
    int N, D;

    // Initialize variables N and D using cin
    std::cin >> N >> D;

    // Calculate the quotient of N by (D*2+1) and store it in variable ans
    int ans = N / (D * 2 + 1);

    // Calculate the remainder of N by (D*2+1) and store it in variable rem
    int rem = N % (D * 2 + 1);

    // Check if the remainder is zero or not
    if (rem != 0) {
        // If the remainder is not zero, increment the value of ans by 1
        ans += 1;
    }

    // Print the value of ans using cout
    std::cout << ans << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
