#include <stdio.h>
#include <stdlib.h>

int main() {
	int c[3][3], a[3], b[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		a[i] = c[0][i];
		b[i] = c[0][i] - a[0];
	}
	if (a[1] == c[1][0] - c[0][0] && a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
		a[2] == c[2][0] - c[0][0] && a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
