#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKET_SIZE 500001
#define MAX_UNIT_SIZE 1000001

typedef struct {
	int n, h, i, chunk;
	int unit[MAX_UNIT_SIZE];
	int bucket[MAX_UNIT_SIZE][MAX_BUCKET_SIZE];
} Segment;

void init(Segment *seg, int n) {
	seg->n = n;
	seg->unit[0] = 1;
	seg->bucket[0] = (int *)malloc(n * sizeof(int));

	int chunk = 8;
	for (int i = 0; n > 1; i++) {
		n = (n - 1) / chunk + 1;
		seg->bucket[i + 1] = (int *)malloc(n * sizeof(int));
		seg->unit[i + 1] = seg->unit[i] * chunk;
	}
	seg->h = sizeof(seg->unit) / sizeof(int);
	seg->chunk = chunk;
}

void maximize(Segment *seg, int index, int value) {
	seg->bucket[0][index] = value;
	for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
		int s = index - index % seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->bucket[seg->i]) {
			t = seg->bucket[seg->i];
		}
		int parent = index / seg->chunk;
		int max = 0;
		for (int i = s; i < t; i++) {
			if (max < seg->bucket[seg->i][i]) {
				max = seg->bucket[seg->i][i];
			}
		}
		seg->bucket[seg->i + 1][parent] = max;
		index /= seg->chunk;
	}
}

int top(Segment *seg) {
	int index = 0;
	for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
		int s = index * seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->bucket[seg->i]) {
			t = seg->bucket[seg->i];
		}
		for (int i = s; i < t; i++) {
			if (seg->bucket[seg->i][i] == seg->bucket[seg->i + 1][index]) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int main() {
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}
	Segment seg;
	init(&seg, getNextInt(fp));
	int m = getNextInt(fp);

	for (int i = 0; i < seg.n; i++) {
		maximize(&seg, i, getNextInt(fp));
	}

	for (int i = 0; i < m; i++) {
		maximize(&seg, top(&seg), seg.bucket[seg.h - 1][0] >> 1);
	}

	int64_t ans = 0;
	for (int i = 0; i < seg.n; i++) {
		ans += seg.bucket[0][i];
	}

	printf("%lld\n", ans);

	return 0;
}

