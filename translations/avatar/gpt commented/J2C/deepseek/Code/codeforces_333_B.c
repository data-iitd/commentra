#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// FastReader structure for efficient input handling
typedef struct {
    char line[MAX_LINE_LENGTH];
    char *ptr;
} FastReader;

FastReader* createFastReader() {
    FastReader *fr = (FastReader *)malloc(sizeof(FastReader));
    fr->ptr = fr->line;
    return fr;
}

// Function to read the next token
char* next(FastReader *fr) {
    if (fr->ptr >= fr->line + MAX_LINE_LENGTH) {
        fgets(fr->line, MAX_LINE_LENGTH, stdin);
        fr->ptr = fr->line;
    }
    char *token = fr->ptr;
    while (*fr->ptr && (*fr->ptr == ' ' || *fr->ptr == '\t' || *fr->ptr == '\n')) {
        fr->ptr++;
    }
    if (*fr->ptr == '\0') {
        return NULL;
    }
    fr->ptr = strchr(fr->ptr, ' ');
    if (fr->ptr) {
        *fr->ptr = '\0';
        fr->ptr++;
    }
    return token;
}

// Function to read the next integer
int nextInt(FastReader *fr) {
    char *token = next(fr);
    return token ? atoi(token) : 0;
}

// Function to read the next long
long nextLong(FastReader *fr) {
    char *token = next(fr);
    return token ? atol(token) : 0;
}

// Function to read the next double
double nextDouble(FastReader *fr) {
    char *token = next(fr);
    return token ? atof(token) : 0.0;
}

// Function to read the next line
char* nextLine(FastReader *fr) {
    if (fr->ptr >= fr->line + MAX_LINE_LENGTH) {
        fgets(fr->line, MAX_LINE_LENGTH, stdin);
        fr->ptr = fr->line;
    }
    char *token = fr->ptr;
    while (*fr->ptr && (*fr->ptr != '\n')) {
        fr->ptr++;
    }
    if (*fr->ptr == '\n') {
        fr->ptr++;
    }
    *fr->ptr = '\0';
    return token;
}

// Main function
int main() {
    FastReader *fr = createFastReader();
    int n = nextInt(fr);
    int m = nextInt(fr);

    // Initialize sets to keep track of banned rows and columns
    bool *bannedRows = (bool *)calloc(n + 1, sizeof(bool));
    bool *bannedCols = (bool *)calloc(n + 1, sizeof(bool));

    // Read the banned rows and columns
    for (int i = 0; i < m; i++) {
        int r = nextInt(fr);
        if (r > 1 && r < n) bannedRows[r] = true;
        int c = nextInt(fr);
        if (c > 1 && c < n) bannedCols[c] = true;
    }

    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2;
    // Subtract the number of banned rows and columns from the answer
    for (int i = 1; i <= n; i++) {
        if (bannedRows[i]) answer--;
        if (bannedCols[i]) answer--;
    }

    // If n is odd, check the middle row and column
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        // If the middle row and column are not banned, decrement the answer
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    // Output the final answer
    printf("%d\n", answer);
    free(bannedRows);
    free(bannedCols);
    free(fr);
    return 0;
}
