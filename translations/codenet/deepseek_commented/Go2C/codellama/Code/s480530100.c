#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// out is a helper function to print output.
void out(int x) {
    printf("%d\n", x);
}

// sc is a bufio.Scanner set up to read input in a word-by-word manner.
char *sc;

// getInt reads a single word from the input and converts it to an integer.
int getInt() {
    int i;
    sscanf(sc, "%d", &i);
    sc = strchr(sc, ' ') + 1;
    return i;
}

// getString reads a single word from the input and returns it as a string.
char *getString() {
    char *s = strchr(sc, ' ') + 1;
    *(strchr(s, ' ')) = '\0';
    sc = strchr(s, ' ') + 1;
    return s;
}

// main function is the entry point of the program.
int main() {
    // Read the number of elements (n) and the number of queries (q).
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree with n elements.
    int *fw = (int *)malloc(sizeof(int) * n);
    memset(fw, 0, sizeof(int) * n);

    // Read n elements and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a = getInt();
        fw[i] = a;
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt();
        if (t == 0) {
            // Update the value at position p by adding x to it.
            int p = getInt(), x = getInt();
            fw[p] += x;
        } else {
            // Query the sum of elements between indices l and r.
            int l = getInt(), r = getInt();
            out(fw[r] - fw[l]);
        }
    }
    return 0;
}

