#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scanString() {
	char *res = malloc(10000);
	scanf("%s", res);
	return res;
}

int scanInt() {
	int res;
	scanf("%d", &res);
	return res;
}

int scanInts(int n) {
	int res[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &res[i]);
	}
	return res;
}

void debug(char *a) {
	printf("%s\n", a);
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	char *s = scanString();
	char *t = scanString();

	char **ans = malloc(10000);
	int ans_len = 0;
	for (int i = 0; i < strlen(s) - strlen(t) + 1; i++) {
		int f = 1;
		char *ss = malloc(10000);
		strcpy(ss, s);

		for (int j = 0; j < strlen(t); j++) {
			if (s[i+j] != t[j] && s[i+j] != '?') {
				f = 0;
				break;
			} else {
				ss[i+j] = t[j];
			}
		}
		if (f) {
			ans[ans_len] = malloc(10000);
			strcpy(ans[ans_len], ss);
			ans_len++;
		}
	}
	qsort(ans, ans_len, sizeof(char *), cmp);
	if (ans_len == 0) {
		printf("UNRESTORABLE\n");
	} else {
		printf("%s\n", ans[0]);
	}
	return 0;
}

int cmp(const void *a, const void *b) {
	return strcmp(*(char **)a, *(char **)b);
}

