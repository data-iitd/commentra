
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generates all permutations of a given string
void permutation(char *target, char *ans, int n, int *list) {
    if (n <= 1) {
        list[0]++;
        list[1] += atoi(ans);
    } else {
        for (int i = 0; i < n; i++) {
            permutation(target, ans + i, n - 1, list);
        }
    }
}

int main() {
    // Read the number of strings
    int n;
    scanf("%d", &n);
    // Initialize a 2D array to store the input strings
    char line[2][100000];
    for (int i = 0; i < 2; i++) {
        memset(line[i], 0, sizeof(line[i]));
        // Read n strings and concatenate them
        for (int j = 0; j < n; j++) {
            scanf("%s", line[i]);
        }
    }
    // Generate the number string for permutations
    char number[100000];
    memset(number, 0, sizeof(number));
    for (int i = 1; i <= n; i++) {
        sprintf(number, "%s%d", number, i);
    }
    // Create a list to store permutations
    int listA[2];
    listA[0] = 0;
    listA[1] = 0;
    // Generate all permutations of the number string
    permutation(number, "", n, listA);
    // Initialize sum to calculate the result
    int sum = 0;
    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < listA[0]; i++) {
            if (strcmp(line[j], number + i) == 0) {
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

