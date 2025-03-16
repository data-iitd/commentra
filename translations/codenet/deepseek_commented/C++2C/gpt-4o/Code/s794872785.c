#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100

// Function to solve the problem
int solve() {
    // Initialize variables to track the longest string and its count
    int maxsize = 0;
    int maxcnt = 0;
<<<<<<< HEAD
    int ans_num; // Index of the longest string
    int ans_num2; // Index of the most frequent string
    char str_v[MAX_STRINGS][MAX_STRING_LENGTH]; // Array to store input strings
    int str_count = 0; // Count of strings read

    // Variable to read input strings
    while (scanf("%s", str_v[str_count]) != EOF) {
        if (maxsize < strlen(str_v[str_count])) { // Check if the current string is the longest so far
            maxsize = strlen(str_v[str_count]); // Update the length of the longest string
            ans_num = str_count; // Store the index of the longest string
        }
        str_count++; // Increment the count of strings
    }

    // Count occurrences of each string and find the most frequent string
    for (int i = 0; i < str_count; i++) {
        int cnt = 0;
        for (int j = 0; j < str_count; j++) {
            if (strcmp(str_v[i], str_v[j]) == 0) cnt++; // Count occurrences of the current string
        }
        if (maxcnt < cnt) { // Check if the current string is the most frequent so far
            maxcnt = cnt; // Update the count of the most frequent string
            ans_num2 = i; // Store the index of the most frequent string
=======
    int ans_num = -1; // Index of the longest string
    int ans_num2 = -1; // Index of the most frequent string
    char str_v[MAX_STRINGS][MAX_STRING_LENGTH]; // Array to store input strings
    int count[MAX_STRINGS] = {0}; // Array to count occurrences of each string
    int n = 0; // Number of strings read

    // Variable to read input strings
    while (scanf("%s", str_v[n]) != EOF) {
        // Store the input string in the array
        if (n < MAX_STRINGS) {
            // Check if the current string is the longest so far
            if (maxsize < strlen(str_v[n])) {
                maxsize = strlen(str_v[n]); // Update the length of the longest string
                ans_num = n; // Store the index of the longest string
            }
            n++;
        }
    }

    // Count occurrences of each string
    for (int i = 0; i < n; i++) {
        if (count[i] == 0) { // Only count if this string hasn't been counted yet
            count[i] = 1; // Count the current string
            for (int j = i + 1; j < n; j++) {
                if (strcmp(str_v[i], str_v[j]) == 0) {
                    count[i]++; // Increment count for duplicates
                }
            }
            // Check if the current string is the most frequent so far
            if (maxcnt < count[i]) {
                maxcnt = count[i]; // Update the count of the most frequent string
                ans_num2 = i; // Store the index of the most frequent string
            }
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Output the most frequent and the longest string
<<<<<<< HEAD
    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
=======
    if (ans_num2 != -1 && ans_num != -1) {
        printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
    }
>>>>>>> 98c87cb78a (data updated)

    return 1; // Return 1 indicating success
}

// Main function to call the solve function
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
