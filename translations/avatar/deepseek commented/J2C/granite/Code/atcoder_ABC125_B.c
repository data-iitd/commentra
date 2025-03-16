

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Read the input value `n` which represents the number of elements.
    int n;
    scanf("%d", &n);

    // Step 2: Read the values of `v` (values) and store them in a list `vList`.
    char vStr[1000];
    fgets(vStr, 1000, stdin);
    char *token = strtok(vStr, " ");
    int *vList = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        vList[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    char cStr[1000];
    fgets(cStr, 1000, stdin);
    token = strtok(cStr, " ");
    int *cList = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        cList[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    int max = 0;

    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for (i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    // Step 6: Print the maximum profit.
    printf("%d\n", max);

    // Free memory
    free(vList);
    free(cList);

    return 0;
}
