#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000
#define MAX_H 20
#define MAX_CHUNK 8

typedef struct {
	int n, h, i, chunk;
	int unit[MAX_H];
	int bucket[MAX_H][MAX_N];
} Segment;

void init(Segment *seg, int n) {
	seg->n = n;
	seg->unit[0] = 1;
	seg->bucket[0][0] = 0;
	seg->chunk = 8;
	int i;
	for (i = 0; n > 1; i++) {
		n = (n-1)/seg->chunk + 1;
		seg->bucket = (int**) realloc(seg->bucket, sizeof(int*)*i+1);
		seg->bucket[i] = (int*) malloc(sizeof(int)*n);
		seg->unit = (int*) realloc(seg->unit, sizeof(int)*(i+1));
		seg->unit[i+1] = seg->unit[i]*seg->chunk;
	}
	seg->h = i+1;
}

void maximize(Segment *seg, int index, int value) {
	seg->bucket[0][index] = value;
	for (seg->i = 0; seg->i < seg->h-1; seg->i++) {
		int s = index - index%seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->n) {
			t = seg->n;
		}
		int parent = index / seg->chunk;
		int max = 0;
		for (int i = s; i < t; i++) {
			if (max < seg->bucket[seg->i][i]) {
				max = seg->bucket[seg->i][i];
			}
		}
		seg->bucket[seg->i+1][parent] = max;
		index /= seg->chunk;
	}
}

int top(Segment *seg) {
	int index = 0;
	for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
		int s = index * seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->n) {
			t = seg->n;
		}
		for (int i = s; i < t; i++) {
			if (seg->bucket[seg->i][i] == seg->bucket[seg->i+1][index]) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int main() {
	Segment seg;
	int n, m, i;
	scanf("%d %d", &n, &m);
	init(&seg, n);
	for (i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);
		maximize(&seg, i, value);
	}
	for (i = 0; i < m; i++) {
		int value;
		scanf("%d", &value);
		maximize(&seg, top(&seg), value/2);
	}

	int ans = 0;
	for (i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	printf("%d\n", ans);
	return 0;
}

