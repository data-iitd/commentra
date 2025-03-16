#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF (int)1e9
#define mod 1000000007

int input() {
    int value;
    scanf("%d", &value);
    return value;
}

int* MAP() {
    static int arr[100000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    int N = input();
    int* A = MAP();

    // Removing consecutive duplicates from list A
    int* temp = (int*)malloc(N * sizeof(int));
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            temp[j++] = A[i];
        }
    }
    N = j;
    free(A);
    A = temp;

    // Initializing variables for main logic
    int i = 1;
    int ans = 0;

    // Main logic to find peaks
    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i++;  // Skip next element as it's already checked
        }
        i++;
    }

    // Output the total number of peaks found
    printf("%d\n", ans + 1);

    free(A);
    return 0;
}
