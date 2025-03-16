#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to generate all permutations of a given target string
void permutation(char *target, char *ans, int depth, char **list, int *count) {
    // Base case: if the target string is of length 0, add the current answer to the list
    if (strlen(target) == 0) {
        list[*count] = (char *)malloc((strlen(ans) + 1) * sizeof(char));
        strcpy(list[*count], ans);
        (*count)++;
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < strlen(target); i++) {
            // Create new target string without the current character
            char newTarget[MAX_LENGTH];
            strncpy(newTarget, target, i);
            newTarget[i] = '\0';
            strcat(newTarget, target + i + 1);
            
            // Append the current character to the answer and recurse
            char newAns[MAX_LENGTH];
            sprintf(newAns, "%s%c", ans, target[i]);
            permutation(newTarget, newAns, depth + 1, list, count);
        }
    }
}

int main() {
    // Read the number of elements to be processed
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store input strings
    char line[2][MAX_LENGTH] = { "", "" };
    
    // Read n strings from the user and concatenate them into the first column of the array
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            char temp[MAX_LENGTH];
            scanf("%s", temp);
            strcat(line[j], temp);
        }
    }
    
    // Create a string containing numbers from 1 to n
    char number[MAX_LENGTH] = "";
    for (int i = 1; i <= n; i++) {
        char temp[2];
        sprintf(temp, "%d", i);
        strcat(number, temp);
    }
    
    // List to hold all permutations of the number string
    char *list[MAX_LENGTH * MAX_LENGTH]; // Maximum possible permutations
    int count = 0;
    
    // Generate all permutations of the number string
    permutation(number, "", 0, list, &count);
    
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < count; i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (strcmp(list[i], line[j]) == 0) {
                if (sum == 0) {
                    sum += i; // Add index if sum is initially zero
                } else {
                    sum -= i; // Subtract index if sum is not zero
                }
            }
        }
    }
    
    // Output the absolute value of the sum
    printf("%d\n", abs(sum));
    
    // Free allocated memory for permutations
    for (int i = 0; i < count; i++) {
        free(list[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
