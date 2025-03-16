
#include <stdio.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Function to read multiple integers from standard input
void scanNums(int len, int *nums) {
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }
}

// Function to calculate the first pattern
int pattern1(int *l) {
    int n = (l[0]*l[3])+(l[1]*l[4]);
    return n;
}

// Function to calculate the second pattern
int pattern2(int *l) {
    int maxNum = (l[3] > l[4])? l[3] : l[4];
    int n = 2 * l[2] * maxNum;
    return n;
}

// Function to calculate the third pattern
int pattern3(int *l) {
    int minNum = (l[3] < l[4])? l[3] : l[4];
    int n = 2 * l[2] * minNum + doch(l);
    return n;
}

// Function to find the minimum of a list of numbers
int min(int *nums, int len) {
    if (len == 0) {
        printf("function min() requires at least one argument.");
        return -1;
    }
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = (res < nums[i])? res : nums[i];
    }
    return res;
}

// Function to find the maximum of a list of numbers
int max(int *nums, int len) {
    if (len == 0) {
        printf("function max() requires at least one argument.");
        return -1;
    }
    int res = nums[0];
    for (int i = 0; i < len; i++) {
        res = (res > nums[i])? res : nums[i];
    }
    return res;
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(int *l) {
    return (l[3] > l[4])? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]);
}

// Main function to read input and call the pattern functions
int main() {
    int len = 5;
    int l[len];
    scanNums(len, l);
    int minN = min(&pattern1(l), 3);
    minN = (minN < min(&pattern2(l), 3))? minN : min(&pattern2(l), 3);
    minN = (minN < min(&pattern3(l), 3))? minN : min(&pattern3(l), 3);
    printf("%d\n", minN);
    return 0;
}
