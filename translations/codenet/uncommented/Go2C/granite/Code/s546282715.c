
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int getNextWord(char **lineptr, char **strtokptr) {
    char *token = NULL;
    token = strtok_r(*lineptr, " ", strtokptr);
    if (token == NULL) {
        return 0;
    }
    *lineptr = NULL;
    return atoi(token);
}

int main(int argc, char **argv) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    char *lineptr = buf;
    char *strtokptr = NULL;

    int n = getNextWord(&lineptr, &strtokptr);
    int m = getNextWord(&lineptr, &strtokptr);

    int *aa = (int *)malloc(sizeof(int) * (m + 1));
    memset(aa, 0, sizeof(int) * (m + 1));
    for (int i = 0; i < m; i++) {
        aa[i] = getNextWord(&lineptr, &strtokptr);
    }

    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa[i + ii]!= 0) {
                continue;
            }
            dp[i + ii] += dp[i];
            dp[i + ii] %= MOD;
        }
    }
    printf("%d\n", dp[n]);

    free(aa);
    free(dp);
    if (fp!= stdin) {
        fclose(fp);
    }

    return 0;
}
