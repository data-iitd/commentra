#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *X;
} Data;

typedef struct {
	int len;
	Data *data;
} Datas;

int cmp(const void *a, const void *b) {
	return strcmp(((Data *)a)->X, ((Data *)b)->X);
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	Data *s = (Data *)malloc(sizeof(Data) * N);
	for (int i = 0; i < N; i++) {
		s[i].X = (char *)malloc(sizeof(char) * L);
		scanf("%s", s[i].X);
	}

	qsort(s, N, sizeof(Data), cmp);

	char *ans = (char *)malloc(sizeof(char) * N * L);
	for (int i = 0; i < N; i++) {
		strcat(ans, s[i].X);
	}
	printf("%s\n", ans);

	return 0;
}

