
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int L[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    int path[N + 1];
    path[0] = 1;
    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    int flag = 0;
    int Hash[N + 1];
    for (int i = 0; i <= N; i++) {
        Hash[i] = 0;
    }

    for (int i = 0; i <= N; i++) {
        int ne = L[x - 1];
        if (Hash[ne]!= 0) {
            flag = 1;
            t = Hash[ne];
            break;
        }
        path[ind + 1] = ne;
        ind++;
        Hash[ne] = ind + 1;
        x = ne;
    }

    if (flag == 1) {
        int loop[N];
        for (int i = t; i <= ind; i++) {
            loop[i - t] = path[i];
        }
        if (K <= ind) {
            printf("%d\n", path[K]);
        } else {
            K = K - ind - 1;
            K = K % (ind - t + 1);
            printf("%d\n", loop[K]);
        }
    } else {
        printf("%d\n", path[K]);
    }

    return 0;
}
