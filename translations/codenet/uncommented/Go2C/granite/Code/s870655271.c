
#include <stdio.h>
#include <math.h>

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

/*  ----------------------------------------  */

int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val > res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 100; i++) {
        int val = va_arg(args, int);
        if (val < res) {
            res = val;
        }
    }
    va_end(args);
    return res;
}

int pow(int x, int y) { return (int)pow(x, y); }

int abs(int x) { return (x < 0)? -x : x; }

int floor(int x) { return (int)floor(x); }

typedef struct {
    int *arr;
    int size;
} SortBy;

int sortByLen(const void *a, const void *b) {
    return abs(((SortBy *)a)->arr[0]) - abs(((SortBy *)b)->arr[0]);
}

