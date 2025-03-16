#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main() {
    int n;
    scanf("%d", &n);
    
    char strings[MAX_STRINGS][MAX_LENGTH];
    int count[MAX_STRINGS] = {0};
    int f = 1; // 1 for 'Yes', 0 for 'No'
    
    // Read n strings into an array
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }
    
    // Initialize an index variable to track the previous string
    int prev_index = -1;

    // Iterate through each string in the array
    for (int i = 0; i < n; i++) {
        // Increment the count for the current string
        count[i]++;
        
        // Check if the current string has appeared more than once
        for (int j = 0; j < i; j++) {
            if (strcmp(strings[i], strings[j]) == 0) {
                f = 0; // Set flag to 'No' if a duplicate is found
                break;
            }
        }
        
        // Check if the previous string's last character does not match the current string's first character
        if (prev_index != -1 && strings[prev_index][strlen(strings[prev_index]) - 1] != strings[i][0]) {
            f = 0; // Set flag to 'No' if the character condition is violated
        }
        
        // Update the index to the current string's index
        prev_index = i;
    }

    // Print the final result based on the checks
    if (f) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
