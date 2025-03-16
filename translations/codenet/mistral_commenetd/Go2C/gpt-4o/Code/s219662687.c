#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to compute the absolute value
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to compute the minimum of two integers
int min(int x, int y) {
    return x < y ? x : y;
}

// Function to perform binary search
int binarySearch(int arr[], int size, int x) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    const int INF = (int)pow(10, 11); // Large constant value for initializing arrays

    // Reading input values
    int A = nextInt();
    int B = nextInt();
    int Q = nextInt();

    // Initializing arrays s and t
    int *s = (int *)malloc((A + 2) * sizeof(int));
    int *t = (int *)malloc((B + 2) * sizeof(int));
    s[0] = -INF;
    s[A + 1] = INF;
    t[0] = -INF;
    t[B + 1] = INF;

    // Reading A elements into array s
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
    }

    // Reading B elements into array t
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
    }

    // Processing each query
    for (int i = 0; i < Q; i++) {
        int x = nextInt();

        // Finding the indices b and d
        int b = binarySearch(s, A + 2, x);
        int d = binarySearch(t, B + 2, x);

        // Computing the minimum distance
        int res = INF;
        for (int j = b - 1; j <= b; j++) {
            for (int k = d - 1; k <= d; k++) {
                int S = s[j];
                int T = t[k];
                int d1 = abs(S - x);
                int d2 = abs(T - S);
                res = min(res, min(d1, d2));
            }
        }

        // Printing the minimum distance for the current query
        printf("%d\n", res);
    }

    // Freeing allocated memory
    free(s);
    free(t);

    return 0;
}

// <END-OF-CODE>
