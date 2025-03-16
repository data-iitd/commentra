#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate all permutations of a given target string
void permutation(char ***list, char *target, char *ans, int *index) {
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (strlen(target) <= 1) {
        (*list)[*index] = (char *)malloc(strlen(ans) + strlen(target) + 1);
        sprintf((*list)[*index], "%s%s", ans, target);
        (*index)++;
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < strlen(target); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            char *new_target = (char *)malloc(strlen(target) - 1 + 1);
            strncpy(new_target, target, i);
            new_target[i] = '\0';
            strcat(new_target, target + i + 1);
            permutation(list, new_target, strncat(ans, target + i, 1), index);
            free(new_target);
        }
    }
}

int main() {
    // Create a scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store input strings
    char **line[2];
    for (int i = 0; i < 2; i++) {
        line[i] = (char **)malloc(n * sizeof(char *));
        for (int j = 0; j < n; j++) {
            line[i][j] = (char *)malloc(1);
            line[i][j][0] = '\0';
        }
    }
    
    // Fill the 2D array with empty strings
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            char temp[100];
            scanf("%s", temp);
            line[i][j] = (char *)realloc(line[i][j], strlen(temp) + 1);
            strcat(line[i][j], temp);
        }
    }
    
    // Create a string containing numbers from 1 to n
    char number[100] = "";
    for (int i = 1; i <= n; i++) {
        char temp[10];
        sprintf(temp, "%d", i);
        strcat(number, temp);
    }
    
    // List to hold all permutations of the number string
    char ***listA = (char ***)malloc(1000 * sizeof(char **));
    for (int i = 0; i < 1000; i++) {
        listA[i] = (char **)malloc(100 * sizeof(char *));
    }
    int index = 0;
    
    // Generate all permutations of the number string
    permutation(listA, number, "", &index);
    
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < index; i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (strcmp(listA[i][0], line[j][0]) == 0) {
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
    
    // Free allocated memory
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            free(line[i][j]);
        }
        free(line[i]);
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 100; j++) {
            free(listA[i][j]);
        }
        free(listA[i]);
    }
    free(listA);
    
    return 0;
}
