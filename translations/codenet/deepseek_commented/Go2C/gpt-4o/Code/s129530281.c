#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000

// Segment struct represents a segment tree.
typedef struct {
    int n, h, i, chunk;
    int *unit;
    int **bucket;
} Segment;

// Function to initialize the segment tree with a given size n.
void init(Segment *seg, int n) {
    seg->n = n;
    seg->unit = (int *)malloc(sizeof(int));
    seg->unit[0] = 1;
    seg->bucket = (int **)malloc(sizeof(int *));
    seg->bucket[0] = (int *)malloc(n * sizeof(int));

    int chunk = 8;
    for (int i = 0; n > 1; i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket = (int **)realloc(seg->bucket, (i + 2) * sizeof(int *));
        seg->bucket[i + 1] = (int *)malloc(n * sizeof(int));
        seg->unit = (int *)realloc(seg->unit, (i + 2) * sizeof(int));
        seg->unit[i + 1] = seg->unit[i] * chunk;
    }
    seg->h = sizeof(seg->unit) / sizeof(seg->unit[0]);
    seg->chunk = chunk;
}

// Function to update the value at a given index in the segment tree.
void maximize(Segment *seg, int index, int value) {
    seg->bucket[0][index] = value;
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

// Function to return the index of the maximum value in the segment tree.
int top(Segment *seg) {
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

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    Segment seg;
    int n, m;
    fscanf(fp, "%d %d", &n, &m);
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    init(&seg, n);

    // Populate the segment tree with initial values.
    for (int i = 0; i < n; i++) {
        int value;
        fscanf(fp, "%d", &value);
        maximize(&seg, i, value);
    }

    // Perform the specified number of operations on the segment tree.
    for (int i = 0; i < m; i++) {
        maximize(&seg, top(&seg), seg.bucket[seg.h - 1][0] >> 1);
    }

    // Calculate the sum of the values in the root bucket of the segment tree.
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    // Write the result to the standard output.
    printf("%lld\n", ans);

    // Free allocated memory
    for (int i = 0; i < seg.h; i++) {
        free(seg.bucket[i]);
    }
    free(seg.bucket);
    free(seg.unit);

<<<<<<< HEAD
    if (fp != stdin) {
        fclose(fp);
    }

=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
