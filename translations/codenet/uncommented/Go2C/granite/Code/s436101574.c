
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100010], t[100010];
    scanf("%s", s);
    scanf("%s", t);

    int ls = strlen(s);
    int lt = strlen(t);

    char *ans[100010];
    int ansc = 0;

    for (int i = 0; i <= ls - lt; i++) {
        int f = 1;
        char ss[100010];
        strcpy(ss, s);
        for (int j = 0; j < lt; j++) {
            if (s[i + j]!= t[j] && s[i + j]!= '?') {
                f = 0;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            char *tmp = (char *)malloc(sizeof(char) * ls + 1);
            strcpy(tmp, ss);
            ans[ansc++] = tmp;
        }
    }

    if (ansc == 0) {
        printf("UNRESTORABLE\n");
    } else {
        qsort(ans, ansc, sizeof(char *), cmp);
        printf("%s\n", ans[0]);
        for (int i = 0; i < ansc; i++) {
            free(ans[i]);
        }
    }

    return 0;
}

