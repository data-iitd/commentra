#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500000

// MP struct holds the string and its pattern matching table.
typedef struct {
    char *s;
    int *table;
} MP;

// Function to initialize the pattern matching table for the string.
void init(MP *mp, const char *s) {
<<<<<<< HEAD
    mp->s = strdup(s);
=======
    mp->s = (char *)s;
>>>>>>> 98c87cb78a (data updated)
    int n = strlen(s);
    mp->table = (int *)malloc((n + 1) * sizeof(int));
    mp->table[0] = -1; // Initialize the first value of the table
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = mp->table[j]; // Update j based on the table
        }
        j++;
        mp->table[i + 1] = j; // Fill the table with the length of the longest prefix
    }
}

// Function to find the root of the given index using path compression.
int root(int i, int *uni) {
    if (i == uni[i]) {
        return i; // Return if the index is its own root
    }
    uni[i] = root(uni[i], uni); // Path compression
    return uni[i]; // Return the root
}

int main() {
<<<<<<< HEAD
    // Initialize input and output
    char s[MAX_LEN + 1], t[MAX_LEN + 1];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
    
    // Remove newline characters from input strings
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;
=======
    // Initialize file pointers for input and output
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check for environment variables to override input and output file pointers
    if (getenv("MASPY") && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r"); // Open specified input file
    }
    if (getenv("MASPYPY") && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w"); // Create specified output file
    }

    // Read two strings from input
    char s[MAX_LEN + 1], t[MAX_LEN + 1];
    scanf("%s %s", s, t);
>>>>>>> 98c87cb78a (data updated)

    // Calculate lengths of the input strings
    int ns = strlen(s);
    int nt = strlen(t);

<<<<<<< HEAD
    // Create a buffer to hold repeated instances of string s
    char *sss = (char *)malloc(2 * (nt + ns) * sizeof(char));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, s); // Fill the buffer with string s
=======
    // Create a slice to hold repeated instances of string s
    char *sss = (char *)malloc(2 * (nt + ns) * sizeof(char));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, s); // Fill the string with repeated instances of s
>>>>>>> 98c87cb78a (data updated)
    }
    strcat(sss, sss); // Concatenate the repeated strings

    // Initialize a boolean array to track matches
    int *ok = (int *)calloc(ns, sizeof(int));

    // Initialize a unique index array and a pattern matching structure
    int *uni = (int *)malloc(ns * sizeof(int));
    MP mp;
    init(&mp, t); // Initialize the pattern matching table with string t
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i; // Set each index to itself initially
    }
    int o;

    // Check for matches of string t in the concatenated string sss
    for (int i = 0; i < ns; i++) {
        o = 1;
        m = 0;
        while (m < nt) {
            if (t[m] != sss[i + m]) { // Compare characters
                o = 0;
                break;
            }
            m++;
        }
        ok[i] = o; // Store the result of the match
        if (o) {
            i += nt - mp.table[m]; // Update index based on the pattern table
            m = mp.table[m]; // Update match index
        }
        while (m >= 0 && t[m] != sss[i + m]) {
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
<<<<<<< HEAD
            printf("-1\n"); // Output -1 if they are in the same component
=======
            fprintf(wfp, "-1\n"); // Output -1 if they are in the same component
>>>>>>> 98c87cb78a (data updated)
            free(sss);
            free(ok);
            free(uni);
            free(mp.table);
<<<<<<< HEAD
            free(mp.s);
=======
>>>>>>> 98c87cb78a (data updated)
            return 0;
        }
        uni[rr] = r; // Union the two components
    }

    // Count the number of matches for each unique root
    int *counter = (int *)calloc(ns, sizeof(int));
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
<<<<<<< HEAD
    printf("%d\n", ans);
=======
    fprintf(wfp, "%d\n", ans);
>>>>>>> 98c87cb78a (data updated)

    // Free allocated memory
    free(sss);
    free(ok);
    free(uni);
<<<<<<< HEAD
    free(mp.table);
    free(mp.s);
=======
    free(counter);
    free(mp.table);

    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

// <END-OF-CODE>
