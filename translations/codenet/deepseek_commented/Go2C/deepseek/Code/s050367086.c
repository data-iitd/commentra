#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 500001

typedef struct {
    char *s;
    int *table;
} MP;

void initMP(MP *mp, char *s) {
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

int getNextInt(FILE *fp) {
    char word[MAX_WORD_LENGTH];
    fscanf(fp, "%s", word);
    return atoi(word);
}

char *getNextString(FILE *fp) {
    char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    fscanf(fp, "%s", word);
    return word;
}

int root(int i, int *uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

void main() {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    char *s = getNextString(fp);
    char *t = getNextString(fp);

    int ns = strlen(s);
    int nt = strlen(t);
    char **ss = (char **)malloc((nt - 1) / ns + 1 * sizeof(char *));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        ss[i] = s;
    }

    char *sss = (char *)malloc((2 * ns * (nt - 1) / ns + 1) * sizeof(char));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, ss[i]);
    }
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, ss[i]);
    }

    bool *ok = (bool *)malloc(ns * sizeof(bool));
    int *uni = (int *)malloc(ns * sizeof(int));
    MP mp;
    initMP(&mp, t);
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    bool o;
    for (int i = 0; i < ns; i++) {
        o = true;
        for (m = 0; m < nt; m++) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
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
        if (!ok[i]) {
            continue;
        }
        if (!ok[(i + nt) % ns]) {
            continue;
        }
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);
        if (rr == r) {
            fprintf(wfp, "-1\n");
            return;
        }
        uni[rr] = r;
    }

    int *counter = (int *)malloc(ns * sizeof(int));
    for (int i = 0; i < ns; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) {
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

    free(s);
    free(t);
    free(ss);
    free(sss);
    free(ok);
    free(uni);
    free(counter);
    free(mp.table);

    fclose(fp);
    fclose(wfp);
}
