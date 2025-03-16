#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReadInt() {
    int v;
    scanf("%d", &v);
    return v;
}

int* ReadInts(int n) {
    int* ret = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ret[i] = ReadInt();
    }
    return ret;
}

int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N = ReadInt();
    int K = ReadInt();

    int* As = ReadInts(N);
    int* Fs = ReadInts(N);

    qsort(As, N, sizeof(int), compareAsc);
    qsort(Fs, N, sizeof(int), compareDesc);

    long long ok = 0;
    long long ng = -1;

    while (ok - ng > 1) {
        long long mid = (ok + ng) / 2;
        long long k = K;
        int isOK = 1;

        for (int i = 0; i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - (mid / Fs[i]);
            }
            if (k < 0) {
                isOK = 0;
                break;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%lld\n", ok);

    free(As);
    free(Fs);

    return 0;
}
