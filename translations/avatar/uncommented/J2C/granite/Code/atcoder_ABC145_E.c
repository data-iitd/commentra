
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int AB[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }
    qsort(AB, N, sizeof(AB[0]), [](const void *a, const void *b) {
        return ((int *)a)[0] - ((int *)b)[0];
    });
    int dp[N + 1][6001];
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] =
                    fmax(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = fmax(ans, dp[i][6000]);
    }
    printf("%d\n", ans);
    return 0;
}
