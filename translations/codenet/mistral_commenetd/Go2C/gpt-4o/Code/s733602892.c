#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    // Read input: N and K
    int N, K;
    scanf("%d %d", &N, &K);

    // Read input: N integers As
    int *As = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }

    // Read input: N integers Fs
    int *Fs = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }

    // Sort As in ascending order and Fs in descending order
    qsort(As, N, sizeof(int), compare);
    qsort(Fs, N, sizeof(int), compare_desc);

    // Calculate the score for each element in As
    int *scores = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }

    // Sort scores in descending order
    qsort(scores, N, sizeof(int), compare_desc);

    // Binary search to find the answer
    int ok = scores[0];
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        // Check if it's possible to distribute the flowers to K students with the given mid score
        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                // Subtract the difference between mid and the product of the current element from the remaining flowers
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                // If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
                isOK = false;
                break;
            }
        }

        if (isOK) {
            // If it's possible to distribute the flowers with the given mid score, update ok with mid
            ok = mid;
        } else {
            // If it's not possible to distribute the flowers with the given mid score, update ng with mid
            ng = mid;
        }
    }

    // Print the answer
    printf("%d\n", ok);

    // Free allocated memory
    free(As);
    free(Fs);
    free(scores);

    return 0;
}

// <END-OF-CODE>
