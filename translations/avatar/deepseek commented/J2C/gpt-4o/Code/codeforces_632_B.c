#include <stdio.h>

int main() {
    // Step 1: Reading Input
    int n;
    scanf("%d", &n); // Read the size of the array
    int a[n]; // Initialize the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the elements of the array
    }

    // Step 2: Reading a String
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s); // Read the string

    // Step 3: Initial Sum Calculation
    long long sum = 0; // Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'

    // Step 4: First Loop
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') sum += a[i]; // Add the element at position i in array a to sum if the character is 'B'
    }

    // Step 5: Main Logic
    long long ans = sum; // Initialize ans with the initial sum
    long long sum1 = sum; // Initialize sum1 for further calculations

    // First nested loop to calculate the maximum possible sum by flipping characters in s
    for (int i = 0; i < n; i++) {
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
    printf("%lld\n", ans); // Print the maximum sum found

    return 0;
}

// <END-OF-CODE>
