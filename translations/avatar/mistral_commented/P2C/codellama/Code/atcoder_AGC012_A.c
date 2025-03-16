
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000000000

// Function to read integers from the standard input
int* readInts() {
    int* A = (int*)malloc(MAX_SIZE * sizeof(int));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    return A;
}

// Function to sort the list 'A' in ascending order
void sort(int* A, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

// Function to calculate the answer
int calculate(int* A, int n) {
    int ans = 0;
    for (int i = n - 2; i >= n - 2 * n - 1; i -= 2) {
        ans += A[i];
    }
    return ans;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);
    int* A = readInts();
    sort(A, n);
    int ans = calculate(A, n);
    printf("%d\n", ans);
    return 0;
}

