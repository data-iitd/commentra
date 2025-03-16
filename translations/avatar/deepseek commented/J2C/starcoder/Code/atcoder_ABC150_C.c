
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the number of strings
    int n;
    scanf("%d", &n);
    // Initialize a 2D array to store the input strings
    char line[2][1000];
    for (int i = 0; i < 2; i++) {
        memset(line[i], 0, sizeof(line[i]));
        // Read n strings and concatenate them
        for (int j = 0; j < n; j++) {
            scanf("%s", line[i]);
        }
    }
    // Generate the number string for permutations
    char number[1000];
    for (int i = 1; i <= n; i++) {
        sprintf(number, "%s%d", number, i);
    }
    // Create a list to store permutations
    char *listA[1000];
    // Generate all permutations of the number string
    for (int i = 0; i < strlen(number); i++) {
        listA[i] = malloc(sizeof(char) * (strlen(number) + 1));
        for (int j = 0; j < strlen(number); j++) {
            if (j == i) {
                listA[i][j] = number[j];
            } else {
                listA[i][j] = number[j];
            }
        }
        listA[i][strlen(number)] = '\0';
    }
    // Initialize sum to calculate the result
    int sum = 0;
    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < strlen(number); i++) {
            if (strcmp(listA[i], line[j]) == 0) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }
    // Print the absolute value of the sum
    printf("%d\n", abs(sum));
    return 0;
}

