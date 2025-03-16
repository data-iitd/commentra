#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    int n, m;
    fscanf(fp, "%d %d", &n, &m);

    int *aa = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int x;
        fscanf(fp, "%d", &x);
        aa[x] = 1;
    }

    int *dp = (int *)calloc(n + 1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa[i + ii]) {
                continue;
            }
            dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
        }
    }

    printf("%d\n", dp[n]);

    free(aa);
    free(dp);
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
