#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to convert a space-separated string of integers into an array
void str2List(char *str, int *arr, int *size) {
    char *token = strtok(str, " ");
    *size = 0;
    while (token != NULL) {
        arr[(*size)++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    int n;
    scanf("%d\n", &n); // Step 1: Read the input value `n`

    // Step 2: Read the values of `v` (values) and store them in an array `vList`.
    char vStr[MAX_SIZE];
    fgets(vStr, sizeof(vStr), stdin);
    int vList[MAX_SIZE];
    int vSize;
    str2List(vStr, vList, &vSize);

    // Step 3: Read the values of `c` (costs) and store them in an array `cList`.
    char cStr[MAX_SIZE];
    fgets(cStr, sizeof(cStr), stdin);
    int cList[MAX_SIZE];
    int cSize;
    str2List(cStr, cList, &cSize);

    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    int max = 0;

    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    // Step 6: Print the maximum profit.
    printf("%d\n", max);

    return 0;
}

// <END-OF-CODE>
