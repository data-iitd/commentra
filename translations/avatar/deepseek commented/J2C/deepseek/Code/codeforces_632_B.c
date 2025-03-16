#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the size of the array
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the elements of the array
    }

    char s[100001]; // Assuming the string length won't exceed 100000
    scanf("%s", s); // Read the string

    long sum = 0; // Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'

    // Step 4: First Loop
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i]; // Get the character at position i in the string s
        if (ch == 'B') sum += a[i]; // Add the element at position i in array a to sum if the character is 'B'
    }

    // Step 5: Main Logic
    long ans = sum; // Initialize ans with the initial sum
    long sum1 = sum; // Initialize sum1 for further calculations

    // First nested loop to calculate the maximum possible sum by flipping characters in s
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') sum1 += a[i]; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a[i]; // Subtract the element at position i in array a from sum1 if the character is 'B'
        if (sum1 > ans) ans = sum1; // Update ans with the maximum value between ans and sum1
    }

    // Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
    sum1 = sum; // Reset sum1 to the initial sum
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') sum1 += a[i]; // Add the element at position i in array a to sum1 if the character is 'A'
        else sum1 -= a[i]; // Subtract the element at position i in array a from sum1 if the character is 'B'
        if (sum1 > ans) ans = sum1; // Update ans with the maximum value between ans and sum1
    }

    // Step 6: Output
    printf("%ld\n", ans); // Print the maximum sum found

    return 0;
}
