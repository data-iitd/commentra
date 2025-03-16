#include <stdio.h> // For standard input and output
#include <string.h> // For string handling

int main() {
    int n; // Number of test cases
    long cnt[5] = {0}; // Array to store counts for M, A, R, C, H

    scanf("%d", &n); // Read the number of test cases

    for (int i = 0; i < n; ++i) {
        char str[100]; // Buffer to read the string
        scanf("%s", str); // Read a string from input

        // Increment the corresponding count based on the first character
        switch (str[0]) {
            case 'M':
                cnt[0]++;
                break;
            case 'A':
                cnt[1]++;
                break;
            case 'R':
                cnt[2]++;
                break;
            case 'C':
                cnt[3]++;
                break;
            case 'H':
                cnt[4]++;
                break;
        }
    }

    // Calculate the result based on the counts
    long res = cnt[0] * cnt[1] * cnt[2] + // First product
               cnt[0] * cnt[1] * cnt[3] + // Second product
               cnt[0] * cnt[1] * cnt[4] + // Third product
               cnt[0] * cnt[2] * cnt[3] + // Fourth product
               cnt[0] * cnt[2] * cnt[4] + // Fifth product
               cnt[0] * cnt[3] * cnt[4] + // Sixth product
               cnt[1] * cnt[2] * cnt[3] + // Seventh product
               cnt[1] * cnt[2] * cnt[4] + // Eighth product
               cnt[1] * cnt[3] * cnt[4] + // Ninth product
               cnt[2] * cnt[3] * cnt[4];   // Tenth product

    printf("%ld\n", res); // Print the result

    return 0; // Return success
}

// <END-OF-CODE>
