#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextString retrieves the next string from the scanner.
char* getNextString(char* buffer, int* index, const char* input) {
    int i = *index;
    while (input[i] != ' ' && input[i] != '\0') {
        buffer[i] = input[i];
        i++;
    }
    buffer[i] = '\0';
    *index = i;
    return buffer;
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(const char* input, int* index) {
    int i = *index;
    int num = 0;
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return num;
}

// getNextInt64 retrieves the next int64 from the scanner.
long long getNextInt64(const char* input, int* index) {
    int i = *index;
    long long num = 0;
    int sign = 1;
    if (input[i] == '-') {
        sign = -1;
        i++;
    }
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return sign * num;
}

// getNextUint64 retrieves the next uint64 from the scanner.
unsigned long long getNextUint64(const char* input, int* index) {
    int i = *index;
    unsigned long long num = 0;
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return num;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(const char* input, int* index) {
    int i = *index;
    double num = 0.0;
    double sign = 1.0;
    if (input[i] == '-') {
        sign = -1.0;
        i++;
    }
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.') {
        i++;
        double decimal = 0.1;
        while (input[i] >= '0' && input[i] <= '9') {
            num += (input[i] - '0') * decimal;
            decimal /= 10;
            i++;
        }
    }
    *index = i;
    return sign * num;
}

// root function finds the root of the given index using path compression.
int root(int i, int* uni) {
    if (i == uni[i]) {
        return i; // Return if the index is its own root
    }
    uni[i] = root(uni[i], uni); // Path compression
    return uni[i]; // Return the root
}

// MP struct holds the string and its pattern matching table.
typedef struct {
    char* s;
    int* table;
} MP;

// init initializes the pattern matching table for the string.
void init(MP* mp, const char* s) {
    int n = strlen(s);
    mp->table = (int*)malloc((n + 1) * sizeof(int));
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

int main() {
    // Initialize file pointers for input and output
    FILE* fp = stdin;
    FILE* wfp = stdout;

    // Check for environment variables to override input and output file pointers
    if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r"); // Open specified input file
    }
    if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w"); // Create specified output file
    }

    // Read input into a buffer
    char buffer[500001];
    fgets(buffer, sizeof(buffer), fp);

    // Read two strings from input
    int index = 0;
    char* s = getNextString(buffer, &index, buffer);
    char* t = getNextString(buffer, &index, buffer);

    // Calculate lengths of the input strings
    int ns = strlen(s);
    int nt = strlen(t);

    // Create a slice to hold repeated instances of string s
    char** ss = (char**)malloc((nt - 1) / ns + 1 * sizeof(char*));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        ss[i] = (char*)malloc((ns + 1) * sizeof(char));
        strcpy(ss[i], s); // Fill the slice with string s
    }

    // Concatenate the repeated strings to form a new string
    char sss[500001];
    sss[0] = '\0';
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        strcat(sss, ss[i]); // Concatenate strings
    }

    // Initialize a boolean slice to track matches
    int* ok = (int*)malloc(ns * sizeof(int));
    memset(ok, 0, ns * sizeof(int));

    // Initialize a unique index array and a pattern matching structure
    int* uni = (int*)malloc(ns * sizeof(int));
    for (int i = 0; i < ns; i++) {
        uni[i] = i; // Set each index to itself initially
    }
    MP mp;
    init(&mp, t); // Initialize the pattern matching table with string t
    int m = 0;
    for (int i = 0; i < ns; i++) {
        int o = 1;
        for (m = 0; m < nt; m++) {
            if (t[m] != sss[i + m]) { // Compare characters
                o = 0;
                break;
            }
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
            fprintf(wfp, "-1\n"); // Output -1 if they are in the same component
            return 0;
        }
        uni[rr] = r; // Union the two components
    }

    // Count the number of matches for each unique root
    int* counter = (int*)malloc(ns * sizeof(int));
    memset(counter, 0, ns * sizeof(int));
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

    // Free allocated memory
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        free(ss[i]);
    }
    free(ss);
    free(ok);
    free(uni);
    free(counter);
    free(mp.table);

    return 0;
}
