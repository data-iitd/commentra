
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, temp, ans, min, max;

    scanf("%d %d", &N, &K);

    int S[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = (temp < 0)? -temp : temp;
            for (int j = i + 1; j < N; j++) {
                temp = S[j];
                ans = (temp < 0)? -temp : temp;
                if (ans < ans) {
                    ans = temp;
                }
            }
        }
        printf("%d\n", ans);
    } else if (N - K!= 0) {
        for (int i = 0; i <= N - K; i++) {
            min = S[i];
            max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = (abs(min) > abs(max))? abs(max) : abs(min);
            }
            ans = (temp < ans)? temp : ans;
        }
        printf("%d\n", ans);
    } else {
        min = S[0];
        max = S[N - 1];
        if (min < 0 && max > 0) {
            printf("%d\n", (2 * (abs(min)) + max < abs(min) + 2 * max)? 2 * (abs(min)) + max : abs(min) + 2 * max);
        } else {
            printf("%d\n", (abs(min) > abs(max))? abs(max) : abs(min));
        }
    }

    return 0;
}

