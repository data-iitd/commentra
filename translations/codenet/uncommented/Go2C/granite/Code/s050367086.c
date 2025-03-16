
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
    int *table;
} MP;

void initMP(MP *mp, char *s) {
    int n = strlen(s);
    mp->s = s;
    mp->table = (int *)malloc(sizeof(int) * (n + 1));
    mp->table[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        for (j = j >= 0? mp->table[j] : -1; j >= 0 && s[i]!= s[j]; j = mp->table[j]);
        mp->table[i + 1] = ++j;
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

    char buf[500001];
    fgets(buf, 500001, fp);
    char *s = buf;
    fgets(buf, 500001, fp);
    char *t = buf;

    int ns = strlen(s);
    int nt = strlen(t);
    char ss[ns * 2];
    for (int i = 0; i < ns * 2; i++) {
        ss[i] = s[i % ns];
    }

    int ok[ns];
    int uni[ns];
    MP mp;
    initMP(&mp, t);
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    bool o = true;
    for (int i = 0; i < ns; i++) {
        o = true;
        for (m = 0; m < nt; m++) {
            if (t[m]!= ss[i + m]) {
                o = false;
                break;
            }
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        for (m = m >= 0? mp.table[m] : 0; m >= 0 && t[m]!= ss[i + m];) {
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
            fprintf(wfp, "-1\n");
            return 0;
        }
        uni[rr] = r;
    }

    int counter[ns];
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (ok[r] == 0) {
            continue;
        }
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    fprintf(wfp, "%d\n", ans);

    fclose(fp);
    fclose(wfp);

    return 0;
}

// END-OF-CODE