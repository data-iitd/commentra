

#include <stdio.h>

int main() {
    int N, count = 0, temp, ans = 0;
    scanf("%d", &N); // Read the integer N from standard input
    temp = N; // Initialize a temporary variable to hold the value of N
    while (temp > 0) {
        temp /= 10;
        count++;
    }
    for (int i = 1; i <= count; i++) {
        if (i == count) { // Check if it's the last digit
            if (i % 2 == 1) { // Check if the position is odd
                ans += (N - pow(10, i - 1) + 1); // Add the count of numbers with odd positions
            }
        } else {
            if (i == 1) { // Check if it's the first digit
                ans += 9; // Add the count of single-digit numbers
            } else if (i % 2 == 1) { // Check if the position is odd
                ans += (pow(10, i) - pow(10, i - 1)); // Add the count of numbers in odd positions
            }
        }
    }
    printf("%d\n", ans); // Print the result
    return 0;
}
