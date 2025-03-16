#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

typedef struct {
    int key;
    int value;
} Pair;

Pair* str2List(char* str, int* size) {
    Pair* ret = (Pair*)malloc(MAX_ITEMS * sizeof(Pair));
    char* token = strtok(str, " ");
    int index = 0;

    while (token != NULL) {
        ret[index].value = atoi(token);
        token = strtok(NULL, " ");
        index++;
    }

    *size = index;
    return ret;
}

int main() {
    char nStr[100], vStr[1000], cStr[1000];
    int n, vSize, cSize;
    Pair* vList;
    Pair* cList;
    int max = 0;

    // Read the number of items (n) from the input
    fgets(nStr, sizeof(nStr), stdin);
    n = atoi(nStr);

    // Read the values (vStr) from the input
    fgets(vStr, sizeof(vStr), stdin);
    vList = str2List(vStr, &vSize);

    // Read the costs (cStr) from the input
    fgets(cStr, sizeof(cStr), stdin);
    cList = str2List(cStr, &cSize);

    // Calculate the profit for each item and sum up the positive profits
    for (int i = 0; i < n; i++) {
        int profit = vList[i].value - cList[i].value;
        // Only add to max if the profit is positive
        if (profit > 0) {
            max += profit;
        }
    }

    // Output the total maximum profit
    printf("%d\n", max);

    // Free allocated memory
    free(vList);
    free(cList);

    return 0;
}
