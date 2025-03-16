#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int L[N + 1];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i + 1]);
    }
    L[0] = -1;

    int path[N + 1];
    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    int flag = 0;
    int Hash[N + 1];
    for (int i = 0; i <= N; i++) {
        Hash[i] = 0;
    }

    while (1) {
        int ne = L[x];
        if (Hash[ne] != 0) {
            flag = 1;
            t = Hash[ne];
            break;
        }
        path[ind++] = ne;
        Hash[ne] = ind;
        x = ne;
    }

    if (flag == 1) {
        int loop[ind - t];
        for (int i = 0; i < ind - t; i++) {
            loop[i] = path[t + i];
        }
        if (K < ind) {
            printf("%d\n", path[K]);
        } else {
            K = K - ind;
            K = K % (ind - t);
            printf("%d\n", loop[K]);
        }
    } else {
        printf("%d\n", path[K - 1]);
    }

    return 0;
}
