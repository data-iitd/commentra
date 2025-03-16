#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader for efficient input reading
typedef struct {
    char* buffer;
    size_t size;
    size_t length;
    FILE* stream;
} FastReader;

// Initializes a FastReader structure
FastReader init_reader(FILE* stream) {
    FastReader reader;
    reader.stream = stream;
    reader.buffer = NULL;
    reader.size = 0;
    reader.length = 0;
    return reader;
}

// Reads a line from the stream
char* readline(FastReader* reader) {
    if (reader->stream == NULL) {
        return NULL;
    }
    if (reader->buffer == NULL) {
        reader->size = 64;
        reader->buffer = malloc(reader->size);
        if (reader->buffer == NULL) {
            return NULL;
        }
    }
    char* ptr = fgets(reader->buffer, reader->size, reader->stream);
    if (ptr == NULL) {
        return NULL;
    }
    size_t len = strlen(reader->buffer);
    if (len < reader->size && reader->buffer[len - 1] == '\n') {
        reader->buffer[len - 1] = '\0';
    }
    reader->length = len;
    return reader->buffer;
}

// Frees the memory allocated by a FastReader structure
void free_reader(FastReader* reader) {
    if (reader->buffer!= NULL) {
        free(reader->buffer);
    }
}

int main() {
    // Read the dimensions of the grid
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    
    // Initialize sets to keep track of banned rows and columns
    int* bannedRows = NULL;
    int* bannedCols = NULL;
    bannedRows = malloc(sizeof(int) * m);
    bannedCols = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &bannedRows[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &bannedCols[i]);
    }
    
    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2;
    
    // Subtract the number of banned rows and columns from the answer
    for (int i = 0; i < m; i++) {
        if (bannedRows[i] > 1 && bannedRows[i] < n) {
            answer--;
        }
        if (bannedCols[i] > 1 && bannedCols[i] < n) {
            answer--;
        }
    }
    
    // If n is odd, check the middle row and column
    if (n % 2!= 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid - 1] &&!bannedCols[mid - 1]) {
            answer--;
        }
    }
    
    // Output the final answer
    printf("%d\n", answer);
    
    // Free the memory allocated by the sets
    free(bannedRows);
    free(bannedCols);
    
    return 0;
}

