
/*
 * InsertionSort.c
 *
 *  Created on: 2014/07/25
 *      Author: Wanwan1985
 */
#include <stdio.h>
#include <stdlib.h>
 
void sort(int *a_pvecIntValue, int a_iVecSize);
 
int main(void) {
 
    int iNum = 0;
    scanf("%d", &iNum);
    int *pvecIntValue = (int*)malloc(sizeof(int) * iNum);
    for (int i = 0; i < iNum; i++) {
        scanf("%d", &pvecIntValue[i]);
    }
 
    sort(pvecIntValue, iNum);
 
    return 0;
}
 
void sort(int *a_pvecIntValue, int a_iVecSize) {
 
    for (int i = 0; i < a_iVecSize; i++) {
 
        if (i!= 0) {
 
            int iIntValue = a_pvecIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_pvecIntValue[j] > iIntValue)) {
                a_pvecIntValue[j+1] = a_pvecIntValue[j];
                j--;
            }
            a_pvecIntValue[j+1] = iIntValue;
        }
 
        for (int k = 0; k < a_iVecSize; k++) {
            printf("%d", a_pvecIntValue[k]);
            if (k!= a_iVecSize - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
