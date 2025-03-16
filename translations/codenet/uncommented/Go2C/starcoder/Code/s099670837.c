#include <stdio.h>

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	int a[2][101] = {0};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == 0 && j == 0) {
					ans = a[i][j] + a[i][k];
				}
				if (i == 0 && j == k) {
					ans = a[i][j] + a[i][k];
				}
				if (i == 0 && j == k) {
					ans = a[i][j] + a[i][k];
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
