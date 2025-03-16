#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_INPUT_SIZE 1000 

// Helper function to convert a space-separated string of integers into a Map
void str2List(char *str, int *vList, int *cList) { 
    // Split the input string into an array of strings
    char *vArrStr[MAX_INPUT_SIZE]; 
    char *cArrStr[MAX_INPUT_SIZE]; 
    int vArrSize = 0; 
    int cArrSize = 0; 
    int i = 0; 
    int j = 0; 
    
    // Populate the arrays with values from the string
    for (i = 0; i < MAX_INPUT_SIZE; i++) { 
        vArrStr[i] = strtok(str, " "); 
        if (vArrStr[i] == NULL) { 
            break; 
        } 
        vArrSize++; 
        str = NULL; 
    } 
    for (j = 0; j < MAX_INPUT_SIZE; j++) { 
        cArrStr[j] = strtok(str, " "); 
        if (cArrStr[j] == NULL) { 
            break; 
        } 
        cArrSize++; 
        str = NULL; 
    } 
    
    // Populate the vList and cList with values from the arrays
    for (i = 0; i < vArrSize; i++) { 
        vList[i] = atoi(vArrStr[i]); 
    } 
    for (j = 0; j < cArrSize; j++) { 
        cList[j] = atoi(cArrStr[j]); 
    } 
} 

// Main function to calculate the maximum profit
int main() { 
    // Declare variables to hold the input values
    int n; 
    char vStr[MAX_INPUT_SIZE]; 
    char cStr[MAX_INPUT_SIZE]; 
    
    // Declare variables to hold the values and costs
    int vList[MAX_INPUT_SIZE]; 
    int cList[MAX_INPUT_SIZE]; 
    
    // Declare a variable to keep track of the maximum profit
    int max = 0; 
    
    // Read the number of items (n) from the input
    scanf("%d", &n); 
    
    // Read the values (vStr) from the input and convert to a list
    scanf("%s", vStr); 
    str2List(vStr, vList, cList); 
    
    // Read the costs (cStr) from the input and convert to a list
    scanf("%s", cStr); 
    str2List(cStr, vList, cList); 
    
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

