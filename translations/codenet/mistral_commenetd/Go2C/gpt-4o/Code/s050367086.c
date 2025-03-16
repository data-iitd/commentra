#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next string from input
char* getNextString() {
    char* buffer = malloc(500001);
    scanf("%s", buffer);
    return buffer;
}

// Function to read the next integer from input
int getNextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read the next long long integer from input
long long getNextInt64() {
    long long i;
    scanf("%lld", &i);
    return i;
}

// Function to read the next double from input
double getNextFloat64() {
    double i;
    scanf("%lf", &i);
    return i;
}

// Function to find the root of the given index in the union-find structure
int root(int i, int* uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

// Structure to represent the suffix array data structure
typedef struct {
    char* s;      // Input string
    int* table;   // Suffix array
} MP;

// Function to initialize the MP structure with the given string s
void init(MP* mp, char* s) {
    mp->s = s;
    int n = strlen(s);
    mp->table = malloc((n + 1) * sizeof(int));
    mp->table[0] = -1; // Set first index to -1 for initialization
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = mp->table[j];
        }
        j++;
        mp->table[i + 1] = j;
    }
}

int main() {
    // Read the first two strings from the input
    char* s = getNextString();
    char* t = getNextString();

    // Initialize variables and structures
    int ns = strlen(s);
    int nt = strlen(t);
    int ss_size = (nt - 1) / ns + 1;
    char* sss = malloc(2 * ns * ss_size + 1);
    
    // Initialize ss with repeated string s
    for (int i = 0; i < ss_size; i++) {
        strcat(sss, s);
    }
    strcat(sss, sss); // Combine all ss strings into one long string

    // Initialize boolean array ok to keep track of unique characters
    int* ok = calloc(ns, sizeof(int));

    // Initialize unordered map mp for suffix array calculation
    MP mp;
    init(&mp, t);
    int m = 0;

    // Initialize uni array with indices from 0 to n-1
    int* uni = malloc(ns * sizeof(int));
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    // Iterate through all characters in string s
    for (int i = 0; i < ns; i++) {
        int o = 1; // Initialize o to true

        // Iterate through all characters in string t
        while (m < nt) {
            // Check if current character in s matches the character at the same position in t
            if (t[m] != sss[i + m]) {
                o = 0; // If not, set o to false and break the loop
                break;
            }
            m++;
        }

        // If all characters match, set ok[i] to true and update variables
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }

        // While characters in s and t do not match, update i and m accordingly
        while (m >= 0 && t[m] != sss[i + m]) {
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

        // If ok[(i + nt) % ns] is false, continue to the next iteration
        if (!ok[(i + nt) % ns]) {
            continue;
        }

        // Calculate roots r and rr of indices i and (i + nt) % ns respectively
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);

        // If roots r and rr are equal, print -1 and exit the program
        if (rr == r) {
            printf("-1\n");
            return 0;
        }

        // Update uni array with root r
        uni[rr] = r;
    }

    // Initialize counter array to store the frequency of each root
    int* counter = calloc(ns, sizeof(int));

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
    printf("%d\n", ans);

    // Free allocated memory
    free(s);
    free(t);
    free(sss);
    free(ok);
    free(uni);
    free(counter);
    free(mp.table);

    return 0;
}

// <END-OF-CODE>
