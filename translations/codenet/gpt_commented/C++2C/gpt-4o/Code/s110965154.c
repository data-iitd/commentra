/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

// Function prototype for the sorting function
void sort(int* a_rvecIntValue, int size);

int main(void) {
    // Variable to hold the number of integers to be sorted
    int iNum = 0;
    // Read the number of integers from standard input
    scanf("%d", &iNum);
    
<<<<<<< HEAD
    // Dynamically allocate an array to store the integers
=======
    // Dynamically allocate memory for the integers
>>>>>>> 98c87cb78a (data updated)
    int* vecIntValue = (int*)malloc(iNum * sizeof(int));
    
    // Loop to read integers from input and store them in the array
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]); // Read an integer
    }

    // Call the sort function to sort the array of integers
    sort(vecIntValue, iNum);

    // Free the allocated memory
    free(vecIntValue);

    return 0; // Exit the program
}

// Function to perform insertion sort on the array of integers
void sort(int* a_rvecIntValue, int size) {
    // Iterate through each element in the array
<<<<<<< HEAD
    for (int i = 0; i < size; i++) {
        // Check if we are not at the first element
        if (i != 0) {
            // Store the current element to be inserted
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1; // Start comparing with the previous element
            
            // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
            // to one position ahead of their current position
            while (j >= 0 && a_rvecIntValue[j] > iIntValue) {
                a_rvecIntValue[j + 1] = a_rvecIntValue[j]; // Shift element to the right
                j--; // Move to the previous element
            }
            // Place the current element at its correct position
            a_rvecIntValue[j + 1] = iIntValue;
        }
=======
    for (int i = 1; i < size; i++) {
        // Store the current element to be inserted
        int iIntValue = a_rvecIntValue[i];
        int j = i - 1; // Start comparing with the previous element
        
        // Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
        // to one position ahead of their current position
        while (j >= 0 && a_rvecIntValue[j] > iIntValue) {
            a_rvecIntValue[j + 1] = a_rvecIntValue[j]; // Shift element to the right
            j--; // Move to the previous element
        }
        // Place the current element at its correct position
        a_rvecIntValue[j + 1] = iIntValue;
>>>>>>> 98c87cb78a (data updated)

        // Print the current state of the sorted portion of the array
        for (int k = 0; k < size; k++) {
            printf("%d", a_rvecIntValue[k]); // Output the element
            // Print a space between elements, but not after the last element
            if (k != size - 1) {
                printf(" ");
            }
        }
        printf("\n"); // New line after printing the current state
    }
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
