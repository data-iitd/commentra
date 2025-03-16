#include <stdio.h>
#include <string.h>

void solve(int testNumber) {
    char s[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", s); // Read the input string

    // Replace all occurrences of "BC" with "D"
    char temp[100001];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'B' && s[i + 1] == 'C') {
            temp[j++] = 'D'; // Replace "BC" with "D"
            i++; // Skip the next character
        } else {
            temp[j++] = s[i]; // Copy the current character
        }
    }
    temp[j] = '\0'; // Null-terminate the new string

    long cnt = 0; // Initialize a counter to keep track of the result
    long tmp = 0; // Temporary variable to count consecutive 'A's
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == 'A') {
            tmp++; // Increment tmp if the current character is 'A'
        } else if (temp[i] == 'D') {
            cnt += tmp; // Add tmp to cnt if the current character is 'D'
        } else {
            tmp = 0; // Reset tmp if the current character is not 'A' or 'D'
        }
    }
    printf("%ld\n", cnt); // Print the final count
}

int main() {
    int testNumber = 1; // Assuming a single test case
    solve(testNumber); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>
