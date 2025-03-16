#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K; // Declare variables N and K
    char S[1000001]; // Declare a character array S
    scanf("%d %d %s", &N, &K, S); // Read the first integer N, the second integer K, and the string S
    
    char c1[1000001]; // Declare a character array c1
    char c3[1000001]; // Declare a character array c3
    
    int flag = 0; // Declare a flag to indicate whether we are flipping
    int count = 0; // Declare a counter for the number of flips
    
    // Process c1 (Left to Right)
    for (int i = 0; i < N; i++) {
        if (flag && S[i] == 'R') { // If we are flipping and encounter 'R'
            flag = 0; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (S[i] == 'L') { // If we encounter 'L'
            flag = 1; // Set the flag to true
            c1[i] = 'R'; // Flip it to 'R'
        }
    }
    
    flag = 0; // Reset the flag
    count = 0; // Reset the flip count
    
    // Process c3 (Right to Left)
    for (int i = 0; i < N; i++) {
        if (flag && S[i] == 'L') { // If we are flipping and encounter 'L'
            flag = 0; // Reset the flag
            count++; // Increment the flip count
        }
        if (count == K) { // If we have made K flips, break out of the loop
            break;
        }
        if (S[i] == 'R') { // If we encounter 'R'
            flag = 1; // Set the flag to true
            c3[i] = 'L'; // Flip it to 'L'
        }
    }
    
    char S1[1000001]; // Declare a character array S1
    char S3[1000001]; // Declare a character array S3
    
    strcpy(S1, c1); // Convert the modified c1 back to a string S1
    strcpy(S3, c3); // Convert the modified c3 back to a string S3
    
    int count1 = 1; // Declare a counter for consecutive characters in S1
    int sum1 = 0; // Declare a sum for S1
    char bef1 = S1[0]; // Declare a variable to store the previous character in S1
    
    // Count consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (S1[i] == bef1) { // If the current character is the same as the previous
            count1++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum1 += count1 - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef1 = S1[i]; // Update the previous character
            sum1 += count1 - 1; // Add the count minus one to the sum
            count1 = 1; // Reset the count
        }
    }
    
    int count3 = 1; // Declare a counter for consecutive characters in S3
    int sum3 = 0; // Declare a sum for S3
    char bef3 = S3[0]; // Declare a variable to store the previous character in S3
    
    // Count consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (S3[i] == bef3) { // If the current character is the same as the previous
            count3++; // Increment the count
            if (i == N - 1) { // If it's the last character in the string
                sum3 += count3 - 1; // Add the count minus one to the sum
            }
        } else { // If the current character is different
            bef3 = S3[i]; // Update the previous character
            sum3 += count3 - 1; // Add the count minus one to the sum
            count3 = 1; // Reset the count
        }
    }
    
    // Print the maximum of the two sums
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);
    
    return 0;
}
