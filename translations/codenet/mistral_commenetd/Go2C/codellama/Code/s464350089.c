#include <stdio.h>
#include <stdlib.h>

int main() {
    // Constants and package imports
    const int mod = 1000000007;
    // 1MB
    const int ioBufferSize = 1 * 1024 * 1024;

    // Helper function to read input
    FILE *sc = fopen("input.txt", "r");
    char buffer[ioBufferSize];
    fgets(buffer, ioBufferSize, sc);
    fclose(sc);

    // Helper functions to read input as a word and an integer
    char *next() {
        char *word = strtok(buffer, " ");
        return word;
    }

    int nextInt() {
        char *word = next();
        int i = atoi(word);
        return i;
    }

    // Main function
    int h, n;
    h = nextInt();
    n = nextInt();

    int a = 0;

    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}

