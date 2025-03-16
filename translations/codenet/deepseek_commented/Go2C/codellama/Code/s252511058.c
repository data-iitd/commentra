#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// point represents a point with x, l (left boundary), and r (right boundary).
typedef struct {
	int x, l, r;
} point;

// ps is a slice of point and implements sort.Interface to sort by r.
typedef struct {
	int len;
	point *p;
} ps;

// nextInt reads the next word from the scanner, converts it to an integer, and returns it.
int nextInt(FILE *sc) {
	char *p;
	int t;
	fscanf(sc, "%s", p);
	t = atoi(p);
	return t;
}

// ps_len returns the length of the ps.
int ps_len(ps *p) {
	return p->len;
}

// ps_swap swaps the elements at the i-th and j-th positions of the ps.
void ps_swap(ps *p, int i, int j) {
	point t = p->p[i];
	p->p[i] = p->p[j];
	p->p[j] = t;
}

// ps_less returns whether the element at the i-th position of the ps is less than the element at the j-th position.
int ps_less(ps *p, int i, int j) {
	return p->p[i].r < p->p[j].r;
}

// ps_sort sorts the ps by their right boundary.
void ps_sort(ps *p) {
	int i, j, k;
	for (i = 0; i < p->len; i++) {
		for (j = i + 1; j < p->len; j++) {
			if (ps_less(p, i, j)) {
				ps_swap(p, i, j);
			}
		}
	}
}

// main function is the entry point of the program.
int main() {
	FILE *sc = stdin;
	int N = nextInt(sc); // Read the number of points.
	point *points = (point *)malloc(sizeof(point) * N);
	for (int i = 0; i < N; i++) {
		points[i].x = nextInt(sc); // Read the x-coordinate of the point.
		int L = nextInt(sc); // Read the length L.
		points[i].l = points[i].x - L; // Calculate the left boundary.
		points[i].r = points[i].x + L; // Calculate the right boundary.
	}
	ps_sort((ps *)points); // Sort the points by their right boundary.
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

