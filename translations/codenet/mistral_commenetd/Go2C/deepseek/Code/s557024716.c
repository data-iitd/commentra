#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 1LL << 60
#define INF_INT32 1 << 30
#define NIL -1

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int readInt3() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    return a, b, c;
}

int readIntSlice(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

char* readString() {
    static char buffer[100000];
    scanf("%s", buffer);
    return buffer;
}

double readFloat64() {
    double value;
    scanf("%lf", &value);
    return value;
}

double readFloat64Slice(int n, double *arr) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    return 0;
}

void printIntsLine(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int* duplicatePatterns(int* elems, int k, int* returnSize) {
    int n = elems[0];
    int totalPatterns = pow(n, k);
    int* patterns = (int*)malloc(totalPatterns * sizeof(int));
    for (int i = 0; i < totalPatterns; i++) {
        patterns[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        int patternSize = pow(n, k - i - 1);
        int index = 0;
        for (int j = 0; j < totalPatterns; j++) {
            patterns[j] += elems[i] * patternSize;
            index++;
            if (index == patternSize) {
                index = 0;
            }
        }
    }
    *returnSize = totalPatterns;
    return patterns;
}

int main() {
    int a, b, c;
    int k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    int elems[] = {0, 1, 2, 3};
    int returnSize;
    int* patterns = duplicatePatterns(elems, k, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        int r = a, g = b, B = c;
        for (int j = 0; j < k; j++) {
            if (patterns[i] & (1 << j)) {
                if (j % 4 == 1) r *= 2;
                else if (j % 4 == 2) g *= 2;
                else if (j % 4 == 3) B *= 2;
            }
        }
        if (g > r && B > g) {
            printf("Yes\n");
            free(patterns);
            return 0;
        }
    }
    printf("No\n");
    free(patterns);
    return 0;
}

