#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generates all permutations of a given string
void permutation(char **list, char *target, char *ans, int *index) {
    if (strlen(target) <= 1) {
        list[*index] = (char *)malloc((strlen(ans) + strlen(target) + 1) * sizeof(char));
        sprintf(list[*index], "%s%s", ans, target);
        (*index)++;
    } else {
        for (int i = 0; i < strlen(target); i++) {
            char temp[256];
            strcpy(temp, target);
            temp[i] = '\0';
            permutation(list, temp + i + 1, strcat(ans, target + i), index);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char line[2][256];
    for (int i = 0; i < 2; i++) {
        scanf("%s", line[i]);
    }

    // Generate the number string for permutations
    char number[256] = "";
    for (int i = 1; i <= n; i++) {
        char temp[10];
        sprintf(temp, "%d", i);
        strcat(number, temp);
    }

    // Create a list to store permutations
    int listSize = 1;
    for (int i = 1; i <= strlen(number); i++) {
        listSize *= i;
    }
    char **listA = (char **)malloc(listSize * sizeof(char *));
    int index = 0;

    // Generate all permutations of the number string
    permutation(listA, number, "", &index);

    // Initialize sum to calculate the result
    int sum = 0;

    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < listSize; i++) {
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

    // Free allocated memory
    for (int i = 0; i < listSize; i++) {
        free(listA[i]);
    }
    free(listA);

    return 0;
}
