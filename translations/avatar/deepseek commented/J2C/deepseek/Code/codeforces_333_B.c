#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// FastReader structure to read input efficiently
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastReader;

// Initialize FastReader
FastReader* createFastReader() {
    FastReader *reader = (FastReader *)malloc(sizeof(FastReader));
    reader->buffer = (char *)malloc(1024 * sizeof(char));
    reader->buffer_size = 1024;
    reader->buffer_position = 0;
    return reader;
}

// Method to read the next token
char* next(FastReader *reader) {
    while (reader->buffer_position == 0 || reader->buffer[reader->buffer_position] == '\0') {
        fgets(reader->buffer, reader->buffer_size, stdin);
        reader->buffer_position = 0;
    }
    char *token = strtok(reader->buffer + reader->buffer_position, " \n");
    if (token != NULL) {
        reader->buffer_position += strlen(token) + 1;
    }
    return token;
}

// Method to read the next integer
int nextInt(FastReader *reader) {
    char *token = next(reader);
    return token ? atoi(token) : 0;
}

// Method to read the next long
long nextLong(FastReader *reader) {
    char *token = next(reader);
    return token ? atol(token) : 0;
}

// Method to read the next double
double nextDouble(FastReader *reader) {
    char *token = next(reader);
    return token ? atof(token) : 0.0;
}

// Method to read the next line
char* nextLine(FastReader *reader) {
    while (reader->buffer_position == 0 || reader->buffer[reader->buffer_position] == '\0') {
        fgets(reader->buffer, reader->buffer_size, stdin);
        reader->buffer_position = 0;
    }
    char *line = strdup(reader->buffer + reader->buffer_position);
    reader->buffer_position += strlen(line);
    return line;
}

// Free FastReader memory
void freeFastReader(FastReader *reader) {
    free(reader->buffer);
    free(reader);
}

// Main function
int main() {
    FastReader *reader = createFastReader();
    // Read the dimensions of the grid
    int n = nextInt(reader);
    // Read the number of banned cells
    int m = nextInt(reader);

    // Initialize sets to keep track of banned rows and columns
    bool *bannedRows = (bool *)calloc(n + 1, sizeof(bool));
    bool *bannedCols = (bool *)calloc(n + 1, sizeof(bool));

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) {
        int r = nextInt(reader);
        if (r > 1 && r < n) bannedRows[r] = true;
        int c = nextInt(reader);
        if (c > 1 && c < n) bannedCols[c] = true;
    }

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2;
    for (int i = 2; i <= n - 1; i++) {
        if (bannedRows[i]) answer--;
        if (bannedCols[i]) answer--;
    }

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    // Output the final answer
    printf("%d\n", answer);
    // Free memory
    free(bannedRows);
    free(bannedCols);
    freeFastReader(reader);
    return 0;
}
