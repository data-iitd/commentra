
/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
#include <stdio.h>

void sort(int a_vecIntValue[], int a_iVecSize);

int main(void) {

    int iNum = 0;
    scanf("%d", &iNum);
    int vecIntValue[iNum];
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]);
    }

    sort(vecIntValue, iNum);

    return 0;
}

void sort(int a_vecIntValue[], int a_iVecSize) {

    for (int i = 0; i < a_iVecSize; i++) {

        if (i!= 0) {
            int iIntValue = a_vecIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_vecIntValue[j] > iIntValue)) {
                a_vecIntValue[j+1] = a_vecIntValue[j];
                j--;
            }
            a_vecIntValue[j+1] = iIntValue;
        }

        for (int k = 0; k < a_iVecSize; k++) {
            printf("%d", a_vecIntValue[k]);
            if (k!= a_iVecSize - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Step 5: Output
// The program outputs the sorted vector after each insertion.

