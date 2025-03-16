#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r; // x is the position, l is the left bound, r is the right bound
} point;

// Comparison function for qsort to sort points by their right bound
int compare(const void *a, const void *b) {
    point *pointA = (point *)a;
    point *pointB = (point *)b;
    return pointA->r - pointB->r; // Sort by the right bound
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of points
    point *points = malloc(N * sizeof(point)); // Allocate memory for points

    // Read each point's position and calculate its left and right bounds
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i].x); // Read the position of the point
        int L;
        scanf("%d", &L); // Read the length to calculate bounds
        points[i].l = points[i].x - L; // Calculate the left bound
        points[i].r = points[i].x + L; // Calculate the right bound
    }

    // Sort the points based on their right bounds
    qsort(points, N, sizeof(point), compare);

    // Initialize the scheduling process for the interval scheduling problem
    int start = points[0].r; // Start with the right bound of the first point
    int ans = 1; // Initialize the count of non-overlapping intervals

    // Iterate through the sorted points to count non-overlapping intervals
    for (int i = 1; i < N; i++) { // Start from the second point
        if (points[i].l < start) { // If the left bound overlaps with the current start
            continue; // Skip to the next point
        }
        start = points[i].r; // Update the start to the right bound of the current point
        ans++; // Increment the count of non-overlapping intervals
    }

    // Output the total number of non-overlapping intervals
    printf("%d\n", ans);

    free(points); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
