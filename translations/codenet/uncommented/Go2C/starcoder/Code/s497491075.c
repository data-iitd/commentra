#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
	int x;
	int y;
} Point;

int main() {
	int N, D;
	scanf("%d %d", &N, &D);

	Point points[MAX_N];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		double d = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
		if (d >= D) {
			count++;
		}
	}
	printf("%d\n", count);
}

