
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate all permutations of a given target string
void permutation(char* list[], char* target, char* ans, int n) {
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (strlen(target) <= 1) {
        char* temp = (char*)malloc(strlen(ans) + strlen(target) + 1);
        strcpy(temp, ans);
        strcat(temp, target);
        list[n] = temp;
        n++;
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < strlen(target); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            char* temp = (char*)malloc(strlen(ans) + 1);
            strcpy(temp, ans);
            strcat(temp, &target[i]);
            permutation(list, &target[i + 1], temp, n);
        }
    }
}

int main() {
    // Create a scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store input strings
    char* line[2][1];
    
    // Fill the 2D array with empty strings
    for (int i = 0; i < 2; i++) {
        line[i][0] = (char*)malloc(1 * sizeof(char));
        line[i][0][0] = '\0';
        // Read n strings from the user and concatenate them into the first column of the array
        for (int j = 0; j < n; j++) {
            char input[100];
            scanf("%s", input);
            char* temp = (char*)malloc(strlen(line[i][0]) + strlen(input) + 1);
            strcpy(temp, line[i][0]);
            strcat(temp, input);
            free(line[i][0]);
            line[i][0] = temp;
        }
    }
    
    // Create a string containing numbers from 1 to n
    char number[100];
    for (int i = 1; i <= n; i++) {
        number[i - 1] = i + '0';
    }
    number[n] = '\0';
    
    // List to hold all permutations of the number string
    char* listA[n * n];
    int listSize = 0;
    // Generate all permutations of the number string
    permutation(listA, number, "", &listSize);
    
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < listSize; i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (strcmp(listA[i], line[j][0]) == 0) {
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
    
    // Free memory allocated for input strings and permutation list
    for (int i = 0; i < 2; i++) {
        free(line[i][0]);
    }
    for (int i = 0; i < listSize; i++) {
        free(listA[i]);
    }
    
    return 0;
}

