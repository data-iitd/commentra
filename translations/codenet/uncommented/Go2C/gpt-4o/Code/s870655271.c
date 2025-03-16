#include <stdio.h>
#include <math.h>

int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value > res) {
            res = value;
        }
    }
    va_end(args);
    return res;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value < res) {
            res = value;
        }
    }
    va_end(args);
    return res;
}

int pow_int(int x, int y) {
    return (int)pow((double)x, (double)y);
}

int abs_int(int x) {
    return (int)fabs((double)x);
}

int floor_int(int x) {
    return (int)floor((double)x);
}

int main() {
    int N, M;
    int ans = 0;
    scanf("%d %d", &N, &M);
    
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

/* <END-OF-CODE> */
