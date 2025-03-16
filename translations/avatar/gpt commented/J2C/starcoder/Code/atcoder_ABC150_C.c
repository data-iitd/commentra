#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate all permutations of a given target string
void permutation(char *target, char *ans, char *list[]) {
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (strlen(target) <= 1) {
        list[0] = (char *) malloc(sizeof(char) * (strlen(ans) + strlen(target) + 1));
        strcpy(list[0], ans);
        strcat(list[0], target);
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < strlen(target); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            permutation(target + 1, ans + target[i], list);
        }
    }
}

int main() {
    // Read the number of elements to be processed
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store input strings
    char *line[2][1];
    
    // Fill the 2D array with empty strings
    for (int i = 0; i < 2; i++) {
        line[i][0] = (char *) malloc(sizeof(char) * 1);
        strcpy(line[i][0], "");
        // Read n strings from the user and concatenate them into the first column of the array
        for (int j = 0; j < n; j++) {
            char temp[100];
            scanf("%s", temp);
            strcat(line[i][0], temp);
        }
    }
    
    // Create a string containing numbers from 1 to n
    char number[100];
    for (int i = 1; i <= n; i++) {
        strcat(number, (char *) malloc(sizeof(char) * 1));
        sprintf(number + strlen(number), "%d", i);
    }
    
    // List to hold all permutations of the number string
    char *listA[100];
    // Generate all permutations of the number string
    permutation(number, "", listA);
    
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < strlen(listA[0]); i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (listA[i][0] == line[j][0][0]) {
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
    
    // 