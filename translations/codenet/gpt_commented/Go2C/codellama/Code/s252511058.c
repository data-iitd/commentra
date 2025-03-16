#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// point struct represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r; // x is the position, l is the left bound, r is the right bound
} point;

// ps is a slice of point, implementing sort.Interface.
typedef struct {
	point *p; // p is a pointer to the points
	int n; // n is the number of points
} ps;

// Len returns the number of points in the slice.
int Len(ps *p) {
	return p->n;
}

// Swap exchanges the points at indices i and j.
void Swap(ps *p, int i, int j) {
	point t = p->p[i];
	p->p[i] = p->p[j];
	p->p[j] = t;
}

// Less reports whether the point at index i should sort before the point at index j.
int Less(ps *p, int i, int j) {
	return p->p[i].r < p->p[j].r; // Sort by the right bound
}

// Sort sorts the points in the slice.
void Sort(ps *p) {
	int i, j, k;
	for (i = 0; i < p->n; i++) {
		for (j = i + 1; j < p->n; j++) {
			if (Less(p, i, j)) {
				Swap(p, i, j);
			}
		}
	}
}

// nextInt reads the next integer from the scanner and returns it.
int nextInt(FILE *f) {
	int t;
	fscanf(f, "%d", &t);
	return t;
}

int main() {
	FILE *f = fopen("input.txt", "r"); // Open the input file
	int N = nextInt(f); // Read the number of points
	point *points = (point *)malloc(N * sizeof(point)); // Create a slice to hold the points

	// Read each point's position and calculate its left and right bounds
	for (int i = 0; i < N; i++) {
		points[i].x = nextInt(f); // Read the position of the point
		int L = nextInt(f); // Read the length to calculate bounds
		points[i].l = points[i].x - L; // Calculate the left bound
		points[i].r = points[i].x + L; // Calculate the right bound
	}

	// Sort the points based on their right bounds
	ps p = {points, N};
	Sort(&p);

	// Initialize the scheduling process for the interval scheduling problem
	int start = points[0].r; // Start with the right bound of the first point
	int ans = 1; // Initialize the count of non-overlapping intervals

	// Iterate through the sorted points to count non-overlapping intervals
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d\n", ans);

	return 0;
}

