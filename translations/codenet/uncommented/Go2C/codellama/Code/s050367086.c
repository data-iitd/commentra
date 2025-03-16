
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int root(int i, int *uni);

int main() {
	char s[MAX_N], t[MAX_N];
	int ns, nt, i, j, m, r, rr, ans;
	int uni[MAX_N];
	int ok[MAX_N];
	int counter[MAX_N];
	int table[MAX_N];
	int *p;

	scanf("%s", s);
	scanf("%s", t);

	ns = strlen(s);
	nt = strlen(t);

	for (i = 0; i < (nt - 1) / ns + 1; i++) {
		strcat(s, s);
	}

	sss = malloc(sizeof(char) * (ns * 2 + 1));
	strcpy(sss, s);
	strcat(sss, s);

	for (i = 0; i < ns; i++) {
		uni[i] = i;
	}

	for (i = 0; i < ns; i++) {
		ok[i] = 1;
	}

	for (i = 0; i < ns; i++) {
		if (ok[i] == 0) {
			continue;
		}
		if (ok[(i + nt) % ns] == 0) {
			continue;
		}
		r = root(i, uni);
		rr = root((i + nt) % ns, uni);
		if (rr == r) {
			printf("-1\n");
			return 0;
		}
		uni[rr] = r;
	}

	for (i = 0; i < ns; i++) {
		if (ok[i] == 0) {
			continue;
		}
		counter[i] = 0;
	}

	for (i = 0; i < ns; i++) {
		r = root(i, uni);
		if (ok[r] == 0) {
			continue;
		}
		counter[r]++;
	}

	ans = 0;
	for (i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}

int root(int i, int *uni) {
	if (i == uni[i]) {
		return i;
	}

	uni[i] = root(uni[i], uni);
	return uni[i];
}

