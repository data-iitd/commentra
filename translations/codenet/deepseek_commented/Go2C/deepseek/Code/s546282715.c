#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

char* getNextWord(FILE* fp) {
    char* word = (char*)malloc(100 * sizeof(char));
    fscanf(fp, "%s", word);
    return word;
}

int getNextInt(FILE* fp) {
    char* word = getNextWord(fp);
    int i = atoi(word);
    free(word);
    return i;
}

int main(int argc, char* argv[]) {
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    int n = getNextInt(fp);
    int m = getNextInt(dp);

    int* aa = (int*)calloc(n+1, sizeof(int));
    for (int i = 0; i < m; i++) {
        aa[getNextInt(fp)] = 1;
    }

    int* dp = (int*)calloc(n+1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
            if (aa[i+ii] == 1) {
                continue;
            }
            dp[i+ii] += dp[i];
            dp[i+ii] %= MOD;
        }
    }

    printf("%d\n", dp[n]);

    if (fp != stdin) {
        fclose(fp);
    }

    free(aa);
    free(dp);

