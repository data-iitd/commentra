#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define MAX_SIZE 500000

// MP Struct
=======
// MP Struct
// Purpose: Manages the pattern and its pre-processing table for the Boyer-Moore algorithm.
>>>>>>> 98c87cb78a (data updated)
typedef struct {
    char *s;
    int *table;
} MP;

// Function to initialize the MP struct and build the pre-processing table
<<<<<<< HEAD
void init(MP *mp, const char *s) {
=======
void initMP(MP *mp, const char *s) {
>>>>>>> 98c87cb78a (data updated)
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

// Function to find the root of a node in the union-find structure
int root(int i, int *uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

int main() {
<<<<<<< HEAD
    char s[MAX_SIZE + 1], t[MAX_SIZE + 1];
    scanf("%s %s", s, t);
=======
    char *s = NULL;
    char *t = NULL;
    size_t len = 0;

    // Read input strings
    getline(&s, &len, stdin);
    getline(&t, &len, stdin);

    // Remove newline characters
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;
>>>>>>> 98c87cb78a (data updated)

    int ns = strlen(s);
    int nt = strlen(t);
    int ss_size = (nt - 1) / ns + 1;
<<<<<<< HEAD
    char *sss = (char *)malloc((2 * ss_size * ns + 1) * sizeof(char));

    for (int i = 0; i < ss_size; i++) {
        strncpy(sss + i * ns, s, ns);
    }
    sss[2 * ss_size * ns] = '\0';
=======
    char *sss = (char *)malloc((2 * ns * ss_size + 1) * sizeof(char));

    // Create the repeated string
    for (int i = 0; i < ss_size; i++) {
        strcat(sss, s);
    }
    strcat(sss, sss); // Concatenate it with itself
>>>>>>> 98c87cb78a (data updated)

    int *ok = (int *)calloc(ns, sizeof(int));
    int *uni = (int *)malloc(ns * sizeof(int));
    MP mp;
<<<<<<< HEAD
    init(&mp, t);
=======
    initMP(&mp, t);
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
=======
            free(s);
            free(t);
>>>>>>> 98c87cb78a (data updated)
            free(sss);
            free(ok);
            free(uni);
            free(mp.table);
            free(mp.s);
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

<<<<<<< HEAD
=======
    // Free allocated memory
    free(s);
    free(t);
>>>>>>> 98c87cb78a (data updated)
    free(sss);
    free(ok);
    free(uni);
    free(counter);
    free(mp.table);
    free(mp.s);
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
