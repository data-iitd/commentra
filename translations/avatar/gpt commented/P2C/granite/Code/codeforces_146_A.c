
#include <stdio.h>

int main() {
    int n, i, h1 = 0, h2 = 0, x = 0;
    char number[1000];

    // Read an integer input which represents the number of elements
    scanf("%d", &n);

    // Read a list of integers from input and convert them to a string
    scanf("%s", number);

    // Iterate through the string of numbers
    for (i = 0; i < n; i++) {
        // Check if the current number is neither 4 nor 7
        if (number[i]!= '4' && number[i]!= '7') {
            printf("NO\n");  // Print "NO" if an invalid number is found
            x = 1;            // Increment the flag to indicate an invalid number was found
            break;           // Exit the loop since we found an invalid number
        }

        // Sum the first half of the numbers
        if (i < n / 2) {
            h1 += number[i] - '0';
        } else {
            // Sum the second half of the numbers
            h2 += number[i] - '0';
        }
    }

    // After checking all numbers, determine if the sums of both halves are equal
    if (!x) {  // Proceed only if no invalid numbers were found
        if (h1 == h2) {
            printf("YES\n");  // Print "YES" if the sums are equal
        } else {
            printf("NO\n");   // Print "NO" if the sums are not equal
        }
    }

    return 0;
}
