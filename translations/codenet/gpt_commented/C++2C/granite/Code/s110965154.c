
/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
#include <stdio.h>

// Function prototype for the sorting function
void sort(int a_vecIntValue[], int a_iVecSize);

int main(void) {
    // Variable to hold the number of integers to be sorted
    int iNum = 0;
    // Read the number of integers from standard input
    scanf("%d", &iNum);
    
    // Array to store the integers
    int vecIntValue[iNum];
    
    // Loop to read integers from input and store them in the array
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]); // Read an integer
    }

    // Call the sort function to sort the array of integers
    sort(vecIntValue, iNum);

    return 0; // Exit the program
}

// Function to perform insertion sort on the array of integers
void sort(int a_vecIntValue[], int a_iVecSize) {
    // Iterate through each element in the array
    for (int i = 0; i < a_iVecSize; i++) {
        // Check if we are not at the first element
        if (i!= 0) {
            // Store the current element to be inserted
            int iIntValue = a_vecIntValue[i];
            int j = i - 1; // Start comparing with the previous element
            
            // Move elements of a_vecIntValue[0..i-1], that are greater than iIntValue,
            // to one position ahead of their current position
            while ((j >= 0) && (a_vecIntValue[j] > iIntValue)) {
                a_vecIntValue[j + 1] = a_vecIntValue[j]; // Shift element to the right
                j--; // Move to the previous element
            }
            // Place the current element at its correct position
            a_vecIntValue[j + 1] = iIntValue;
        }

        // Print the current state of the sorted portion of the array
        for (int k = 0; k < a_iVecSize; k++) {
            printf("%d", a_vecIntValue[k]); // Output the element
            // Print a space between elements, but not after the last element
            if (k!= a_iVecSize - 1) {
                printf(" ");
            }
        }
        printf("\n"); // New line after printing the current state
    }
}

