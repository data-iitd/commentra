
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    char buf[500001];
    fgets(buf, 500001, fp);
    int n = atoi(buf);

    int *mm = (int *)malloc(sizeof(int) * (n + 1));
    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
    }
    for (int i = 0; i < n; i++) {
        fgets(buf, 500001, fp);
        mm[i] = atoi(buf);
        fgets(buf, 500001, fp);
        mm[i + 1] = atoi(buf);
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    printf("%d\n", dp[1][n]);

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(mm);

    if (fp!= stdin) {
        fclose(fp);
    }

    return 0;
}
