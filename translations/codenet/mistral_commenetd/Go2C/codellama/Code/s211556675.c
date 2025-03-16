
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
typedef struct {
    int id, num;
} Val;

typedef struct {
    Val *vals;
    int len;
} ByNum;

void swap(Val *a, Val *b) {
    Val temp = *a;
    *a = *b;
    *b = temp;
}

int partition(ByNum *a, int low, int high) {
    int pivot = a->vals[high].num;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a->vals[j].num < pivot) {
            i++;
            swap(&a->vals[i], &a->vals[j]);
        }
    }
    i++;
    swap(&a->vals[i], &a->vals[high]);
    return i;
}

void quicksort(ByNum *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int max(int a, int b, int c) {
    int m = a;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    return m;
}

int min(int a, int b, int c) {
    int m = a;
    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }
    return m;
}

int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);

    // Find the maximum value among A, B, and C
    int ma = max(A, B, C);

    // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Calculate the final answer
    int answer = pow(ma, K) + rest;

    // Write the answer to the output
    printf("%d\n", answer);

    return 0;
}

