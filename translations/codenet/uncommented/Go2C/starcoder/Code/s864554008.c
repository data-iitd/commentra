#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int n, m;
	char **nImg, **mImg;
} data;

data newData();
int match(data d, int x, int y);

int main() {
	data d = newData();
	if (match(d, 0, 0)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

data newData() {
	int n, m;
	scanf("%d %d", &n, &m);
	char **nImg = load(n);
	char **mImg = load(m);

	data ret = {n: n, m: m, nImg: nImg, mImg: mImg};
	return ret;
}

char **load(int cnt) {
	char **ret = malloc(cnt * sizeof(char *));
	for (int i = 0; i < cnt; i++) {
		ret[i] = malloc(100 * sizeof(char));
	}

	for (int i = 0; i < cnt; i++) {
		scanf("%s", ret[i]);
	}

	return ret;
}

int match(data d, int x, int y) {
	for (int i = 0; i < d.m; i++) {
		for (int j = 0; j < d.m; j++) {
			if (d.nImg[x+i][y+j]!= d.mImg[i][j]) {
				return 0;
			}
		}
	}

	return 1;
}

