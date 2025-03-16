#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int nums[], int len) {
    if (len == 0) {
        fprintf(stderr, "Function min() requires at least one argument.\n");
        exit(EXIT_FAILURE);
    }
    int res = nums[0];
    for (int i = 1; i < len; i++) {
        res = fmin(res, nums[i]);
    }
    return res;
}

int max(int nums[], int len) {
    if (len == 0) {
        fprintf(stderr, "Function max() requires at least one argument.\n");
        exit(EXIT_FAILURE);
    }
    int res = nums[0];
    for (int i = 1; i < len; i++) {
        res = fmax(res, nums[i]);
    }
    return res;
}

int pattern1(int l[]) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

int pattern2(int l[]) {
    return 2 * l[2] * fmax(l[3], l[4]);
}

int pattern3(int l[]) {
    return 2 * l[2] * fmin(l[3], l[4]) + doch(l);
}

int doch(int l[]) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

int main() {
    int len = 5;
    int l[5];
    for (int i = 0; i < len; i++) {
        scanf("%d", &l[i]);
    }
    int result = min(pattern1(l), pattern2(l), pattern3(l));
    printf("%d\n", result);
    return 0;
}
