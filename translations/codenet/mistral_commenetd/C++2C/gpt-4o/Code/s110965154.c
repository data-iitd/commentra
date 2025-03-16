/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in ascending order using insertion sort algorithm
void sort(int* a_rvecIntValue, int size);

int main(void) {
    int iNum = 0; // Initialize a variable to store the number of elements in the array
    scanf("%d", &iNum); // Read the number of elements from the standard input

    int* vecIntValue = (int*)malloc(iNum * sizeof(int)); // Create an array to store the integers
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]); // Read the next integer from the standard input
    }

    // Call the sorting function to sort the array
    sort(vecIntValue, iNum);

    free(vecIntValue); // Free the allocated memory
    return 0;
}

void sort(int* a_rvecIntValue, int size) {
    // Iterate through each element in the array starting from the second element
    for (int i = 1; i < size; i++) {
        int iIntValue = a_rvecIntValue[i]; // Get the value of the current element
        int j = i - 1; // Initialize a variable to store the index of the previous element
        while (j >= 0 && a_rvecIntValue[j] > iIntValue) { // While the previous element is greater than the current element
            a_rvecIntValue[j + 1] = a_rvecIntValue[j]; // Swap the previous and next elements
            j--; // Decrement the index of the previous element
        }
        a_rvecIntValue[j + 1] = iIntValue; // Place the current element at its correct position

        // Print the sorted array after each insertion
        for (int k = 0; k < size; k++) {
            printf("%d", a_rvecIntValue[k]); // Print the value of the current element
            if (k != size - 1) { // Check if we are not at the last element
                printf(" "); // Print a space if not
            }
        }
        printf("\n"); // Print a newline after each pass
    }
}

/* <END-OF-CODE> */
