#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000

typedef struct {
	char s[MAX_N];
	int table[MAX_N];
} MP;

void init(MP *mp, char *s) {
	int n = strlen(s);
	int j = -1;
	for (int i = 0; i < n; i++) {
		for (; j >= 0 && s[i]!= s[j]; j = mp->table[j]) {
		}
		j++;
		mp->table[i+1] = j;
	}
	strcpy(mp->s, s);
}

int root(int i, int *uni) {
	if (i == uni[i]) {
		return i;
	}
	uni[i] = root(uni[i], uni);
	return uni[i];
}

int main() {
	FILE *fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	FILE *wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");

	MP mp;
	char s[MAX_N], t[MAX_N];

	fscanf(fp, "%s", s);
	fscanf(fp, "%s", t);

	int ns = strlen(s);
	int nt = strlen(t);
	char ss[MAX_N];
	for (int i = 0; i < (nt-1)/ns+1; i++) {
		strcpy(ss, s);
	}

	char sss[MAX_N];
	sprintf(sss, "%s%s", ss, ss);

	int ok[MAX_N];
	int uni[MAX_N];
	for (int i = 0; i < ns; i++) {
		ok[i] = 1;
		uni[i] = i;
	}
	int m = 0;
	int o;
	for (int i = 0; i < ns; i++) {
		o = 1;
		for (m = 0; m < nt; m++) {
			if (t[m]!= sss[i+m]) {
				o = 0;
				break;
			}
		}
		ok[i] = o;
		if (o) {
			i += nt - mp.table[m];
			m = mp.table[m];
		}
		for (m = 0; m >= 0 && t[m]!= sss[i+m]; m = mp->table[m]) {
			i += m - mp.table[m];
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
			fprintf(wfp, "-1\n");
			return 0;
		}
		uni[rr] = r;
	}

	int counter[MAX_N];
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

	fprintf(wfp, "%d\n", ans);

	fclose(fp);
	fclose(wfp);
	return 0;
}

