#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 100000

int input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return c;
}

int read_int() {
    int num = 0;
    int c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return num;
}

int read_ints() {
    int nums[MAX_N];
    int c, i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            ungetc(c, stdin);
            scanf("%d", &nums[i]);
            i++;
        }
    }
    return i;
}

int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    int N = read_int();
    int a[MAX_N];
    for (int i = 0; i < N; i++) {
        a[i] = read_int();
    }

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
    } else if (max_sign == 1) {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 0; i < N - 1; i++) {
            printf("%d %d\n", i + 1, i + 2);
        }
    } else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = N - 1; i > 0; i--) {
            printf("%d %d\n", i + 1, i);
        }
    }

    return 0;
}
