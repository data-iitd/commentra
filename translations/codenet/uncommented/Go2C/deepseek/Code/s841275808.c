#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ScanInt() {
    int i;
    scanf("%d", &i);
    return i;
}

float ScanFloat64() {
    float f;
    scanf("%f", &f);
    return f;
}

char* ScanText() {
    char* text = (char*)malloc(100 * sizeof(char));
    scanf("%s", text);
    return text;
}

int Max(int a, int b) {
    return a < b ? b : a;
}

int Min(int a, int b) {
    return a > b ? b : a;
}

int Abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    int N = ScanInt();
    int X[N], Y[N];
    for (int i = 0; i < N; i++) {
        X[i] = ScanInt();
        Y[i] = X[i];
    }

    qsort(Y, N, sizeof(int), (int (*)(const void *, const void *))compare);
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2);
        } else {
            printf("%d\n", m1);
        }
    }

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
