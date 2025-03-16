#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int read_int() {
    int num;
    scanf("%d", &num);
    return num;
}

int* read_ints() {
    int* arr = (int*)malloc(sizeof(int) * 100000);
    int n = read_int();
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    int N = read_int();
    int* a = read_ints();

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        printf("0\n");
    } else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        if (max_sign == 1) {
            for (int i = 0; i < N - 1; i++) {
                printf("%d %d\n", i + 1, i + 2);
            }
        } else {
            for (int i = 0; i < N - 1; i++) {
                printf("%d %d\n", i + 2, i + 1);
            }
        }
    }

    return 0;
}
