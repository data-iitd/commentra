
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

int* scanNums(int len) {
    int* nums = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        int num;
        scanf("%d", &num);
        nums[i] = num;
    }
    return nums;
}

int pattern1(int* l) {
    int n = (l[0] * l[3]) + (l[1] * l[4]);
    return n;
}

int pattern2(int* l) {
    int n = 2 * l[2] * (l[3] > l[4]? l[3] : l[4]);
    return n;
}

int pattern3(int* l) {
    int n = 2 * l[2] * (l[3] < l[4]? l[3] : l[4]) + (l[3] > l[4]? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]));
    return n;
}

int min(int* nums, int len) {
    if (len == 0) {
        printf("funciton min() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = res < nums[i]? res : nums[i];
    }
    return res;
}

int max(int* nums, int len) {
    if (len == 0) {
        printf("funciton max() requires at least one argument.");
        exit(1);
    }
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = res > nums[i]? res : nums[i];
    }
    return res;
}

int doch(int* l) {
    return l[3] > l[4]? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]);
}

int main() {
    int len = 5;
    int* l = scanNums(len);
    int res = min(new int[]{pattern1(l), pattern2(l), pattern3(l)}, 3);
    printf("%d\n", res);
    return 0;
}

