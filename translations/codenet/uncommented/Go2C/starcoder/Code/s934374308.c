#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, K, R, S, P;
	char T[1000000];
	scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
	scanf("%s", T);

	int dict[3] = {0, 0, 0};
	char char;
	int s[N] = {1, 1, 1};
	int r[N] = {1, 1, 1};
	int p[N] = {1, 1, 1};
	for (int i = 0; i < N; i++) {
		if (i >= K) {
			if (T[i] == T[i-K]) {
				switch (T[i]) {
				case's':
					if (s[i%K]) {
						s[i%K] = 0;
						continue;
					} else {
						s[i%K] = 1;
					}

				case 'r':
					if (r[i%K]) {
						r[i%K] = 0;
						continue;
					} else {
						r[i%K] = 1;

					}

				case 'p':
					if (p[i%K]) {
						p[i%K] = 0;
						continue;
					} else {
						p[i%K] = 1;

					}
				}
			} else {
				switch (T[i]) {
				case's':
					s[i%K] = 1;
				case 'r':
					r[i%K] = 1;
				case 'p':
					p[i%K] = 1;
				}

			}
		}
		switch (T[i]) {
		case's':
			dict[0] = dict[0] + 1;
		case 'r':
			dict[1] = dict[1] + 1;
		case 'p':
			dict[2] = dict[2] + 1;
		}
	}

	int res = P*dict[1] + S*dict[2] + R*dict[0];
	printf("%d\n", res);

}

