
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read a single integer from input
int next_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
int* next_ints() {
    int* x = malloc(sizeof(int) * 100);
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%d", &x[i]);
    }
    return x;
}

int main() {
    int n = next_int();
    int t = 0;
    int i;
    for (i = 0; i < n; i++) {
        if ((i + 1) & 1) {
            t++;
        }
    }
    printf("%d\n", t / n);
    return 0;
}

