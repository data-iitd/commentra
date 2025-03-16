#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100 // Define a maximum number of strings
#define MAX_LENGTH 100  // Define a maximum length for each string

int main() {
    int N;
    scanf("%d", &N); // Step 1: Read the input value N

    char strings[MAX_STRINGS][MAX_LENGTH]; // Step 2: Initialize an array to store strings
    int seen[MAX_STRINGS] = {0}; // Step 3: Initialize an array to track seen strings
    int ans = 1; // Step 4: Initialize a boolean variable 'ans' (1 for true, 0 for false)
    char next = '\0'; // Step 6: Initialize a variable 'next'

    for (int i = 0; i < N; i++) { // Step 3: Read N strings and store them in the array
        scanf("%s", strings[i]);
    }

    for (int i = 0; i < N; i++) { // Step 7: Loop through the strings
        for (int j = 0; j < i; j++) { // Check if the current string has been seen before
            if (strcmp(strings[i], strings[j]) == 0) {
                ans = 0; // Set ans to false
                break;
            }
        }
        if (!ans) break; // Break if a duplicate is found

        if (i != 0) { // Step 10: Check if it's not the first string
            if (next != strings[i][0]) { // Check if the starting character matches
                ans = 0; // Set ans to false
                break;
            }
        }
        next = strings[i][strlen(strings[i]) - 1]; // Step 11: Update 'next'
    }

    if (ans) { // Step 12: Check the value of 'ans'
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
