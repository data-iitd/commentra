#include <stdio.h>
#include <string.h>

int main() {
	int N, K, R, S, P;
	char T[100000];
	scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
	scanf("%s", T);

	int dict[3] = {0, 0, 0};
	char char;
	int s[100000];
	for (int i = 0; i < N; i++) {
		s[i] = 1;
	}
	int r[100000];
	int p[100000];
	for (int i = 0; i < N; i++) {
		r[i] = s[i];
		p[i] = s[i];
	}
	for (int i = 0; i < strlen(T); i++) {
		char = T[i];
		if (i >= K) {
			if (char == T[i-K]) {
				switch (char) {
				case 's':
					if (s[i%K] == 1) {
						s[i%K] = 0;
						continue;
					} else {
						s[i%K] = 1;
					}

				case 'r':
					if (r[i%K] == 1) {
						r[i%K] = 0;
						continue;
					} else {
						r[i%K] = 1;

					}

				case 'p':
					if (p[i%K] == 1) {
						p[i%K] = 0;
						continue;
					} else {
						p[i%K] = 1;

					}
				}
			} else {
				switch (char) {
				case 's':
					s[i%K] = 1;
				case 'r':
					r[i%K] = 1;
				case 'p':
					p[i%K] = 1;
				}

			}
		}
		switch (char) {
		case 's':
			dict[0] = dict[0] + 1;
		case 'r':
			dict[1] = dict[1] + 1;
		case 'p':
			dict[2] = dict[2] + 1;
		}
	}

	int res = P*dict[1] + S*dict[2] + R*dict[0];
	printf("%d", res);

	return 0;
}

