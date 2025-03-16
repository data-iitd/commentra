

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100001], t[100001];
    scanf("%s", s);
    scanf("%s", t);

    int n = strlen(s);
    int m = strlen(t);

    char ans[100001];
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (s[i + j]!= '?' && s[i + j]!= t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < m; j++) {
                s[i + j] = t[j];
            }
            strcpy(ans + count * m, s + i);
            count++;
        }
    }

    if (count == 0) {
        printf("UNRESTORABLE\n");
    } else {
        qsort(ans, count, m, cmp);
        printf("%s\n", ans);
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

