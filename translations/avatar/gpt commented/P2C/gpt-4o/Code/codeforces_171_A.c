#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declare two strings to hold the input
    char a[1000], b[1000];
    
    // Read input and split into two strings a and b
    scanf("%s %s", a, b);
    
    // Determine the maximum length of the two strings
    int len_a = strlen(a);
    int len_b = strlen(b);
    int x = len_a > len_b ? len_a : len_b;

    // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
    char padded_a[1000], padded_b[1000];
    memset(padded_a, '0', x);
    memset(padded_b, '0', x);
    padded_a[x] = '\0';
    padded_b[x] = '\0';

    // Copy 'a' right-justified
    for (int i = 0; i < len_a; i++) {
        padded_a[x - len_a + i] = a[i];
    }
    
    // Copy 'b' left-justified
    for (int i = 0; i < len_b; i++) {
        padded_b[i] = b[i];
    }

    // Initialize an empty string to store the result and a carry variable
    char result[1001]; // Result can be at most x + 1 in length
    int c = 0, result_index = 0;

    // Iterate over each digit from the least significant to the most significant
    for (int i = 0; i < x; i++) {
        // Calculate the sum of the corresponding digits and the carry
        int d = (padded_b[i] - '0') + (padded_a[x - i - 1] - '0') + c;

        // Check if the sum exceeds 9, which requires a carry
        if (d > 9) {
            result[result_index++] = (d % 10) + '0'; // Append the last digit of the sum to the result
            c = 1; // Set carry to 1 for the next iteration
        } else {
            result[result_index++] = d + '0'; // Append the sum to the result
            c = 0; // Reset carry to 0
        }
    }

    // If there's a carry left after the last addition, append '1' to the result
    if (c == 1) {
        result[result_index++] = '1';
    }

    // Reverse the result to get the correct order
    for (int i = 0; i < result_index / 2; i++) {
        char temp = result[i];
        result[i] = result[result_index - i - 1];
        result[result_index - i - 1] = temp;
    }

    // Null-terminate the result string
    result[result_index] = '\0';

    // Print the final result, converting to int to remove leading zeros
    printf("%s\n", result);

    return 0;
}
