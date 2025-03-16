

/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
#include <stdio.h>
#include <stdlib.h>
 
// Function to sort the array in ascending order using insertion sort algorithm
void sort(int a_rvecIntValue[], int a_iSize);
 
int main(void) {
 
    int iNum = 0; // Initialize a variable to store the number of elements in the array
    scanf("%d", &iNum); // Read the number of elements from the standard input
 
    int *vecIntValue = (int*)malloc(sizeof(int) * iNum); // Create an empty array to store the integers
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]); // Read the next integer from the standard input
    }
 
    // Call the sorting function to sort the array
    sort(vecIntValue, iNum);
 
    // Print the sorted array after each insertion
    for (int i = 0; i < iNum; i++) {
        printf("%d", vecIntValue[i]); // Print the value of the current element
        if (i!= iNum - 1) { // Check if we are not at the last element
            printf(" "); // Print a space if not
        }
    }
    printf("\n"); // Print a newline after each pass
 
    free(vecIntValue); // Free the memory allocated for the array
    return 0;
}
 
void sort(int a_rvecIntValue[], int a_iSize) {
 
    // Iterate through each element in the array starting from the second element
    for (int i = 0; i < a_iSize; i++) {
        if (i!= 0) { // Check if we are not at the first element
 
            int iIntValue = a_rvecIntValue[i]; // Get the value of the current element
            int j = i - 1; // Initialize a variable to store the index of the previous element
            while ((j >= 0) && (a_rvecIntValue[j] > iIntValue)) { // While the previous element is greater than the current element
                a_rvecIntValue[j+1] = a_rvecIntValue[j]; // Swap the previous and next elements
                j--; // Decrement the index of the previous element
            }
            a_rvecIntValue[j+1] = iIntValue; // Place the current element at its correct position
        }
 
        // Print the sorted array after each insertion
        for (int k = 0; k < a_iSize; k++) {
            printf("%d", a_rvecIntValue[k]); // Print the value of the current element
            if (k!= a_iSize - 1) { // Check if we are not at the last element
                printf(" "); // Print a space if not
            }
        }
        printf("\n"); // Print a newline after each pass
    }
}
