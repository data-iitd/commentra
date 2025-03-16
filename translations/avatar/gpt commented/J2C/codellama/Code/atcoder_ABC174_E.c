#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

#define MAX_INPUT 1000000 

// Structure to store the input
typedef struct { 
    int n, k; 
    int logsLength[MAX_INPUT]; 
} Input; 

// Function to read the input
void readInput(Input *input) { 
    scanf("%d %d", &input->n, &input->k); 
    for (int i = 0; i < input->n; ++i) 
        scanf("%d", &input->logsLength[i]); 
} 

// Function to perform binary search
int binarySearch(Input *input) { 
    int min = 1, max = (int) 1e9 + 1000; 
    while (min < max) { 
        int mid = (min + max) / 2; 
        if (nei(mid, input->logsLength, input->k)) 
            max = mid; 
        else 
            min = mid + 1; 
    } 
    return min; 
} 

// Function to determine if logs can be cut with the given mid length
bool nei(int mid, int logsLength[], int k) { 
    for (int i = 0; i < k; ++i) 
        k -= (logsLength[i] + mid - 1) / mid - 1; 
    return k >= 0; 
} 

// Function to print the output
void printOutput(int min) { 
    printf("%d\n", min); 
} 

// Main function
int main() { 
    Input input; 
    readInput(&input); 
    printOutput(binarySearch(&input)); 
    return 0; 
} 

