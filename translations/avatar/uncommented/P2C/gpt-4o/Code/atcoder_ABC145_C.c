#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int N, int *x, int *y) {
    int *indices = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    double total_distance = 0.0;
    int count = 0;

    // Generate all permutations of indices
    int *permutation = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        permutation[i] = indices[i];
    }

    do {
        double current_distance = 0.0;
        for (int i = 0; i < N - 1; i++) {
            int f = permutation[i];
            int t = permutation[i + 1];
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            current_distance += distance;
        }
        total_distance += current_distance;
        count++;
    } while (next_permutation(permutation, N));

    double result = total_distance / count;
    printf("%lf\n", result);

    free(indices);
    free(permutation);
}

int next_permutation(int *array, int n) {
    int i = n - 1;
    while (i > 0 && array[i - 1] >= array[i]) {
        i--;
    }
    if (i <= 0) {
        return 0; // No more permutations
    }

    int j = n - 1;
    while (array[j] <= array[i - 1]) {
        j--;
    }
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    j = n - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return 1; // Next permutation found
}

int main() {
    int N;
    scanf("%d", &N);
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    solve(N, x, y);

    free(x);
    free(y);
    return 0;
}

// <END-OF-CODE>
