/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

void sort(int* a_rvecIntValue, int a_iSize);

int main(void) {

    // Step 3: Main function
    // The main function reads the number of integers to be sorted.
    // It then reads each integer and stores them in a vector.
    // It calls the `sort` function with the vector.

    int iNum = 0;
    scanf("%d", &iNum);
    int* vecIntValue = (int*)malloc(iNum * sizeof(int));
    while (iNum) {
        int iIntValue = 0;
        scanf("%d", &iIntValue);
        vecIntValue[iNum - 1] = iIntValue;
        iNum--;
    }

    sort(vecIntValue, iNum);

    return 0;
}

void sort(int* a_rvecIntValue, int a_iSize) {

    // Step 4: Sort function implementation
    // The sort function uses the insertion sort algorithm.
    // It iterates through the vector, inserting each element in the correct position.
    // It prints the vector after each insertion to show the progress of the sorting process.

    for (int i = 0; i < a_iSize; i++) {

        // If it's not the first element, insert it in the correct position
        if (i != 0) {
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_rvecIntValue[j] > iIntValue)) {
                a_rvecIntValue[j+1] = a_rvecIntValue[j];
                j--;
            }
            a_rvecIntValue[j+1] = iIntValue;
        }

        // Print the vector after each insertion
        for (int k = 0; k < a_iSize; k++) {
            printf("%d ", a_rvecIntValue[k]);
        }
        printf("\n");
    }
}

// Step 5: Output
// The program outputs the sorted vector after each insertion.

