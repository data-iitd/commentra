#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int doch(int l[]) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

int pattern1(int l[]) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

int pattern2(int l[]) {
    return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(int l[]) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

int main() {
    int l[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &l[i]);
    }
    
    int result = min(pattern1(l), min(pattern2(l), pattern3(l)));
    printf("%d\n", result);
    
    return 0;
}

// <END-OF-CODE>
