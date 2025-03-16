
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to generate all permutations of a given target string
void permutation(char *target, char *ans, int n) {
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (strlen(target) <= 1) {
        printf("%s%s\n", ans, target);
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < strlen(target); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            permutation(target + i + 1, ans + target[i], n);
        }
    }
}

int main() {
    // Create a scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store input strings
    char line[2][1000];
    
    // Fill the 2D array with empty strings
    for (int i = 0; i < 2; i++) {
        memset(line[i], 0, sizeof(line[i]));
        // Read n strings from the user and concatenate them into the first column of the array
        for (int j = 0; j < n; j++) {
            scanf("%s", line[i]);
        }
    }
    
    // Create a string containing numbers from 1 to n
    char number[1000];
    memset(number, 0, sizeof(number));
    for (int i = 1; i <= n; i++) {
        sprintf(number, "%s%d", number, i);
    }
    
    // List to hold all permutations of the number string
    char listA[1000][1000];
    memset(listA, 0, sizeof(listA));
    // Generate all permutations of the number string
    permutation(number, "", n);
    
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < n; i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (strcmp(listA[i], line[j]) == 0) {
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
    
    return 0;
}

