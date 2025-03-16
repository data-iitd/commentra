#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500001

typedef struct {
    char *s;
    int *table;
} MP;

void initMP(MP *mp, const char *s) {
    mp->s = strdup(s);
    int n = strlen(s);
    mp->table = (int *)malloc((n + 1) * sizeof(int));
    mp->table[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = mp->table[j];
        }
        j++;
        mp->table[i + 1] = j;
    }
}

int root(int i, int *uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

int main() {
    char s[MAX_SIZE], t[MAX_SIZE];
    scanf("%s %s", s, t);

    int ns = strlen(s);
    int nt = strlen(t);
    char **ss = (char **)malloc(((nt - 1) / ns + 1) * sizeof(char *));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        ss[i] = strdup(s);
    }

    char *sss = (char *)malloc((2 * (nt - 1) + 2 * ns + 1) * sizeof(char));
    strcpy(sss, ss[0]);
    for (int i = 1; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, ss[i]);
    }
    strcat(sss, sss);

    int *ok = (int *)calloc(ns, sizeof(int));
    int *uni = (int *)malloc(ns * sizeof(int));
    MP mp;
    initMP(&mp, t);
    int m = 0;

    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    for (int i = 0; i < ns; i++) {
        int o = 1;
        m = 0;
        while (m < nt) {
            if (t[m] != sss[i + m]) {
                o = 0;
                break;
            }
            m++;
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }
        i--;
        m++;
    }

    int ans = 0;
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) continue;
        if (!ok[(i + nt) % ns]) continue;
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);
        if (rr == r) {
            printf("-1\n");
            return 0;
        }
        uni[rr] = r;
    }

    int *counter = (int *)calloc(ns, sizeof(int));
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) continue;
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    printf("%d\n", ans);

    free(sss);
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        free(ss[i]);
    }
    free(ss);
    free(ok);
    free(uni);
    free(counter);
    free(mp.table);
    free(mp.s);

    return 0;
}

// <END-OF-CODE>
