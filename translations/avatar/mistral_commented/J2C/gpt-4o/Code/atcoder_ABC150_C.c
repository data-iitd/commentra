#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *target, char *ans, int depth, char ***list, int *count) {
    if (target[0] == '\0') { // Base case: if the target string is empty
        (*list)[*count] = (char *)malloc((strlen(ans) + 1) * sizeof(char));
        strcpy((*list)[*count], ans); // Add the current permutation to the list
        (*count)++;
    } else {
        for (int i = 0; target[i] != '\0'; i++) { // Iterate through each character in the target string
            char newTarget[100]; // Temporary string for the remaining characters
            strncpy(newTarget, target, i); // Copy characters before the current index
            newTarget[i] = '\0'; // Null-terminate the string
            strcat(newTarget, target + i + 1); // Append characters after the current index
            char newAns[100]; // Temporary string for the current answer
            sprintf(newAns, "%s%c", ans, target[i]); // Append the current character to the answer
            permutation(newTarget, newAns, depth + 1, list, count); // Recursive call
        }
    }
}

int main() {
    int n; // Declare an integer variable to store the number of test cases
    scanf("%d", &n); // Read the number of test cases from the user

    char number[100] = ""; // Declare an empty string variable to store the number string
    for (int i = 1; i <= n; i++) { // Create the number string
        char temp[2];
        sprintf(temp, "%d", i);
        strcat(number, temp);
    }

    char **listA = (char **)malloc(10000 * sizeof(char *)); // Allocate memory for permutations
    int count = 0; // Counter for the number of permutations
    permutation(number, "", 0, &listA, &count); // Call the permutation function

    int sum = 0; // Declare an integer variable to store the sum of the indices of the matching permutations
    char line[100][100]; // Array to store lines read from the user
    for (int j = 0; j < n; j++) { // Read lines from the user
        scanf("%s", line[j]);
    }

    for (int j = 0; j < n; j++) { // Iterate through each line read from the user
        for (int i = 0; i < count; i++) { // Iterate through each permutation in the list
            if (strcmp(listA[i], line[j]) == 0) { // Check if the current permutation matches the current line
                if (sum == 0) { // If this is the first matching permutation
                    sum += i; // Add the index of the matching permutation to the sum
                } else { // If there is already a matching permutation in the sum
                    sum -= i; // Subtract the index of the previous matching permutation from the sum
                }
            }
        }
    }

    printf("%d\n", abs(sum)); // Print the absolute value of the sum

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(listA[i]);
    }
    free(listA);

    return 0;
}

// <END-OF-CODE>
