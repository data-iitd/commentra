#include <stdio.h>
#include <stdlib.h>

// Defining a structure 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
typedef struct {
    int x, l, r;
} point;

// Defining a function to compare two points based on their right-endpoints
int compare(const void *a, const void *b) {
    point *p1 = (point *)a;
    point *p2 = (point *)b;
    return p1->r - p2->r;
}

// Main function starts here
int main() {
    int N;
    // Reading the number of segments N from the input
    scanf("%d", &N);
    // Creating an array 'points' of type 'point' to store all segments
    point points[N];
    // Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' array
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i].x);
        // Reading left-endpoint L of the segment
        int L;
        scanf("%d", &L);
        // Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }
    // Sorting 'points' array based on their right-endpoints
    qsort(points, N, sizeof(point), compare);
    // Initializing variables for result calculation
    int start = points[0].r;
    int ans = 1;
    // Iterating through all segments in sorted order and updating result accordingly
    for (int i = 0; i < N; i++) {
        // If the start of current segment is less than the end of previous segment, then skip it
        if (points[i].l < start) {
            continue;
        }
        // Updating start to the end of current segment
        start = points[i].r;
        // Incrementing answer by 1
        ans++;
    }
    // Printing the final answer
    printf("%d\n", ans);
    return 0;
}

