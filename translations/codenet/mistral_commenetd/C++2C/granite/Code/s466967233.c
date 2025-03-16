
#include <stdio.h>

int main()
{
    // Initialize variables
    int N, K;
    int A[200100];
    int B[200100] = {-1};
    int now = 1;
    int cnt = 0;

    // Read input values
    scanf("%d %d", &N, &K);

    // Read array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i + 1]);
    }

    // Initialize B array with -1
    for (int i = 0; i < 200100; i++) {
        B[i] = -1;
    }

    // B[1] is always 0
    B[1] = 0;

    // Simulation of the algorithm
    int j;
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
        int tmp;
        tmp = (K - B[now]) % (cnt - B[now]);

        // Move to the final node
        for (int j = 0; j < tmp; j++) {
            now = A[now];
        }
    }

    // Print the answer
    printf("%d\n", now);

    return 0;
}


