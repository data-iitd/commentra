#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // Read the first integer N and the second integer K
    char S[N + 1]; // Declare a string S with size N + 1 for null termination
    scanf("%s", S); // Read the string S

    char c1[N + 1]; // Create character array c1
    char c3[N + 1]; // Create character array c3
    strcpy(c1, S); // Copy S to c1
    strcpy(c3, S); // Copy S to c3

    int flag = 0; // A flag to indicate whether we are flipping
    int count = 0; // A counter for the number of flips

    // Process c1 (Left to Right)
    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') { // If we are flipping and encounter 'R'
            flag = 0; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (c1[i] == 'L') { // If we encounter 'L'
            flag = 1; // Set the flag to true
            c1[i] = 'R'; // Flip it to 'R'
        }
    }

    flag = 0; // Reset the flag
    count = 0; // Reset the flip count

    // Process c3 (Right to Left)
    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') { // If we are flipping and encounter 'L'
            flag = 0; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (c3[i] == 'R') { // If we encounter 'R'
            flag = 1; // Set the flag to true
            c3[i] = 'L'; // Flip it to 'L'
        }
    }

    int sum1 = 0; // Initialize sum for S1
    count = 1; // Initialize count for consecutive characters
    char bef = c1[0]; // Initialize the previous character

    // Count consecutive characters in c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) { // If the current character is the same as the previous
            count++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum1 += count - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef = c1[i]; // Update the previous character
            sum1 += count - 1; // Add the count minus one to the sum
            count = 1; // Reset the count
        }
    }

    int sum3 = 0; // Initialize sum for S3
    count = 1; // Reset count for consecutive characters
    bef = c3[0]; // Initialize the previous character

    // Count consecutive characters in c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) { // If the current character is the same as the previous
            count++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum3 += count - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef = c3[i]; // Update the previous character
            sum3 += count - 1; // Add the count minus one to the sum
            count = 1; // Reset the count
        }
    }

    // Print the maximum of the two sums
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);

    return 0;
}

// <END-OF-CODE>
