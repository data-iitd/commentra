#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N, K, x, t, i, j, flag, ind, count;
    int *L, *path;
    bool loop;
    L = (int *) malloc(sizeof(int) * (N + 1));
    path = (int *) malloc(sizeof(int) * (N + 1));
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
    L[N] = -1;
    path[0] = 1;
    ind = 0;
    count = 0;
    x = 1;
    t = -1;
    flag = false;
    for (i = 0; i < N + 1; i++) {
        j = L[x];
        if (path[j]) {
            flag = true;
            t = path[j];
            break;
        }
        path[ind + 1] = j;
        ind++;
        path[j] = ind;
        x = j;
    }
    if (flag) {
        loop = true;
        if (K < ind) {
            printf("%d\n", path[K]);
        } else {
            K = K - ind;
            K = K % (ind - t);
            printf("%d\n", path[t + K]);
        }
    } else {
        printf("%d\n", path[K - 1]);
    }
    return 0;
}

