#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_STRING_LENGTH 100

int main() {
    int N;
    scanf("%d", &N);
    
    char map[MAX_N][MAX_STRING_LENGTH];
    int past[MAX_N] = {0}; // To track if a string has been seen
    int past_count = 0; // Count of unique strings seen
    int ans = 1; // Assume true (1) initially
    char next[2] = ""; // To store the last character of the previous string

    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < N; i++) {
        // Check if the string has been seen before
        for (int j = 0; j < past_count; j++) {
            if (strcmp(map[i], map[past[j]]) == 0) {
                ans = 0; // Set to false (0)
                break;
            }
        }
        if (ans == 0) break; // Exit if already false

        // Add the current string to past
        past[past_count++] = i;

        // Check the first character condition
        if (i != 0) {
            if (next[0] != map[i][0]) {
                ans = 0; // Set to false (0)
                break;
            }
        }

        // Update next with the last character of the current string
        next[0] = map[i][strlen(map[i]) - 1];
        next[1] = '\0'; // Null-terminate the string
    }

    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
