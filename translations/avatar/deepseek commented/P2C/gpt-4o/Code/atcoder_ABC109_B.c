#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100  // Define a maximum number of strings
#define MAX_LENGTH 100   // Define a maximum length for each string

int main() {
    int n;  // Number of strings
    scanf("%d", &n);  // Step 2: Take an integer input n which represents the number of strings.

    char strings[MAX_STRINGS][MAX_LENGTH];  // Array to store the strings
    int count[MAX_STRINGS] = {0};  // Array to count occurrences of each string
    int unique_count = 0;  // To keep track of unique strings
    char f[4] = "Yes";  // Step 5: Initialize a variable f to 'Yes' to keep track of the validity of the sequence.
    int i = -1;  // Step 6: Initialize a variable i to -1 to keep track of the index of the current string.

    // Step 4: Create a list l by taking n inputs from the user.
    for (int j = 0; j < n; j++) {
        scanf("%s", strings[j]);
    }

    // Step 7: Enter a for loop to iterate over each string v in the list l.
    for (int j = 0; j < n; j++) {
        // Check if the string is already counted
        int found = 0;
        for (int k = 0; k < unique_count; k++) {
            if (strcmp(strings[j], strings[k]) == 0) {
                count[k]++;
                found = 1;
                break;
            }
        }
        // If not found, add it to the unique list
        if (!found) {
            strcpy(strings[unique_count], strings[j]);
            count[unique_count] = 1;
            unique_count++;
        }

        // Step 9: If the count of v becomes 2 or more, set f to 'No'.
        if (count[found ? (j - 1) : unique_count - 1] >= 2) {
            strcpy(f, "No");
        }

        // Step 10: If i is not -1 and the last character of the previous string is not the same as the first character of the current string, set f to 'No'.
        if (i != -1 && strings[i][strlen(strings[i]) - 1] != strings[j][0]) {
            strcpy(f, "No");
        }
        i++;  // Step 11: Increment the index i after processing each string.
    }

    // Step 12: Print the value of f, which indicates whether the sequence is valid or not.
    printf("%s\n", f);

    return 0;
}
