/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */
#include <stdio.h>
#include <stdlib.h>

void sort(int* a_rvecIntValue, int size);

int main(void) {
    int iNum = 0;
    scanf("%d", &iNum);
    int* vecIntValue = (int*)malloc(iNum * sizeof(int));
    
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &vecIntValue[i]);
    }

    sort(vecIntValue, iNum);
    
    free(vecIntValue);
    return 0;
}

void sort(int* a_rvecIntValue, int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (i != 0) {
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1;
            while (j >= 0 && a_rvecIntValue[j] > iIntValue) {
                a_rvecIntValue[j + 1] = a_rvecIntValue[j];
                j--;
            }
            a_rvecIntValue[j + 1] = iIntValue;
        }

        for (unsigned int k = 0; k < size; k++) {
            printf("%d", a_rvecIntValue[k]);
            if (k != size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* <END-OF-CODE> */
