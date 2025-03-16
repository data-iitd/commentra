
#include <stdio.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the console
    char c;
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N];
    scanf("%s", S);

    // Convert the string S into a character array for manipulation
    char c1[N];
    char c3[N];
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

    // Convert the modified character arrays back to strings
    char S1[N];
    char S3[N];
    strcpy(S1, c1);
    strcpy(S3, c3);

    // Initialize variables to count consecutive characters in S1
    int sum1 = 0;
    int count1 = 1;
    char bef1 = S1[0];

    // Count the number of consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (S1[i] == bef1) {
            count1++;
            // If it's the last character, add the count to sum1
            if (i == N - 1) {
                sum1 += count1 - 1;
            }
        } else {
            bef1 = S1[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }

    // Reset count and initialize variables to count consecutive characters in S3
    int sum3 = 0;
    int count3 = 1;
    char bef3 = S3[0];

    // Count the number of consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (S3[i] == bef3) {
            count3++;
            // If it's the last character, add the count to sum3
            if (i == N - 1) {
                sum3 += count3 - 1;
            }
        } else {
            bef3 = S3[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }

    // Output the maximum of the two sums calculated from S1 and S3
    printf("%d\n", (sum1 > sum3)? sum1 : sum3);

    return 0;
}
