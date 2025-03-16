
#include <stdio.h>
#include <limits.h>

int checKNo(int brr[], int n);

int main() {
    int n, arr[100], max = INT_MIN;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int brr[100], x = 0;
            for (int k = 0; k < n; k++)
                brr[x++] = arr[k];
            for (int k = i; k <= j; k++) {
                if (brr[k] == 0)
                    brr[k] = 1;
                else
                    brr[k] = 0;
            }
            int count = checKNo(brr, n);
            if (count > max)
                max = count;
        }
    }
    if (n == 1) {
        if (arr[0] == 1)
            printf("0");
        else
            printf("1");
    } else {
        printf("%d", max);
    }
    return 0;
}

int checKNo(int brr[], int n) {
    int val = 0;
    for (int i = 0; i < n; i++)
        if (brr[i] == 1)
            val++;
    return val;
}

