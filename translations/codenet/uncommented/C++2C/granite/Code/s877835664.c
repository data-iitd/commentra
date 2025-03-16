
#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int cur = 0;
    int dic[N];
    for (int i = 0; i < N; i++) {
        dic[i] = -1;
    }
    bool flg = false;
    for (int i = 0; i < K; i++) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            cur = A[cur] - 1;
        }
        else if (!flg) {
            int tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            i = K - tmp;
            flg = true;
        }
    }

    printf("%d\n", cur + 1);
    return 0;
}
