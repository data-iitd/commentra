
#include <stdio.h>
#include <math.h>

int nextInt();
int* scanNums(int len);
int pattern1(int* l);
int pattern2(int* l);
int pattern3(int* l);
int min(int n,...);
int max(int n,...);
int doch(int* l);

int main() {
    int len = 5;
    int* l = scanNums(len);
    printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));
    return 0;
}

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* scanNums(int len) {
    int* nums = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        nums[i] = nextInt();
    }
    return nums;
}

int pattern1(int* l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

int pattern2(int* l) {
    return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int* l) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

int min(int n,...) {
    va_list args;
    int res = n;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        res = num < res? num : res;
    }
    va_end(args);
    return res;
}

int max(int n,...) {
    va_list args;
    int res = n;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        res = num > res? num : res;
    }
    va_end(args);
    return res;
}

int doch(int* l) {
    return l[3] > l[4]? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]);
}

