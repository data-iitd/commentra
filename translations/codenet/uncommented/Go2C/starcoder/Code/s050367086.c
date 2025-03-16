#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[1000001];
	char t[1000001];
	scanf("%s%s", s, t);
	int ns = strlen(s);
	int nt = strlen(t);
	char ss[ns][ns];
	for (int i = 0; i < ns; i++) {
		for (int j = 0; j < ns; j++) {
			ss[i][j] = s[j];
		}
	}
	for (int i = 0; i < ns; i++) {
		for (int j = 0; j < nt; j++) {
			ss[i][j+ns] = s[j];
		}
	}
	int ok[ns];
	int uni[ns];
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}
	int m = 0;
	for (int i = 0; i < ns; i++) {
		ok[i] = 1;
		for (int j = 0; j < nt; j++) {
			if (t[j]!= ss[i][j+m]) {
				ok[i] = 0;
				break;
			}
		}
		if (ok[i]) {
			for (int j = 0; j < nt; j++) {
				if (t[j]!= ss[i][j+m]) {
					break;
				}
				m++;
			}
			i += nt - m;
			m = m;
		}
		for (int j = 0; j < nt; j++) {
			if (t[j]!= ss[i][j+m]) {
				i += m - m;
				m = m;
			}
		}
		i--;
		m++;
	}
	int ans = 0;
	int r, rr;
	for (int i = 0; i < ns; i++) {
		if (!ok[i]) {
			continue;
		}
		if (!ok[(i+nt)%ns]) {
			continue;
		}
		r = root(i, uni);
		rr = root((i+nt)%ns, uni);
		if (rr == r) {
			printf("-1");
			return 0;
		}
		uni[rr] = r;
	}
	int counter[ns];
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (!ok[r]) {
			continue;
		}
		counter[r]++;
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}
	printf("%d", ans);
	return 0;
}

int root(int i, int uni[]) {
	if (i == uni[i]) {
		return i;
	}
	uni[i] = root(uni[i], uni);
	return uni[i];
}

