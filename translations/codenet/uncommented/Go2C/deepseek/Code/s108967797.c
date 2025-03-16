#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int n = 0;
    char ch;
    while ((ch = getchar_unlocked()) >= '0') {
        n = n * 10 + ch - '0';
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
    return (a > b) ? (a - b) : (b - a);
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
