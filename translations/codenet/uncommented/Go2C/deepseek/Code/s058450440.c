#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[1000];
int ans = 0;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < len; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    char dic[128] = {0};
    char buffer[1000];
    char *tokens[1000];
    int tokenCount = 0;

    scanf("%d", &n);
    getchar(); // consume newline after n

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (char *p = strtok(buffer, " \n"); p != NULL; p = strtok(NULL, " \n")) {
            tokens[tokenCount++] = p;
        }
    }

    for (int i = 0; i < tokenCount; i++) {
        char c = tokens[i][0];
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[c]++;
        }
    }

    int index = 0;
    for (int i = 0; i < 128; i++) {
        if (dic[i] > 0) {
            a[index++] = dic[i];
        }
    }
    len = index;

    dfs(3, 0, 1);
    printf("%d\n", ans);

    return 0;
}
