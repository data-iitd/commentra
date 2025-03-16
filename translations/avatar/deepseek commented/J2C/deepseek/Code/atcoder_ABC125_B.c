#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to convert a string of space-separated integers into an array with index as key and integer value as value.
int* str2Array(char* str, int* size) {
    int capacity = 10;
    int* arr = (int*)malloc(capacity * sizeof(int));
    char* token = strtok(str, " ");
    int index = 0;

    while (token != NULL) {
        if (index >= capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
        arr[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    *size = index;
    return arr;
}

int main() {
    char nStr[100], vStr[100], cStr[100];
    int n, *vList, *cList;
    int max = 0;

    // Step 1: Read the input value `n` which represents the number of elements.
    fgets(nStr, sizeof(nStr), stdin);
    n = atoi(nStr);

    // Step 2: Read the values of `v` (values) and store them in an array `vList`.
    fgets(vStr, sizeof(vStr), stdin);
    int vSize;
    vList = str2Array(vStr, &vSize);

    // Step 3: Read the values of `c` (costs) and store them in an array `cList`.
    fgets(cStr, sizeof(cStr), stdin);
    int cSize;
    cList = str2Array(cStr, &cSize);

    // Step 4: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    // Step 5: Print the maximum profit.
    printf("%d\n", max);

    // Free allocated memory
    free(vList);
    free(cList);

    return 0;
}
