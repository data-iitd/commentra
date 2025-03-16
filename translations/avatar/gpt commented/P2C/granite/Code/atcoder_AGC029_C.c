
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int dp[N][2];
    dp[0][0] = A[0];
    dp[0][1] = 0;
    int len = 1;

    for (int i = 1; i < N; i++) {
        if (A[i] <= dp[len - 1][0]) {
            int j = len - 1;
            while (j >= 0 && dp[j][0] >= A[i]) {
                j--;
            }
            if (j >= 0) {
                dp[j + 1][0] = A[i];
                dp[j + 1][1] = dp[j][1];
            } else {
                dp[0][0] = A[i];
                dp[0][1] = 0;
            }
            len = j + 2;
        } else {
            dp[len][0] = A[i];
            dp[len][1] = 0;
            len++;
        }

        int is_added = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (dp[j][1] < 2) {
                int k = j;
                while (k >= 0 && dp[k][0] >= dp[j][0] - 1) {
                    k--;
                }
                if (k >= 0) {
                    dp[k + 1][0] = dp[j][0] - 1;
                    dp[k + 1][1] = dp[j][1] + 1;
                } else {
                    dp[0][0] = dp[j][0] - 1;
                    dp[0][1] = 1;
                }
                len = k + 2;
                is_added = 1;
                break;
            }
        }

        if (!is_added) {
            break;
        }
    }

    printf("%d\n", len);

    return 0;
}
