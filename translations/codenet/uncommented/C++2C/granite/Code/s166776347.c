
#include <stdio.h>

int main() {
    // 入力
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // 解法 
    int ans1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) continue;
            if (A[i] > A[j]) ans1++;
            ans1 %= 100000007;
        }
    }
    

    int count[2005] = {0};
    for (int i = 0; i < N; i++) {
        count[A[i] - 1]++;
    }
    // for (int i = 0; i < 3; i++) printf("%d, ", count[i]);
    // printf("\n");
    int ans2 = 0;
    int remain = N;
    for (int i = 0; i < 2005; i++) {
        remain -= count[i];
        ans2 += count[i] * remain;
    }
    // printf("%d\n", ans1);
    // printf("%d\n", ans2);
    // K %= 100000007;
    int tmp = K * (K - 1);
    tmp /= 2;
    tmp %= 100000007;
    tmp *= ans2;
    tmp %= 100000007;
    ans1 *= K;
    ans1 %= 100000007;
    ans1 += tmp;
    ans1 %= 100000007;
    // 出力
    printf("%d\n", ans1);
}
