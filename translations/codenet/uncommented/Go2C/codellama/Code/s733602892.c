#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 100000

int N, K;
int As[MAX_N];
int Fs[MAX_N];
int scores[MAX_N];

void sort_ints(int *arr, int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    sort_ints(scores, N);

    int ok = scores[0];
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    printf("%d\n", ok);
    return 0;
}

