#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Represents a point with x, l (left boundary), and r (right boundary).
typedef struct {
	int x, l, r;
} point;

// Sorts a slice of point by r.
void sortPoints(point *points, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (points[i].r > points[j].r) {
				point tmp = points[i];
				points[i] = points[j];
				points[j] = tmp;
			}
		}
	}
}

// Returns the maximum number of non-overlapping intervals.
int solve(point *points, int n) {
	int ans = 1;
	int start = points[0].r;
	for (int i = 0; i < n; i++) {
		if (points[i].l < start) {
			continue;
		}
		start = points[i].r;
		ans++;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	point *points = (point *) malloc(sizeof(point) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &points[i].x);
		int l;
		scanf("%d", &l);
		points[i].l = points[i].x - l;
		points[i].r = points[i].x + l;
	}
	sortPoints(points, n);
	printf("%d\n", solve(points, n));
	return 0;
}

