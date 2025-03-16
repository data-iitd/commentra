#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a point
typedef struct {
    int x, l, r;
} Point;

// Define a type for an array of points
typedef Point Points[100000];

// Function to compare two points based on their right bounds
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->r - p2->r;
}

int main() {
    int N;
    Points points;

    // Read the number of points
    scanf("%d", &N);

    // Read each point's position and calculate its left and right bounds
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i].x);
        int L;
        scanf("%d", &L);
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }

    // Sort the points based on their right bounds
    qsort(points, N, sizeof(Point), compare);

    // Initialize the scheduling process for the interval scheduling problem
    int start = points[0].r;
    int ans = 1;

    // Iterate through the sorted points to count non-overlapping intervals
    for (int i = 0; i < N; i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }

    // Output the total number of non-overlapping intervals
    printf("%d\n", ans);

    return 0;
}
