#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int root(int i, int *uni);
void init(char *s, int *table);

int main() {
	char s[MAX_N], t[MAX_N];
	int ns, nt, i, j, m, r, rr, ans, counter[MAX_N];
	int uni[MAX_N];
	int ok[MAX_N];
	char sss[MAX_N * 2];

	scanf("%s", s);
	scanf("%s", t);

	ns = strlen(s);
	nt = strlen(t);

	for (i = 0; i < (nt - 1) / ns + 1; i++) {
		strcat(sss, s);
	}
	strcat(sss, s);

	for (i = 0; i < ns; i++) {
		uni[i] = i;
	}

	init(t, table);
	m = 0;
	for (i = 0; i < ns; i++) {
		ok[i] = true;
		for (m = 0; m < nt; m++) {
			if (t[m] != sss[i + m]) {
				ok[i] = false;
				break;
			}
		}
		if (ok[i]) {
			i += nt - table[m];
			m = table[m];
		}
		for (m >= 0 && t[m] != sss[i + m]; m = table[m]) {
			i += m - table[m];
		}
		i--;
		m++;
	}

	ans = 0;
	for (i = 0; i < ns; i++) {
		if (ok[i] == false) {
			continue;
		}
		if (ok[(i + nt) % ns] == false) {
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
		r = root(i, uni);
		if (ok[r] == false) {
			continue;
		}
		counter[r]++;
	}
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

void init(char *s, int *table) {
	int n = strlen(s);
	int j = -1;
	for (int i = 0; i < n; i++) {
		for (j >= 0 && s[i] != s[j]; j = table[j]) {
			j = table[j];
		}
		j++;
		table[i + 1] = j;
	}
}

