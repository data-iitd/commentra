#include <stdio.h>

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initialize an array to hold the integer values
    int a[n];
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Read the string input which consists of characters 'A' and 'B'
    char s[n + 1]; // +1 for the null terminator
    scanf("%s", s);
    
    // Initialize a variable to hold the sum of values corresponding to 'B'
    long sum = 0;
    
    // Calculate the initial sum based on the positions of 'B' in the string
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            sum += a[i]; // Add the value to sum if the character is 'B'
        }
    }
    
    // Store the initial sum as the maximum answer found so far
    long ans = sum;
    long sum1 = sum;
    
    // Iterate through the string to calculate the maximum possible sum
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        } else {
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        }
        
        // Update the maximum answer if the current sum1 is greater
        if (sum1 > ans) {
            ans = sum1;
        }
    }
    
    // Reset sum1 to the initial sum for the next calculation
    sum1 = sum;
    
    // Iterate through the string in reverse to calculate the maximum possible sum
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i]; // Increase sum1 if the character is 'A'
        } else {
            sum1 -= a[i]; // Decrease sum1 if the character is not 'A'
        }
        
        // Update the maximum answer if the current sum1 is greater
        if (sum1 > ans) {
            ans = sum1;
        }
    }
    
    // Output the maximum sum found
    printf("%ld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
