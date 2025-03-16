#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
	char X[100001];
} Data;

int N, L;
Data s[MAX_N];

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		scanf("%s", s[i].X);
	}
	qsort(s, N, sizeof(Data), cmp);
	char ans[100001];
	for (int i = 0; i < N; i++) {
		strcat(ans, s[i].X);
	}
	printf("%s", ans);
	return 0;
}

int cmp(const void *a, const void *b) {
	return strcmp(((Data*)a)->X, ((Data*)b)->X);
}

