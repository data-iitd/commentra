#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a point with x, l (left boundary), and r (right boundary).
typedef struct {
    int x, l, r;
} Point;

// Define a comparison function for sorting points by r.
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->r - p2->r;
}

// Read the next integer from the standard input.
int readInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Main function is the entry point of the program.
int main() {
    int N = readInt(); // Read the number of points.
    Point points[N];
    for (int i = 0; i < N; i++) {
        points[i].x = readInt(); // Read the x-coordinate of the point.
        int L = readInt(); // Read the length L.
        points[i].l = points[i].x - L; // Calculate the left boundary.
        points[i].r = points[i].x + L; // Calculate the right boundary.
    }
    // Sort the points by their right boundary.
    qsort(points, N, sizeof(Point), compare);
    // Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
    int start = points[0].r; // Initialize the start of the first interval.
    int ans = 1; // Initialize the answer (at least one interval is selected).
    for (int i = 0; i < N; i++) {
        if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
            continue;
        }
        start = points[i].r; // Move to the next interval.
        ans++; // Increment the count of selected intervals.
    }
    printf("%d\n", ans); // Print the number of selected intervals.
    return 0;
}
