#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 1000
#define MAX_LENGTH 100

// Structure to hold a string and its count
typedef struct {
    char str[MAX_LENGTH];
    int count;
} StringCount;

int main() {
    int n;
    scanf("%d\n", &n); // Read the number of strings

    StringCount counts[MAX_STRINGS];
    int uniqueCount = 0;

    // Read the strings
    char input[MAX_STRINGS * MAX_LENGTH];
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Check if the string is already counted
        int found = 0;
        for (int i = 0; i < uniqueCount; i++) {
            if (strcmp(counts[i].str, token) == 0) {
                counts[i].count++;
                found = 1;
                break;
            }
        }
        // If not found, add it to the counts
        if (!found) {
            strcpy(counts[uniqueCount].str, token);
            counts[uniqueCount].count = 1;
            uniqueCount++;
        }
        token = strtok(NULL, " ");
    }

    // Find the string with the maximum occurrences
    char result[MAX_LENGTH];
    int maxCount = 0;
    int lastIndex = -1;

    for (int i = 0; i < uniqueCount; i++) {
        if (counts[i].count > maxCount) {
            maxCount = counts[i].count;
            strcpy(result, counts[i].str);
            lastIndex = i;
        } else if (counts[i].count == maxCount) {
            // Check the index of the first occurrence in the original input
            char *firstOccurrence = strstr(input, counts[i].str);
            char *lastOccurrence = strstr(input, result);
            if (firstOccurrence > lastOccurrence) {
                strcpy(result, counts[i].str);
                lastIndex = i;
            }
        }
    }

    // Print the result
    printf("%s\n", result);

    return 0;
}

// <END-OF-CODE>
