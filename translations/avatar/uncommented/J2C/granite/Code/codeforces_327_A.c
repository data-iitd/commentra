
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x = 0;
            int brr[n];
            for (int k = 0; k < n; k++) {
                brr[x++] = arr[k];
            }
            for (int k = i; k <= j; k++) {
                if (brr[k] == 0) {
                    brr[k] = 1;
                } else {
                    brr[k] = 0;
                }
            }
            int count = checkNo(brr);
            if (count > max) {
                max = count;
            }
        }
    }
    if (n == 1) {
        if (arr[0] == 1) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else {
        printf("%d\n", max);
    }
    return 0;
}

int checkNo(int brr[]) {
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (brr[i] == 1) {
            val++;
        }
    }
    return val;
}

