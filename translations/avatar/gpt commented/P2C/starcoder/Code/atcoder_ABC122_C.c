#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    char s[n + 1];
    scanf("%s", s);
    int problems[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }
    int cumsum[n + 1];
    cumsum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + (s[i - 1] == 'A' && s[i] == 'C');
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", cumsum[problems[i][1] - 1] - cumsum[problems[i][0] - 1]);
    }
    return 0;
}

