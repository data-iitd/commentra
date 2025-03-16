#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100

// Function to sanitize a string by converting it to lowercase and removing certain characters
void sanitize(char *s, char *result) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            result[j++] = tolower(s[i]);
        }
    }
    result[j] = '\0'; // Null-terminate the sanitized string
}

// Function to generate all permutations of a string
void permute(char *str, int l, int r, char **results, int *count) {
    if (l == r) {
        results[*count] = strdup(str); // Duplicate the string
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recur
            permute(str, l + 1, r, results, count);

            // Backtrack
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

// Main logic of the program
int main() {
    char inputStrings[3][MAX_LEN];
    char sanitizedStrings[3][MAX_LEN];
    char *permutedResults[1000]; // Assuming a maximum of 1000 permutations
    int count = 0;

    // Read 3 strings
    for (int i = 0; i < 3; i++) {
        fgets(inputStrings[i], MAX_LEN, stdin);
        inputStrings[i][strcspn(inputStrings[i], "\n")] = 0; // Remove newline
        sanitize(inputStrings[i], sanitizedStrings[i]);
    }

    // Generate permutations
    char combined[3 * MAX_LEN];
    for (int i = 0; i < 3; i++) {
        combined[i] = sanitizedStrings[i][0]; // Initialize with first character
    }
    permute(combined, 0, 2, permutedResults, &count);

    // Read number of test cases
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char testString[MAX_LEN];
        fgets(testString, MAX_LEN, stdin);
        testString[strcspn(testString, "\n")] = 0; // Remove newline
        char sanitizedTest[MAX_LEN];
        sanitize(testString, sanitizedTest);

        // Check if the sanitized test string is in the results
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(sanitizedTest, permutedResults[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }

    // Free allocated memory for permutations
    for (int i = 0; i < count; i++) {
        free(permutedResults[i]);
    }

    return 0;
}

// <END-OF-CODE>
