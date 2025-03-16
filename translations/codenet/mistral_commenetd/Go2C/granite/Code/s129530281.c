
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n, h, i, chunk;
    int *unit;
    int **bucket;
} Segment;

void init(Segment *seg, int n) {
    seg->n = n;
    seg->unit = (int *)malloc(sizeof(int));
    seg->unit[0] = 1;
    seg->bucket = (int **)malloc(sizeof(int *));
    seg->bucket[0] = (int *)malloc(sizeof(int) * n);

    int chunk = 8;
    for (seg->i = 0; n > 1; seg->i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket = (int **)realloc(seg->bucket, sizeof(int *) * (seg->i + 1));
        seg->unit = (int *)realloc(seg->unit, sizeof(int) * (seg->i + 1));
        seg->bucket[seg->i] = (int *)malloc(sizeof(int) * n);
        seg->unit[seg->i] = seg->unit[seg->i - 1] * chunk;
    }
    seg->h = seg->i + 1;
    seg->chunk = chunk;
}

void maximize(Segment *seg, int index, int value) {
    seg->bucket[0][index] = value;

    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i].size) {
            t = seg->bucket[seg->i].size;
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
        if (t > seg->bucket[seg->i].size) {
            t = seg->bucket[seg->i].size;
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
    int n, m;
    fscanf(fp, "%d %d", &n, &m);

    // Initialize the Segment struct with the given size n
    Segment seg;
    init(&seg, n);

    // Process the input data by maximizing the segments
    for (int i = 0; i < n; i++) {
        int value;
        fscanf(fp, "%d", &value);
        maximize(&seg, i, value);
    }
    for (int i = 0; i < m; i++) {
        maximize(&seg, top(&seg), seg.bucket[0][top(&seg)] / 2);
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

    return 0;
}

