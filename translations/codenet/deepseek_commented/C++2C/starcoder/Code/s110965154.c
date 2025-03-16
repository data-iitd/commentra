#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Step 1: Include necessary headers
// The code includes <stdio.h>, <stdlib.h> and <string.h> which are necessary for input and string operations.

void sort(int* a_parrIntValue, int a_iNum);

// Step 2: Define the sort function
// The `sort` function is defined to take a pointer to an array of integers and the number of integers.

int main(void) {

    // Step 3: Main function
    // The main function reads the number of integers to be sorted.
    // It then reads each integer and stores them in an array.
    // It calls the `sort` function with the array.

    int iNum = 0;
    scanf("%d", &iNum);
    int* parrIntValue = (int*)malloc(sizeof(int) * iNum);
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &parrIntValue[i]);
    }

    sort(parrIntValue, iNum);

    return 0;
}

void sort(int* a_parrIntValue, int a_iNum) {

    // Step 4: Sort function implementation
    // The sort function uses the insertion sort algorithm.
    // It iterates through the array, inserting each element in the correct position.
    // It prints the array after each insertion to show the progress of the sorting process.

    for (int i = 0; i < a_iNum; i++) {

        // If it's not the first element, insert it in the correct position
        if (i!= 0) {
            int iIntValue = a_parrIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_parrIntValue[j] > iIntValue)) {
                a_parrIntValue[j+1] = a_parrIntValue[j];
                j--;
            }
            a_parrIntValue[j+1] = iIntValue;
        }

        // Print the array after each insertion
        for (int k = 0; k < a_iNum; k++) {
            printf("%d", a_parrIntValue[k]);
            if (k!= a_iNum - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Step 5: Output
// The program outputs the sorted array after each insertion.

