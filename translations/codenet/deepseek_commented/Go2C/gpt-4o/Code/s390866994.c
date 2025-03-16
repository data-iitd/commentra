#include <stdio.h>
#include <stdlib.h>

void out(int x) {
    printf("%d\n", x);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, C, K;

    // Read input values
    scanf("%d", &N); // Number of passengers
    scanf("%d", &C); // Bus capacity
    scanf("%d", &K); // Time window

    // Array to store arrival times
    int *t = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the arrival times
    qsort(t, N, sizeof(int), compare);

    // Initialize variables for the number of buses and passengers in the current bus
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K; // Time when the bus will be full or the time window expires

    // Iterate through the sorted arrival times
    for (int i = 1; i < N; i++) {
        if (cnt < C && t[i] <= end) {
            // The current passenger can fit in the bus
            cnt++;
        } else {
            // The current bus is full or the time window has expired
            // Increment the bus count, reset the count, and update the end time
            cnt = 1;
            end = t[i] + K;
            ans++;
        }
    }

    // Output the number of buses required
    out(ans);

    // Free allocated memory
    free(t);
    return 0;
}

// <END-OF-CODE>
