#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void out(int x, ...) {
	printf("%d\n", x);
}

int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

char *getString() {
	char *s = (char *)malloc(sizeof(char) * 100);
	scanf("%s", s);
	return s;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	int N, C, K;
	int *t;
	int i;
	int ans;
	int cnt;
	int end;

	N = getInt();
	C = getInt();
	K = getInt();
	t = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		t[i] = getInt();
	}

	qsort(t, N, sizeof(int), cmp);
	// out(t);
	ans = 1;
	cnt = 1;
	end = t[0] + K;
	for (i = 1; i < N; i++) {
		if (cnt < C && t[i] <= end) {
			cnt++;
			// out(t[i]);
		} else {
			// out("----");
			// out(t[i]);
			cnt = 1;
			end = t[i] + K;
			ans++;
		}
	}
	out(ans);
	return 0;
}

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

