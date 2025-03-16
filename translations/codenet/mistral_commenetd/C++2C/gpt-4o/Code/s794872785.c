#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100

// Function to solve the problem
int solve() {
    // Initialize variables
    int maxsize = 0;
    int maxcnt = 0;
    int ans_num = -1;
    int ans_num2 = -1;
    char str_v[MAX_STRINGS][MAX_STRING_LENGTH]; // Array to store strings read from input
    int str_count = 0; // Count of strings read

    // Read strings from input
    while (scanf("%s", str_v[str_count]) != EOF) {
        // Update maxsize if the current string is larger
        if (maxsize < strlen(str_v[str_count])) {
            maxsize = strlen(str_v[str_count]);
            ans_num = str_count;
        }
        str_count++;
    }

    // Find the string with maximum occurrences in the array
    for (int i = 0; i < str_count; i++) {
        int cnt = 0;
        // Count the occurrences of the current string in the array
        for (int j = 0; j < str_count; j++) {
            if (strcmp(str_v[i], str_v[j]) == 0) cnt++;
        }
        // Update maxcnt and ans_num2 if the current string has more occurrences
        if (maxcnt < cnt) {
            maxcnt = cnt;
            ans_num2 = i;
        }
    }

    // Print the answer
    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);

    // Return 1 to indicate successful execution
    return 1;
}

// Main function
int main() {
    // Call the solve function
    solve();

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
