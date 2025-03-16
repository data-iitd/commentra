
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read an array of integers from standard input
    int arr[100];
    int i = 0;
    char input[1000];
    fgets(input, 1000, stdin);
    char *token = strtok(input, " ");
    while (token!= NULL) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    // Assign the first two elements of the array to variables a and b
    int a = arr[0];
    int b = arr[1];
    // Initialize the number of taps needed to 0
    int tap = 0;
    // Initialize the consent variable to 1 (the starting point)
    int consent = 1;
    
    // Loop until the consent value is less than b
    while (consent < b) {
        // Update consent by adding (a - 1) to it
        consent = consent + a - 1;
        // Increment the tap count
        tap++;
    }
    
    // Print the total number of taps needed
    printf("%d\n", tap);
    return 0;
}

// Function to scan an array of integers from standard input
int* scanArrayInt() {
    int arr[100];
    int i = 0;
    char input[1000];
    fgets(input, 1000, stdin);
    char *token = strtok(input, " ");
    while (token!= NULL) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    return arr;
}

