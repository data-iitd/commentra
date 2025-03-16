
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n;
    scanf("%d", &n);

    // Initialize an array to hold the integer values
    int a[n];

    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read the string input which consists of characters 'A' and 'B'
    char s[100001];
    scanf("%s", s);

    // Initialize a variable to hold the sum of values corresponding to 'B'
    long sum = 0;

    // Calculate the initial sum based on the positions of 'B' in the string
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'B') {
            sum += a[i]; // Add the value to sum if the character is 'B'
        }
    }

    // Store the initial sum as the maximum answer found so far
    long ans = sum;
    long sum1 = sum;

    // Iterate through the string to calculate the maximum possible sum
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        } else {
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        }

        // Update the maximum answer if the current sum1 is greater
        ans = fmax(ans, sum1);
    }

    // Reset sum1 to the initial sum for the next calculation
    sum1 = sum;

    // Iterate through the string in reverse to calculate the maximum possible sum
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        } else {
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        }

        // Update the maximum answer if the current sum1 is greater
        ans = fmax(ans, sum1);
    }

    // Output the maximum sum found
    printf("%ld\n", ans);

    return 0;
}
