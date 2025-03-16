#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int *heights = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &heights[i]);
	}
	int *t = malloc(sizeof(int) * (n + 1));
	t[0] = 0;
	for (int i = 1; i < n; i++) {
		t[i] = t[i - 1] + abs(heights[i] - heights[i - 1]);
		if (1 < i) {
			t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]));
		}
	}
	printf("%d\n", t[n - 1]);
	return 0;
}
