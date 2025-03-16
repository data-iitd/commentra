#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int xt, yt;
	int a[3][7] = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (x == a[i][j]) {
				xt = i;
			}
			if (y == a[i][j]) {
				yt = i;
			}
		}
	}
	if (xt == yt) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
