
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKET_SIZE 500001
#define MAX_UNIT_SIZE 100

typedef struct {
    int n, h, i, chunk;
    int unit[MAX_UNIT_SIZE];
    int bucket[MAX_UNIT_SIZE][MAX_BUCKET_SIZE];
} Segment;

void init(Segment *seg, int n) {
    seg->n = n;
    seg->unit[0] = 1;
    seg->bucket[0] = (int *)malloc(n * sizeof(int));

    // Calculate the chunk size for the segment tree
    int chunk = 8;
    for (int i = 0; n > 1; i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket[i + 1] = (int *)malloc(n * sizeof(int));
        seg->unit[i + 1] = seg->unit[i] * chunk;
    }
    seg->h = sizeof(seg->unit) / sizeof(int);
    seg->chunk = chunk;
}

void maximize(Segment *seg, int index, int value) {
    // Update the leaf node with the given index and value
    seg->bucket[0][index] = value;

    // Propagate the update to the parent nodes
    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i]) {
            t = seg->bucket[seg->i];
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

int top(Segment *seg) {
    int index = 0;
    for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
        int s = index * seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i]) {
            t = seg->bucket[seg->i];
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

int main() {
    // Open the standard input file if a command-line argument is provided
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Initialize a bufio.Writer for formatted output
    FILE *writer = stdout;

    // Read the first two integers from the input
    int n = 0, m = 0;
    fscanf(fp, "%d %d", &n, &m);

    // Initialize the Segment struct with the given size n
    Segment seg;
    init(&seg, n);

    // Process the input data by maximizing the segments
    for (int i = 0; i < n; i++) {
        int value = 0;
        fscanf(fp, "%d", &value);
        maximize(&seg, i, value);
    }
    for (int i = 0; i < m; i++) {
        int value = 0;
        fscanf(fp, "%d", &value);
        maximize(&seg, seg.top(&seg), value / 2);
    }

    // Calculate the answer and print it to the output
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    // Print the answer to the output
    fprintf(writer, "%lld\n", ans);

    // Flush the writer buffer to ensure all data is written
    fflush(writer);

    // Close the standard input file if a command-line argument is provided
    if (argc > 1) {
        fclose(fp);
    }

    return 0;
}

