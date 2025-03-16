#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

char* getNextWord(char* buffer, int* index, FILE* fp) {
    int i = *index;
    while (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0') {
        i++;
    }
    int len = i - *index;
    char* word = (char*)malloc(len + 1);
    strncpy(word, buffer + *index, len);
    word[len] = '\0';
    *index = i + 1;
    return word;
}

int getNextInt(char* buffer, int* index, FILE* fp) {
    char* word = getNextWord(buffer, index, fp);
    int num = atoi(word);
    free(word);
    return num;
}

int main(int argc, char* argv[]) {
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), fp);

    int index = 0;
    int n = getNextInt(buffer, &index, fp);
    int m = getNextInt(buffer, &index, fp);

    int* aa = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        aa[i] = getNextInt(buffer, &index, fp);
    }

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            int is_blocked = 0;
            for (int j = 0; j < m; j++) {
                if (aa[j] == i + ii) {
                    is_blocked = 1;
                    break;
                }
            }
            if (is_blocked) {
                continue;
            }
            dp[i + ii] += dp[i];
            dp[i + ii] %= MOD;
        }
    }

    printf("%d\n", dp[n]);

    free(aa);
    free(dp);
    if (argc > 1) {
        fclose(fp);
    }

    return 0;
}
