#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the maximum of two integers.
int max(int a, int b) {
    return a > b ? a : b;
}

// Reads the next integer from the input buffer.
int readInt() {
    int v;
    scanf("%d", &v);
    return v;
}

// Reads the next 64-bit integer from the input buffer.
long long readInt64() {
    long long v;
    scanf("%lld", &v);
    return v;
}

// Reads the next float from the input buffer.
double readFloat() {
    double v;
    scanf("%lf", &v);
    return v;
}

// Reads the next array of integers from the input buffer.
int* readIntArray() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Reads the next map of integers from the input buffer.
int* readMap() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int H = readInt();
    int W = readInt();
    int N = readInt();
    
    int A = max(H, W);
    
    printf("%d\n", (N + A - 1) / A);
    
    return 0;
}
