#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
<<<<<<< HEAD
} Point;

// Comparator function for sorting points by their right boundary.
int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
=======
} point;

// Comparator function for sorting points by their right boundary.
int compare(const void *a, const void *b) {
    point *pointA = (point *)a;
    point *pointB = (point *)b;
>>>>>>> 98c87cb78a (data updated)
    return pointA->r - pointB->r;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of points.
    
<<<<<<< HEAD
    Point *points = (Point *)malloc(N * sizeof(Point));
=======
    point *points = (point *)malloc(N * sizeof(point));
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i].x); // Read the x-coordinate of the point.
        int L;
        scanf("%d", &L); // Read the length L.
        points[i].l = points[i].x - L; // Calculate the left boundary.
        points[i].r = points[i].x + L; // Calculate the right boundary.
    }
    
<<<<<<< HEAD
    qsort(points, N, sizeof(Point), compare); // Sort the points by their right boundary.
=======
    qsort(points, N, sizeof(point), compare); // Sort the points by their right boundary.
>>>>>>> 98c87cb78a (data updated)
    
    int start = points[0].r; // Initialize the start of the first interval.
    int ans = 1; // Initialize the answer (at least one interval is selected).
    
    for (int i = 1; i < N; i++) { // Start from the second point.
        if (points[i].l < start) { // If the current interval overlaps with the previous one, skip it.
            continue;
        }
        start = points[i].r; // Move to the next interval.
        ans++; // Increment the count of selected intervals.
    }
    
    printf("%d\n", ans); // Print the number of selected intervals.
    
    free(points); // Free the allocated memory.
    return 0;
}

// <END-OF-CODE>
