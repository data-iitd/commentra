#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000

int readInt() {
    char c;
    int n = 0;
    while ((c = getchar()) >= '0' && c <= '9') {
        n = n * 10 + (c - '0');
    }
    return n;
}

double average(double *s, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += s[i];
    }
    return sum / size;
}

double diff(double a, double b) {
    return fabs(a - b);
}

int main() {
    int n = readInt();
    double a[n];
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }

    double ave = average(a, n);

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double diffValue = diff(a[i], ave);
        if (diffValue < minDiff) {
            minDiff = diffValue;
            ansIndex = i;
        }
    }
    printf("%d\n", ansIndex);
    return 0;
}
