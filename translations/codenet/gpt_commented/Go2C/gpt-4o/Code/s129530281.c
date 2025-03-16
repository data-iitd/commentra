#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 500001

// Segment structure to hold the segment data and operations
typedef struct {
    int n, h, i, chunk;
    int *unit;
    int **bucket;
} Segment;

// Function to initialize the segment structure with the given size n
void init(Segment *seg, int n) {
    seg->n = n;
    seg->unit = (int *)malloc(sizeof(int) * 1);
    seg->unit[0] = 1;
    seg->bucket = (int **)malloc(sizeof(int *) * 1);
    seg->bucket[0] = (int *)malloc(sizeof(int) * n);

    int chunk = 8; // Define the chunk size
    for (int i = 0; n > 1; i++) {
        n = (n - 1) / chunk + 1; // Reduce n based on the chunk size
        seg->bucket = (int **)realloc(seg->bucket, sizeof(int *) * (i + 2));
        seg->bucket[i + 1] = (int *)malloc(sizeof(int) * n); // Append a new bucket
        seg->unit = (int *)realloc(seg->unit, sizeof(int) * (i + 2));
        seg->unit[i + 1] = seg->unit[i] * chunk; // Update unit array
    }
    seg->h = sizeof(seg->unit) / sizeof(seg->unit[0]); // Set the height of the segment
    seg->chunk = chunk; // Set the chunk size
}

// Function to update the segment at a given index with a new value
void maximize(Segment *seg, int index, int value) {
    seg->bucket[0][index] = value; // Set the value in the first bucket
    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk; // Calculate the start of the current chunk
        int t = s + seg->chunk; // Calculate the end of the current chunk
        if (t > sizeof(seg->bucket[seg->i]) / sizeof(seg->bucket[seg->i][0])) {
            t = sizeof(seg->bucket[seg->i]) / sizeof(seg->bucket[seg->i][0]); // Adjust end if it exceeds the bucket length
        }
        int parent = index / seg->chunk; // Determine the parent index
        int max = 0; // Initialize max value
        for (int i = s; i < t; i++) {
            if (max < seg->bucket[seg->i][i]) {
                max = seg->bucket[seg->i][i]; // Find the maximum value in the current chunk
            }
        }
        seg->bucket[seg->i + 1][parent] = max; // Update the parent bucket with the maximum value
        index /= seg->chunk; // Move to the parent index for the next iteration
    }
}

// Function to retrieve the index of the top value in the segment
int top(Segment *seg) {
    int index = 0; // Start from the root index
    for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
        int s = index * seg->chunk; // Calculate the start of the current chunk
        int t = s + seg->chunk; // Calculate the end of the current chunk
        if (t > sizeof(seg->bucket[seg->i]) / sizeof(seg->bucket[seg->i][0])) {
            t = sizeof(seg->bucket[seg->i]) / sizeof(seg->bucket[seg->i][0]); // Adjust end if it exceeds the bucket length
        }
        for (int i = s; i < t; i++) {
            if (seg->bucket[seg->i][i] == seg->bucket[seg->i + 1][index]) {
                index = i; // Update index if the value matches the top value
                break;
            }
        }
    }
    return index; // Return the index of the top value
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin; // Default to standard input
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open the file if an argument is provided
    }

    Segment seg;
    int n, m;
    fscanf(fp, "%d %d", &n, &m); // Read the number of elements and operations

    init(&seg, n); // Initialize the segment with size n

    // Populate the segment with initial values
    for (int i = 0; i < n; i++) {
        int value;
        fscanf(fp, "%d", &value);
        maximize(&seg, i, value); // Maximize the segment with the input values
    }

    // Perform m operations to maximize the segment
    for (int i = 0; i < m; i++) {
        maximize(&seg, top(&seg), seg.bucket[seg.h - 1][0] >> 1); // Maximize using the top value and half of the last bucket's first element
    }

    // Calculate the final answer by summing up the values in the first bucket
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (int64_t)seg.bucket[0][i]; // Accumulate the values
    }

    // Output the final result
    printf("%lld\n", ans);

    // Free allocated memory
    for (int i = 0; i < seg.h; i++) {
        free(seg.bucket[i]);
    }
    free(seg.bucket);
    free(seg.unit);

    if (fp != stdin) {
        fclose(fp); // Close the file if it was opened
    }

    return 0;
}

// <END-OF-CODE>
