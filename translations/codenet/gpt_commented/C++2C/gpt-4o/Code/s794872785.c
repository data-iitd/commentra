#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100

// Function to solve the problem of finding the longest and most frequent string
int solve() {
    // Initialize variables to track the maximum size of strings and their counts
    int maxsize = 0; // To store the length of the longest string
    int maxcnt = 0;  // To store the count of the most frequent string
    int ans_num;     // Index of the longest string
    int ans_num2;    // Index of the most frequent string
    char str_v[MAX_STRINGS][MAX_STRING_LENGTH]; // Array to store input strings
<<<<<<< HEAD
    int count[MAX_STRINGS] = {0}; // Array to count occurrences of each string
    int n = 0; // Number of strings read

    // Read strings from standard input until EOF
    while (scanf("%s", str_v[n]) != EOF) {
        // Check if the current string is longer than the previously recorded maximum
        if (maxsize < strlen(str_v[n])) {
            maxsize = strlen(str_v[n]); // Update the maximum size
            ans_num = n; // Update index of the longest string
        }
        n++; // Increment the number of strings read
    }

    // Loop through the array to find the most frequent string
    for (int i = 0; i < n; i++) {
        if (count[i] == 0) { // Only count if this string hasn't been counted yet
            int cnt = 1; // Start count for this string
            for (int j = i + 1; j < n; j++) {
                if (strcmp(str_v[i], str_v[j]) == 0) {
                    cnt++; // Increment count if a match is found
                    count[j] = -1; // Mark this string as counted
                }
            }
            // Check if the current count is greater than the previously recorded maximum count
            if (maxcnt < cnt) {
                maxcnt = cnt; // Update the maximum count
                ans_num2 = i; // Update index of the most frequent string
            }
=======
    int str_count = 0; // Count of strings read

    // Read strings from standard input until EOF
    while (scanf("%s", str_v[str_count]) != EOF) {
        // Check if the current string is longer than the previously recorded maximum
        if (maxsize < strlen(str_v[str_count])) {
            maxsize = strlen(str_v[str_count]); // Update the maximum size
            ans_num = str_count; // Update index of the longest string
        }
        str_count++; // Increment the count of strings
    }

    // Loop through the array to find the most frequent string
    for (int i = 0; i < str_count; i++) {
        int cnt = 0; // Counter for occurrences of the current string
        // Count how many times the current string appears in the array
        for (int j = 0; j < str_count; j++) {
            if (strcmp(str_v[i], str_v[j]) == 0) cnt++; // Increment count if a match is found
        }
        // Check if the current count is greater than the previously recorded maximum count
        if (maxcnt < cnt) {
            maxcnt = cnt; // Update the maximum count
            ans_num2 = i; // Update index of the most frequent string
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Output the most frequent string and the longest string
    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);

    return 1; // Indicate successful execution
}

int main() {
    solve(); // Call the solve function to process input and output results
    return 0; // Indicate successful program termination
}

// <END-OF-CODE>
