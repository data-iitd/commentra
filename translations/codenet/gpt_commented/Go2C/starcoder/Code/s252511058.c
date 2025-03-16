

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compare(const void *a, const void *b) {
	point *p1 = (point *) a;
	point *p2 = (point *) b;
	return p1->r - p2->r;
}

int main() {
	int N;
	scanf("%d", &N); // Read the number of points
	point *points = (point *) malloc(N * sizeof(point)); // Create a slice to hold the points

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
	for (int i = 0; i < N; i++) {
		if (points[i].l < start) { // If the left bound overlaps with the current start
			continue; // Skip to the next point
		}
		start = points[i].r; // Update the start to the right bound of the current point
		ans++; // Increment the count of non-overlapping intervals
	}

	// Output the total number of non-overlapping intervals
	printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Represents a point with its position and its left and right bounds.
typedef struct {
	int x, l, r;
} point;

// Sorts the points based on their right bounds.
int compa