#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Define a maximum size for the arrays

// Function to convert a space-separated string to an array of integers
void str2List(char *str, int *arr, int *size) {
    char *token = strtok(str, " ");
    *size = 0;
    while (token != NULL) {
        arr[(*size)++] = atoi(token); // Convert string to integer and store in array
        token = strtok(NULL, " ");
    }
}

int main() {
    int n; // Number of elements
    scanf("%d\n", &n); // Read the number of elements

    char vStr[MAX_SIZE]; // String for values
    fgets(vStr, sizeof(vStr), stdin); // Read the values string

    char cStr[MAX_SIZE]; // String for costs
    fgets(cStr, sizeof(cStr), stdin); // Read the costs string

    int vList[MAX_SIZE]; // Array for values
    int cList[MAX_SIZE]; // Array for costs
    int vSize, cSize;

    str2List(vStr, vList, &vSize); // Convert values string to array
    str2List(cStr, cList, &cSize); // Convert costs string to array

    int max = 0; // Initialize max to 0

    for (int i = 0; i < n; i++) { // Iterate through each element
        int profit = vList[i] - cList[i]; // Calculate profit
        if (profit > 0) { // Check if profit is positive
            max += profit; // Add to max if positive
        }
    }

    printf("%d\n", max); // Print the maximum profit

    return 0; // Return success
}

// <END-OF-CODE>
