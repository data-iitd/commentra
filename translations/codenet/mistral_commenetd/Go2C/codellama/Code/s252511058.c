
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
typedef struct point {
	int x, l, r;
} point;

// Defining a slice 'ps' of type 'point' for storing all segments in sorted order based on their right-endpoints
typedef struct ps {
	point *p;
	int len;
} ps;

// Implementing Len method for slice 'ps' to get its length
int ps_len(ps *p) {
	return p->len;
}

// Implementing Swap method for slice 'ps' to swap two elements
void ps_swap(ps *p, int i, int j) {
	point temp = p->p[i];
	p->p[i] = p->p[j];
	p->p[j] = temp;
}

// Implementing Less method for slice 'ps' to compare two elements based on their right-endpoints
int ps_less(ps *p, int i, int j) {
	return p->p[i].r < p->p[j].r;
}

// Main function starts here
int main() {
	// Initializing scanner for reading input from standard input
	FILE *fp = fopen(getenv("OUTPUT_PATH"), "w");
	int N;
	scanf("%d", &N);
	// Creating a slice 'points' of type 'point' to store all segments
	point *points = (point *)malloc(N * sizeof(point));
	// Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' slice
	for (int i = 0; i < N; i++) {
		scanf("%d", &points[i].x);
		int L;
		scanf("%d", &L);
		// Calculating left and right endpoints of the segment based on x-coordinate and left-endpoint
		points[i].l = points[i].x - L;
		points[i].r = points[i].x + L;
	}
	// Sorting 'points' slice based on their right-endpoints
	ps p = {points, N};
	qsort(p.p, p.len, sizeof(point), (int (*)(const void *, const void *))ps_less);
	// Initializing variables for result calculation
	int start = p.p[0].r;
	int ans = 1;
	// Iterating through all segments in sorted order and updating result accordingly
	for (int i = 0; i < p.len; i++) {
		// If the start of current segment is less than the end of previous segment, then skip it
		if (p.p[i].l < start) {
			continue;
		}
		// Updating start to the end of current segment
		start = p.p[i].r;
		// Incrementing answer by 1
		ans++;
	}
	// Printing the final answer
	printf("%d\n", ans);
	// Closing the output file
	fclose(fp);
	return 0;
}

// Adding a comment at the end of the code
