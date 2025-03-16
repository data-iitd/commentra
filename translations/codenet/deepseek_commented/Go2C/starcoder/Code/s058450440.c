#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, j, k, l, m, ans = 0;
	char c;
	int a[5] = {0};
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c", &c);
		switch (c) {
		case 'M':
			a[0]++;
			break;
		case 'A':
			a[1]++;
			break;
		case 'R':
			a[2]++;
			break;
		case 'C':
			a[3]++;
			break;
		case 'H':
			a[4]++;
			break;
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 5; j++) {
			for (k = j + 1; k < 5; k++) {
				ans += a[i] * a[j] * a[k];
			}
		}
	}
	printf("%d", ans);
	return 0;
}

