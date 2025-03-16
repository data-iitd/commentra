
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
    mp->table = (int*)malloc(sizeof(int) * (n + 1));
    mp->table[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        for (j = table[j]; j >= 0 && s[i]!= s[j]; j = table[j]);
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
    // Initialize file pointers for input and output
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check for environment variables to override input and output file pointers
    if (getenv("MASPY") == "ますπ") {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r"); // Open specified input file
    }
    if (getenv("MASPYPY") == "ますπッピ") {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w"); // Create specified output file
    }

    // Create a scanner for reading input and a writer for output
    char s[500001];
    char t[500001];
    fgets(s, 500001, fp);
    fgets(t, 500001, fp);

    // Calculate lengths of the input strings
    int ns = strlen(s);
    int nt = strlen(t);

    // Create a slice to hold repeated instances of string s
    char ss[500001];
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcpy(ss + i * ns, s); // Fill the slice with string s
    }

    // Concatenate the repeated strings to form a new string
    char sss[1000001];
    strcpy(sss, ss);
    strcat(sss, ss);

    // Initialize a boolean slice to track matches
    bool ok[500001];
    for (int i = 0; i < ns; i++) {
        ok[i] = false; // Set each index to false initially
    }

    // Initialize a unique index array and a pattern matching structure
    int uni[500001];
    MP mp;
    init(&mp, t); // Initialize the pattern matching table with string t
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i; // Set each index to itself initially
    }
    bool o = false;

    // Check for matches of string t in the concatenated string sss
    for (int i = 0; i < ns; i++) {
        o = true;
        for (m = 0; m < nt; m++) {
            if (t[m]!= sss[i + m]) { // Compare characters
                o = false;
                break;
            }
        }
        ok[i] = o; // Store the result of the match
        if (o) {
            i += nt - mp.table[m]; // Update index based on the pattern table
            m = mp.table[m]; // Update match index
        }
        for (m = m >= 0 && t[m]!= sss[i + m]; m = mp.table[m]) {
            i += m - mp.table[m]; // Update index if mismatch occurs
            m = mp.table[m]; // Update match index
        }
        i--; // Adjust index for the next iteration
        m++; // Move to the next character
    }

    // Calculate the answer based on the matches found
    int ans = 0;
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) {
            continue; // Skip if no match
        }
        if (!ok[(i + nt) % ns]) {
            continue; // Skip if no match for the next index
        }
        r = root(i, uni); // Find the root of the current index
        rr = root((i + nt) % ns, uni); // Find the root of the next index
        if (rr == r) {
            fprintf(wfp, "-1\n"); // Output -1 if they are in the same component
            return 0;
        }
        uni[rr] = r; // Union the two components
    }

    // Count the number of matches for each unique root
    int counter[500001];
    for (int i = 0; i < ns; i++) {
        r = root(i, uni); // Find the root for the current index
        if (!ok[r]) {
            continue; // Skip if no match
        }
        counter[r]++; // Increment the count for the root
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i]; // Update the answer with the maximum count
        }
    }

    // Output the final answer
    fprintf(wfp, "%d\n", ans);

    fclose(fp); // Close the input file pointer
    fclose(wfp); // Close the output file pointer

    return 0;
}

// Translate the above C code to Python and end with comment "