#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the next word as a string
char* getNextString(char* buffer, int* index) {
    int start = *index;
    while (buffer[*index] != ' ' && buffer[*index] != '\n' && buffer[*index] != '\0') {
        (*index)++;
    }
    char* result = (char*)malloc((*index - start + 1) * sizeof(char));
    strncpy(result, buffer + start, *index - start);
    result[*index - start] = '\0';
    return result;
}

// Function to get the next integer from the buffer
int getNextInt(char* buffer, int* index) {
    char* str = getNextString(buffer, index);
    int result = atoi(str);
    free(str);
    return result;
}

// Function to get the next 64-bit integer from the buffer
long long getNextInt64(char* buffer, int* index) {
    char* str = getNextString(buffer, index);
    long long result = atoll(str);
    free(str);
    return result;
}

// Function to get the next 64-bit unsigned integer from the buffer
unsigned long long getNextUint64(char* buffer, int* index) {
    char* str = getNextString(buffer, index);
    unsigned long long result = strtoull(str, NULL, 10);
    free(str);
    return result;
}

// Function to get the next 64-bit floating-point number from the buffer
double getNextFloat64(char* buffer, int* index) {
    char* str = getNextString(buffer, index);
    double result = atof(str);
    free(str);
    return result;
}

// Segment struct represents a segment tree data structure
typedef struct {
    int n, h, i, chunk;
    int* unit;
    int** bucket;
} Segment;

// Function to initialize the Segment struct with the given size n
void initSegment(Segment* seg, int n) {
    seg->n = n;
    seg->unit = (int*)malloc(sizeof(int));
    seg->unit[0] = 1;
    seg->bucket = (int**)malloc(sizeof(int*));
    seg->bucket[0] = (int*)malloc(n * sizeof(int));

    // Calculate the chunk size for the segment tree
    int chunk = 8;
    for (int i = 0; n > 1; i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket = (int**)realloc(seg->bucket, (i + 2) * sizeof(int*));
        seg->bucket[i + 1] = (int*)malloc(n * sizeof(int));
        seg->unit = (int*)realloc(seg->unit, (i + 2) * sizeof(int));
        seg->unit[i + 1] = seg->unit[i] * chunk;
    }
    seg->h = i;
    seg->chunk = chunk;
}

// Function to update the segment tree with the given index and value
void maximize(Segment* seg, int index, int value) {
    // Update the leaf node with the given index and value
    seg->bucket[0][index] = value;

    // Propagate the update to the parent nodes
    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->n) {
            t = seg->n;
        }
        int parent = index / seg->chunk;
        int max = 0;
        for (int i = s; i < t; i++) {
            if (max < seg->bucket[seg->i][i]) {
                max = seg->bucket[seg->i][i];
            }
        }
        seg->bucket[seg->i + 1][parent] = max;
        index /= seg->chunk;
    }
}

// Function to return the index of the maximum value in the current segment
int top(Segment* seg) {
    int index = 0;
    for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
        int s = index * seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->n) {
            t = seg->n;
        }
        for (int i = s; i < t; i++) {
            if (seg->bucket[seg->i][i] == seg->bucket[seg->i + 1][index]) {
                index = i;
                break;
            }
        }
    }
    return index;
}

int main(int argc, char* argv[]) {
    // Open the standard input file if a command-line argument is provided
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Read the entire input into a buffer
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = (char*)malloc(fsize + 1);
    fread(buffer, 1, fsize, fp);
    fclose(fp);

    // Initialize a bufio.Writer for formatted output
    FILE* writer = stdout;
    // Read the first two integers from the input
    int n = getNextInt(buffer, &index);
    int m = getNextInt(buffer, &index);

    // Initialize the Segment struct with the given size n
    Segment seg;
    initSegment(&seg, n);

    // Process the input data by maximizing the segments
    for (int i = 0; i < n; i++) {
        maximize(&seg, i, getNextInt(buffer, &index));
    }
    for (int i = 0; i < m; i++) {
        maximize(&seg, top(&seg), seg.bucket[seg.h - 1][0] >> 1);
    }

    // Calculate the answer and print it to the output
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    // Print the answer to the output
    fprintf(writer, "%lld\n", ans);

    // Free allocated memory
    free(buffer);
    for (int i = 0; i < seg.h; i++) {
        free(seg.bucket[i]);
    }
    free(seg.bucket);
    free(seg.unit);

    return 0;
}
