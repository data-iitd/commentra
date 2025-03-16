

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    // Read input: N and K
    int N, K;
    scanf("%d %d", &N, &K);

    // Read input: N integers As
    int *As = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }

    // Read input: N integers Fs
    int *Fs = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }

    // Sort As and Fs in ascending and descending order respectively
    std::sort(As, As + N);
    std::sort(Fs, Fs + N, std::greater<int>());

    // Calculate the score for each element in As
    int *scores = new int[N];
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }

    // Sort scores in descending order
    std::sort(scores, scores + N, std::greater<int>());

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

    // Free memory
    delete[] As;
    delete[] Fs;
    delete[] scores;

    return 0;
}

