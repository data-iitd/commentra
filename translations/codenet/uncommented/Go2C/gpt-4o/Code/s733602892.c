#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // For descending order
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int *As = (int *)malloc(N * sizeof(int));
    int *Fs = (int *)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }

    // Sort As in ascending order
    qsort(As, N, sizeof(int), compare);
    
    // Sort Fs in descending order
    qsort(Fs, N, sizeof(int), compare);
    
    int *scores = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    // Sort scores in descending order
    qsort(scores, N, sizeof(int), compare);
    
    int ok = scores[0];
    int ng = -1;
    
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        int isOK = 1;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = 0;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    printf("%d\n", ok);
    
    free(As);
    free(Fs);
    free(scores);
    
    return 0;
}

// <END-OF-CODE>
