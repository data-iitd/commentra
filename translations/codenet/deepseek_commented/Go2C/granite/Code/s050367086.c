
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
    int *table;
} MP;

void init(MP *mp, char *s) {
    mp->s = s;
    int n = strlen(s);
    mp->table = (int *)malloc(sizeof(int) * (n + 1));
    mp->table[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        for (j = mp->table[i]; j >= 0 && s[i]!= s[j]; j = mp->table[j]);
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
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (getenv("MASPY")!= NULL && strcmp(getenv("MASPY"), "ますぴ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
    }
    if (getenv("MASPYPY")!= NULL && strcmp(getenv("MASPYPY"), "ますぴぴ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    char s[500001];
    char t[500001];
    fgets(s, 500001, fp);
    fgets(t, 500001, fp);

    int ns = strlen(s);
    int nt = strlen(t);
    char ss[500001];
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(ss, s);
    }
    strcat(ss, s);

    int ok[ns];
    for (int i = 0; i < ns; i++) {
        ok[i] = 1;
    }

    int uni[ns];
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    MP mp;
    init(&mp, t);
    int m = 0;
    for (int i = 0; i < ns; i++) {
        int o = 1;
        for (m = 0; m < nt; m++) {
            if (t[m]!= ss[i + m]) {
                o = 0;
                break;
            }
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        for (m = m >= 0? m : 0; m > 0 && t[m]!= ss[i + m];) {
            i += m - mp.table[m];
            m = mp.table[m];
        }
        i--;
        m++;
    }

    int ans = 0;
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (ok[i] == 0) {
            continue;
        }
        if (ok[(i + nt) % ns] == 0) {
            continue;
        }
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);
        if (rr == r) {
            printf("-1\n");
            return 0;
        }
        uni[rr] = r;
    }

    int counter[ns];
    for (int i = 0; i < ns; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < ns; i++) {
        if (ok[i] == 0) {
            continue;
        }
        r = root(i, uni);
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    printf("%d\n", ans);

    fclose(fp);
    fclose(wfp);

    return 0;
}

// END-OF-CODE