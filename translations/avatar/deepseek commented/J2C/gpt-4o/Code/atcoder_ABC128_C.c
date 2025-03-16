#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of switches (N) and the number of lights (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize an array of integers with N elements, all set to 0
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }

    // Read M groups of integers, where each group represents a switch and its corresponding states
    for (int i = 0; i < M; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int s;
            scanf("%d", &s);
            s--; // Convert to 0-based index
            a[s] |= (1 << i);
        }
    }

    // Read the final state of each light
    int p = 0;
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        p |= (x << i);
    }

    // Calculate the number of possible configurations of switch states that match the final state of the lights
    int ans = 0;
    for (int s = 0; s < (1 << N); s++) {
        int t = 0;
        for (int i = 0; i < N; i++) {
            if ((s >> i) & 1) {
                t ^= a[i];
            }
        }
        if (p == t) {
            ans++;
        }
    }

    // Print the result
    printf("%d\n", ans);

    // Free the allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
