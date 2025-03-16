
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int S[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    int temp = 0;
    int ans = 1000000000;
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = (ans < abs(temp))? ans : abs(temp);
        }
        printf("%d\n", ans);
    } else if (N - K!= 0) {
        for (int i = 0; i <= N - K; i++) {
            int min = S[i];
            int max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = (2 * (-min) + max < (-min) + 2 * max)? (2 * (-min) + max) : ((-min) + 2 * max);
            } else {
                temp = (ans < abs(max))? ans : abs(max);
            }
            ans = (ans < temp)? ans : temp;
        }
        printf("%d\n", ans);
    } else {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0) {
            printf("%d\n", (2 * (-min) + max < (-min) + 2 * max)? (2 * (-min) + max) : ((-min) + 2 * max));
        } else {
            printf("%d\n", (ans < abs(max))? ans : abs(max));
        }
    }
    return 0;
}
