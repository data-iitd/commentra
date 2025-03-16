#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 500001

typedef struct {
    char *s;
    int *table;
} MP;

void getScanner(FILE *fp) {
    // No-op in C, as we don't have a scanner object like in Go
}

char *getNextString(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int getNextInt(FILE *fp) {
    char *line = getNextString(fp);
    return line ? atoi(line) : 0;
}

long long getNextInt64(FILE *fp) {
    char *line = getNextString(fp);
    return line ? atoll(line) : 0;
}

unsigned long long getNextUint64(FILE *fp) {
    char *line = getNextString(fp);
    return line ? strtoull(line, NULL, 10) : 0;
}

double getNextFloat64(FILE *fp) {
    char *line = getNextString(fp);
    return line ? atof(line) : 0.0;
}

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
    int ss_len = (nt - 1) / ns + 1;
    char **ss = (char **)malloc(ss_len * sizeof(char *));
    for (int i = 0; i < ss_len; i++) {
        ss[i] = (char *)malloc(ns + 1);
        strcpy(ss[i], s);
    }

    char sss[MAX_BUFFER_SIZE];
    strcpy(sss, "");
    for (int i = 0; i < ss_len; i++) {
        strcat(sss, ss[i]);
    }

    MP mp;
    initMP(&mp, t);

    bool ok[ns];
    memset(ok, false, ns);

    int uni[ns];
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    for (int i = 0; i < ns; i++) {
        bool o = true;
        int m = 0;
        while (m < nt) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
            m++;
        }
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

    for (int i = 0; i < ns; i++) {
        if (!ok[i]) {
            continue;
        }
        if (!ok[(i + nt) % ns]) {
            continue;
        }
        int r = root(i, uni);
        int rr = root((i + nt) % ns, uni);
        if (rr == r) {
            fprintf(wfp, "-1\n");
            return 0;
        }
        uni[rr] = r;
    }

    int counter[ns];
    memset(counter, 0, ns * sizeof(int));

    for (int i = 0; i < ns; i++) {
        int r = root(i, uni);
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

    fclose(fp);
    fclose(wfp);

    for (int i = 0; i < ss_len; i++) {
        free(ss[i]);
    }
    free(ss);
    free(mp.table);

    return 0;
}
