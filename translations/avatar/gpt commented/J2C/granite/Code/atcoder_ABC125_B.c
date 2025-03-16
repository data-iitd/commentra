
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the console
    char input[1000];
    fgets(input, 1000, stdin);

    // Read the number of items (n) from the input
    int n = atoi(input);

    // Read the values (vStr) from the input and convert to a list
    fgets(input, 1000, stdin);
    char *vStr = input;
    char *token = strtok(vStr, " ");
    int *vList = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (token!= NULL) {
        vList[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    // Read the costs (cStr) from the input and convert to a list
    fgets(input, 1000, stdin);
    char *cStr = input;
    token = strtok(cStr, " ");
    int *cList = (int *)malloc(n * sizeof(int));
    i = 0;
    while (token!= NULL) {
        cList[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    // Initialize a variable to keep track of the maximum profit
    int max = 0;

    // Calculate the profit for each item and sum up the positive profits
    for (i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        // Only add to max if the profit is positive
        if (profit > 0) {
            max += profit;
        }
    }

    // Output the total maximum profit
    printf("%d\n", max);

    // Free the memory allocated for the lists
    free(vList);
    free(cList);

    return 0;
}
