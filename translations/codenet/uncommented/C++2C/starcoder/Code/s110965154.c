#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void sort(int* a_parrIntValue, int a_iNum);
 
int main(void) {
 
    int iNum = 0;
    scanf("%d", &iNum);
    int* parrIntValue = (int*)malloc(sizeof(int) * iNum);
    while (iNum) {
        int iIntValue = 0;
        scanf("%d", &iIntValue);
        parrIntValue[iNum-1] = iIntValue;
        iNum--;
    }
 
    sort(parrIntValue, iNum);
 
    return 0;
}
 
void sort(int* a_parrIntValue, int a_iNum) {
 
    for (int i = 0; i < a_iNum; i++) {
 
        if (i!= 0) {
 
            int iIntValue = a_parrIntValue[i];
            int j = i - 1;
            while ((j >= 0) && (a_parrIntValue[j] > iIntValue)) {
                a_parrIntValue[j+1] = a_parrIntValue[j];
                j--;
            }
            a_parrIntValue[j+1] = iIntValue;
        }
 
        for (int k = 0; k < a_iNum; k++) {
            printf("%d", a_parrIntValue[k]);
            if (k!= a_iNum - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
