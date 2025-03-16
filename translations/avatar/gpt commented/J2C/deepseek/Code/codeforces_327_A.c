#include <stdio.h>
#include <limits.h>

int checkNo(int* brr, int n) {
    int val = 0;
    for (int i = 0; i < n; i++)
        if (brr[i] == 1)
            val++;
    return val;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int brr[n];
                for (int k = 0; k < n; k++)
                    brr[k] = arr[k];

                for (int k = i; k <= j; k++) {
                    if (brr[k] == 0)
                        brr[k] = 1;
                    else
                        brr[k] = 0;
                }

                int count = checkNo(brr, n);
                if (count > max)
                    max = count;
            }
        }

        if (n == 1) {
            if (arr[0] == 1)
                printf("0\n");
            else
                printf("1\n");
        } else {
            printf("%d\n", max);
        }
    }
