
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
    int *table;
} MP;

void init(MP *mp, char *s) {
    int n = strlen(s);
    mp->s = s;
    mp->table = (int *)malloc(sizeof(int) * (n + 1));
    mp->table[0] = -1; // Set first index to -1 for initialization
    int j = -1;
    for (int i = 0; i < n; i++) {
        // While j is not equal to the root of the previous character, update j
        while (j >= 0 && s[i]!= s[j]) {
            j = mp->table[j];
        }
        j++;
        // Set table[i] to the index of the next occurrence of the current character in s
        mp->table[i + 1] = j;
    }
}

int root(int i, int *uni) {
    if (i == uni[i]) {
        return i;
    }
    // Recursively call root function with the root of index i
    uni[i] = root(uni[i], uni);
    return uni[i];
}

int main() {
    // Open the standard input and output files
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // If environment variables are set, open input and output files accordingly
    if (getenv("MASPY")!= NULL && strcmp(getenv("MASPY"), "ますπ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
    }
    if (getenv("MASPYPY")!= NULL && strcmp(getenv("MASPYPY"), "ますπッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    // Initialize scanner and writer
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
    char sss[1000001];
    for (int i = 0; i < 2; i++) {
        strcat(sss, ss);
    }

    // Initialize boolean array ok to keep track of unique characters
    bool ok[500001];
    for (int i = 0; i < ns; i++) {
        ok[i] = true;
    }

    // Initialize unordered map mp and array uni for suffix array calculation
    MP mp;
    init(&mp, t);
    int m = 0;

    // Initialize uni array with indices from 0 to n-1
    int uni[500001];
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    // Initialize variable o for checking if current and next characters match
    bool o;

    // Iterate through all characters in string s
    for (int i = 0; i < ns; i++) {
        // Initialize o to true
        o = true;

        // Iterate through all characters in string t
        for (m = 0; m < nt; m++) {
            // Check if current character in s matches the character at the same position in t
            if (t[m]!= sss[i + m]) {
                // If not, set o to false and break the loop
                o = false;
                break;
            }
            // Increment m
            m++;
        }

        // If all characters match, set ok[i] to true and update variables r and m accordingly
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }

        // While characters in s and t do not match, update i and m accordingly
        for (m = m >= 0 && t[m]!= sss[i + m]; m--) {
            i += m - mp.table[m];
            m = mp.table[m];
        }

        // Decrement i and increment m to move to the next pair of characters
        i--;
        m++;
    }

    // Initialize variable ans to store the answer
    int ans = 0;

    // Initialize variables r and rr for root calculation
    int r, rr;

    // Iterate through all characters in string s again
    for (int i = 0; i < ns; i++) {
        // If ok[i] is false, continue to the next iteration
        if (!ok[i]) {
            continue;
        }

        // If ok[(i+nt)%ns] is false, continue to the next iteration
        if (!ok[(i + nt) % ns]) {
            continue;
        }

        // Calculate roots r and rr of indices i and (i+nt)%ns respectively
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);

        // If roots r and rr are equal, print -1 and exit the program
        if (rr == r) {
            fprintf(wfp, "-1\n");
            return 0;
        }

        // Update uni array with root r
        uni[rr] = r;
    }

    // Initialize counter array to store the frequency of each root
    int counter[500001];
    for (int i = 0; i < ns; i++) {
        counter[i] = 0;
    }

    // Iterate through all roots and update their frequencies in counter array
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) {
            continue;
        }
        counter[r]++;
    }

    // Find the maximum frequency in counter array and store it in variable ans
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    // Print the answer
    fprintf(wfp, "%d\n", ans);

    // Flush the writer buffer
    fflush(wfp);

    return 0;
}

// END-OF-CODE