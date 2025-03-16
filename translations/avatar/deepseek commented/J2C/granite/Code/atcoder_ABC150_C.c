

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generates all permutations of a given string
void permutation(char* target, char* ans, int start, int end, char** list, int* size) {
    if (start == end) {
        list[*size] = (char*)malloc(strlen(ans) + 1);
        strcpy(list[*size], ans);
        (*size)++;
    } else {
        for (int i = start; i <= end; i++) {
            char temp = target[start];
            target[start] = target[i];
            target[i] = temp;
            permutation(target, strcat(ans, &target[start]), start + 1, end, list, size);
            temp = target[start];
            target[start] = target[i];
            target[i] = temp;
        }
    }
}

int main() {
    // Read the number of strings
    int n;
    scanf("%d", &n);
    // Initialize a 2D array to store the input strings
    char* line[2][1];
    for (int i = 0; i < 2; i++) {
        line[i][0] = (char*)malloc(1);
        line[i][0][0] = '\0';
        // Read n strings and concatenate them
        for (int j = 0; j < n; j++) {
            char* str = (char*)malloc(10);
            scanf("%s", str);
            line[i][0] = (char*)realloc(line[i][0], strlen(line[i][0]) + strlen(str) + 1);
            strcat(line[i][0], str);
            free(str);
        }
    }
    // Generate the number string for permutations
    char* number = (char*)malloc(n + 1);
    for (int i = 1; i <= n; i++) {
        number[i - 1] = '0' + i;
    }
    number[n] = '\0';
    // Create a list to store permutations
    char** listA = (char**)malloc(n! * sizeof(char*));
    int size = 0;
    // Generate all permutations of the number string
    permutation(number, "", 0, n - 1, listA, &size);
    // Initialize sum to calculate the result
    int sum = 0;
    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < size; i++) {
            if (strcmp(listA[i], line[j][0]) == 0) {
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
    // Free memory
    for (int i = 0; i < size; i++) {
        free(listA[i]);
    }
    free(listA);
    free(number);
    for (int i = 0; i < 2; i++) {
        free(line[i][0]);
    }
    return 0;
}

