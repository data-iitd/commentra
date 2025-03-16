#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int L[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }

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

    path[0] = 1;
    for (int i = 1; i <= N; i++) {
        int ne = L[x];
        if (Hash[ne]) {
            flag = 1;
            t = Hash[ne];
            break;
        }
        path[++ind] = ne;
        Hash[ne] = ind;
        x = ne;
    }

    if (flag) {
        int loop[ind - t + 1];
        for (int i = 0; i <= ind - t; i++) {
            loop[i] = path[t + i];
        }
        if (K < N + 1) {
            printf("%d\n", path[K]);
        } else {
            K = K - (N + 1 - t);
            K = K % (ind - t + 1);
            printf("%d\n", loop[K]);
        }
    } else {
        printf("%d\n", path[K - 1]);
    }

    return 0;
}
