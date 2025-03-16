#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader structure to read input efficiently
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} FastReader;

// Function to initialize FastReader
FastReader* createFastReader() {
    FastReader *reader = (FastReader*)malloc(sizeof(FastReader));
    reader->buffer_size = 1024;
    reader->buffer = (char*)malloc(reader->buffer_size);
    reader->buffer_position = 0;
    return reader;
}

// Function to read the next token as a string
char* next(FastReader *reader) {
    while (reader->buffer_position == 0 || reader->buffer[reader->buffer_position] == '\0') {
        reader->buffer_position = 0;
        fgets(reader->buffer, reader->buffer_size, stdin);
    }
    char *token = strtok(reader->buffer, " \n");
    if (token == NULL) {
        token = next(reader);
    }
    return token;
}

// Function to read the next token as an integer
int nextInt(FastReader *reader) {
    char *token = next(reader);
    return atoi(token);
}

// Function to read the next token as a long
long nextLong(FastReader *reader) {
    char *token = next(reader);
    return atol(token);
}

// Function to read the next token as a double
double nextDouble(FastReader *reader) {
    char *token = next(reader);
    return atof(token);
}

// Function to read the next line as a string
char* nextLine(FastReader *reader) {
    while (reader->buffer_position == 0 || reader->buffer[reader->buffer_position] == '\0') {
        reader->buffer_position = 0;
        fgets(reader->buffer, reader->buffer_size, stdin);
    }
    char *line = (char*)malloc(reader->buffer_size);
    strcpy(line, reader->buffer);
    reader->buffer_position = 0;
    return line;
}

// Main function
int main() {
    FastReader *reader = createFastReader();

    // Read the number of elements
    int n = nextInt(reader);

    // Create a TreeSet to keep track of available positions on the left
    int *answer = (int*)calloc(n, sizeof(int));
    int *available = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        available[i] = 1;
    }

    // Read the number of queries
    int q = nextInt(reader);

    // Process each query
    while (q-- > 0) {
        // Read the range [l, r] and the winning index
        int l = nextInt(reader) - 1;
        int r = nextInt(reader) - 1;
        int win = nextInt(reader) - 1;

        // Update the answer array for all positions in the range [l, r]
        for (int i = l; i <= r; i++) {
            if (available[i]) {
                answer[i] = win + 1; // Set the answer for this position
                available[i] = 0; // Mark this position as unavailable
            }
        }

        // Mark the winning index as available again
        available[win] = 1;
    }

    // Build the output string from the answer array
    char *ans = (char*)malloc(n * 2);
    for (int i = 0; i < n; i++) {
        sprintf(ans + i * 2, "%d", answer[i]);
        if (i < n - 1) {
            strcat(ans, " ");
        }
    }

    // Print the final answer
    printf("%s\n", ans);

    // Free allocated memory
    free(reader->buffer);
    free(reader);
    free(answer);
    free(available);
    free(ans);

    return 0;
}
