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
 
    for (int i = 0; i < a_iSize; i++) {
 
        if (i != 0) {
 
            int iIntValue = a_rvecIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_rvecIntValue[j] > iIntValue)) {
                a_rvecIntValue[j+1] = a_rvecIntValue[j];
                j--;
            }
            a_rvecIntValue[j+1] = iIntValue;
        }
 
        for (int k = 0; k < a_iSize; k++) {
            printf("%d", a_rvecIntValue[k]);
            if (k != a_iSize - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

