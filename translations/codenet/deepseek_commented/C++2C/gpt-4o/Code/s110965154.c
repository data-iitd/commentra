/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

// Step 1: Define the sort function
void sort(int* a_rvecIntValue, int size);

// Step 2: Main function
int main(void) {
    int iNum = 0;
    scanf("%d", &iNum);
    
    // Allocate memory for the array
    int* vecIntValue = (int*)malloc(iNum * sizeof(int));
    if (vecIntValue == NULL) {
        return 1; // Memory allocation failed
    }

    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]);
    }

    sort(vecIntValue, iNum);

    // Free allocated memory
    free(vecIntValue);
    
    return 0;
}

void sort(int* a_rvecIntValue, int size) {
    // Step 3: Sort function implementation
    for (int i = 0; i < size; i++) {
        // If it's not the first element, insert it in the correct position
        if (i != 0) {
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1;
            while (j >= 0 && a_rvecIntValue[j] > iIntValue) {
                a_rvecIntValue[j + 1] = a_rvecIntValue[j];
                j--;
            }
            a_rvecIntValue[j + 1] = iIntValue;
        }

        // Print the array after each insertion
        for (int k = 0; k < size; k++) {
            printf("%d", a_rvecIntValue[k]);
            if (k != size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Step 4: Output
// The program outputs the sorted array after each insertion.

