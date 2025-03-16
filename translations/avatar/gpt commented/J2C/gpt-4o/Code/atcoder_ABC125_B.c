#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

// Function to convert a space-separated string of integers into an array
void str2List(char *str, int *arr, int *size) {
    char *token = strtok(str, " ");
    *size = 0;
    
    while (token != NULL) {
        arr[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, " ");
    }
}

int main() {
    // Read the number of items (n) from the input
    int n;
    scanf("%d\n", &n);
    
    // Read the values (vStr) from the input
    char vStr[1000];
    fgets(vStr, sizeof(vStr), stdin);
    
    // Read the costs (cStr) from the input
    char cStr[1000];
    fgets(cStr, sizeof(cStr), stdin);
    
    // Arrays to hold the values and costs
    int vList[MAX_ITEMS];
    int cList[MAX_ITEMS];
    int vSize, cSize;
    
    // Convert the input strings to arrays
    str2List(vStr, vList, &vSize);
    str2List(cStr, cList, &cSize);
    
    // Initialize a variable to keep track of the maximum profit
    int max = 0;
    
    // Calculate the profit for each item and sum up the positive profits
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        // Only add to max if the profit is positive
        if (profit > 0) {
            max += profit;
        }
    }
    
    // Output the total maximum profit
    printf("%d\n", max);
    
    return 0;
}

// <END-OF-CODE>
