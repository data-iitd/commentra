#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, j, k, l, m, ans = 0;
	int a[100000];
	char s[100000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		switch (s[0]) {
		case 'M':
			a[i] = 1;
			break;
		case 'A':
			a[i] = 2;
			break;
		case 'R':
			a[i] = 3;
			break;
		case 'C':
			a[i] = 4;
			break;
		case 'H':
			a[i] = 5;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				for (l = k + 1; l < n; l++) {
					for (m = l + 1; m < n; m++) {
						ans += a[i] * a[j] * a[k] * a[l] * a[m];
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}

