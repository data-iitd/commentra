/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

// Function prototype for the sorting function
void sort(int* a_rvecIntValue, int a_iNum);

int main(void) {
    // Variable to hold the number of integers to be sorted
    int iNum = 0;
    // Read the number of integers from standard input
    scanf("%d", &iNum);
    
    // Vector to store the integers
    int* vecIntValue = (int*)malloc(iNum * sizeof(int));
    
    // Loop to read integers from input and store them in the vector
    while (iNum) {
        int iIntValue = 0;
        scanf("%d", &iIntValue); // Read an integer
        vecIntValue[iNum - 1] = iIntValue; // Add the integer to the vector
        iNum--; // Decrement the count of integers to read
    }

    // Call the sort function to sort the vector of integers
    sort(vecIntValue, iNum);

    return 0; // Exit the program
}

// Function to perform insertion sort on the vector of integers
void sort(int* a_rvecIntValue, int a_iNum) {
    // Iterate through each element in the vector
    for (int i = 0; i < a_iNum; i++) {
        // Check if we are not at the first element
        if (i != 0) {
            // Store the current element to be inserted
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1; // Start comparing with the previous element
            
            // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
            // to one position ahead of their current position
            while ((j >= 0) && (a_rvecIntValue[j] > iIntValue)) {
                a_rvecIntValue[j + 1] = a_rvecIntValue[j]; // Shift element to the right
                j--; // Move to the previous element
            }
            // Place the current element at its correct position
            a_rvecIntValue[j + 1] = iIntValue;
        }

        // Print the current state of the sorted portion of the vector
        for (int k = 0; k < a_iNum; k++) {
            printf("%d ", a_rvecIntValue[k]); // Output the element
            // Print a space between elements, but not after the last element
            if (k != a_iNum - 1) {
                printf(" ");
            }
        }
        printf("\n"); // New line after printing the current state
    }
}

