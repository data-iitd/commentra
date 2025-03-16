#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long N, K;
    long long A[200100];
    long long B[200100];
    int now = 1;
    long long cnt = 0;

    // Read input values
    scanf("%lld %lld", &N, &K);

    // Read array A
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize B array with -1
    memset(B, -1, sizeof(B));

    // B[1] is always 0
    B[1] = 0;

    // Simulation of the algorithm
    long long j;
    for (j = 1; j <= K; j++) {
        // Move to the next node
        now = A[now];

        // If the node has not been reached yet, update B[now]
        if (B[now] == -1) {
            B[now] = j;
        } else {
            // If the node has already been reached, calculate the answer
            cnt = j;
            break;
        }
    }

    // If the simulation has not reached the end, calculate the answer
    if (j < K) {
        long long tmp;
        tmp = (K - B[now]) % (cnt - B[now]);

        // Move to the final node
        for (long long j = 0; j < tmp; j++) {
            now = A[now];
        }
    }

    // Print the answer
    printf("%d\n", now);

    return 0;
}
