#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the integer N (length of the string) and K (number of changes allowed)
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the string S
    char S[N + 1];
    scanf("%s", S);
    
    // Create two copies of the string for manipulation
    char c1[N + 1], c3[N + 1];
    strcpy(c1, S);
    strcpy(c3, S);
    
    // Initialize a flag to track changes and a count for 'R' occurrences
    int flag = 0;
    int count = 0;
    
    // First pass: Change 'L' to 'R' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'R', increment count and reset flag
        if (flag && c1[i] == 'R') {
            flag = 0;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'L', set the flag and change 'L' to 'R'
        if (c1[i] == 'L') {
            flag = 1;
            c1[i] = 'R';
        }
    }
    
    // Reset flag and count for the second pass
    flag = 0;
    count = 0;
    
    // Second pass: Change 'R' to 'L' up to K times
    for (int i = 0; i < N; i++) {
        // If the flag is set and the current character is 'L', increment count and reset flag
        if (flag && c3[i] == 'L') {
            flag = 0;
            count++;
        }
        // Break the loop if K changes have been made
        if (count == K) {
            break;
        }
        // If the current character is 'R', set the flag and change 'R' to 'L'
        if (c3[i] == 'R') {
            flag = 1;
            c3[i] = 'L';
        }
    }
    
    // Initialize variables to count consecutive characters in c1
    count = 1;
    int sum1 = 0;
    char bef = c1[0];
    
    // Count the number of consecutive characters in c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) {
            count++;
            // If it's the last character, add the count to sum1
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = c1[i];
            sum1 += count - 1;
            count = 1;
        }
    }
    
    // Reset count and initialize variables to count consecutive characters in c3
    count = 1;
    int sum3 = 0;
    bef = c3[0];
    
    // Count the number of consecutive characters in c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count++;
            // If it's the last character, add the count to sum3
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count - 1;
            count = 1;
        }
    }
    
    // Output the maximum of the two sums calculated from c1 and c3
    printf("%d\n", (sum1 > sum3) ? sum1 : sum3);
    
    return 0;
}

// <END-OF-CODE>
