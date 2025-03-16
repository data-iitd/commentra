#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to cut the array based on the index
void cut(int array[][2], int *size, int index) {
    if (*size < 1) {
        return;
    }

    if (index <= array[0][0]) {
        array[(*size)++] = (int[]){index, array[0][1]};
        return;
    }

    for (int i = *size - 1; i > 0; i--) {
        if (array[i - 1][0] < index) {
            array[*size] = array[i];
            (*size)++;
            array[*size++] = (int[]){index, array[i][1]};
            return;
        }
    }
}

// Function to check if it's possible to add a certain number of elements
int is_possible(int K, int A[], int N) {
    int dp[MAX_SIZE][2];
    int dp_size = 0;
    dp[dp_size][0] = A[0];
    dp[dp_size++][1] = 0;

    for (int i = 1; i < N; i++) {
        int a = A[i];
        if (a <= dp[dp_size - 1][0]) {
            cut(dp, &dp_size, a);
        }
        dp[dp_size][0] = a;
        dp[dp_size++][1] = 0;

        int is_added = 0;

        for (int j = dp_size - 1; j >= 0; j--) {
            if (dp[j][1] < K - 1) {
                cut(dp, &dp_size, dp[j][0] - 1);
                dp[dp_size][0] = dp[j][0];
                dp[dp_size++][1] = dp[j][1] + 1;

                if (dp[dp_size - 1][0] < a) {
                    dp[dp_size][0] = a;
                    dp[dp_size++][1] = 0;
                    is_added = 1;
                    break;
                }
            }
        }

        if (!is_added) {
            return 0;
        }
    }
    return 1;
}

// Function to find the binary index of a number in the list
int bis(int x, int y, int A[], int N) {
    if (y == x + 1) {
        return y;
    }

    int mid = (x + y) / 2;
    if (is_possible(mid, A, N)) {
        return bis(x, mid, A, N);
    } else {
        return bis(mid, y, A, N);
    }
}

int main() {
    int A[MAX_SIZE];
    int N = 0;

    // Taking input from user
    while (scanf("%d", &A[N]) != EOF) {
        N++;
    }

    // Sorting the array
    qsort(A, N, sizeof(int), compare);

    // Printing the result of the binary index function
    printf("%d\n", bis(0, N, A, N));

    return 0;
}

// <END-OF-CODE>
