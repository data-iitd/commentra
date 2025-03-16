#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	scanf("%s", a);
	char tmp[100];
	strcpy(tmp, a);
	strcpy(tmp, str_replace(tmp, "1", "0"));
	char b[100];
	strcpy(b, str_replace(tmp, "9", "1"));
	char ans[100];
	strcpy(ans, str_replace(b, "0", "9"));
	printf("%s\n", ans);
	return 0;
}

char *str_replace(char *str, char *old, char *new) {
	char *p = str;
	char *q = str;
	char *r = str;
	int len_old = strlen(old);
	int len_new = strlen(new);
	while (*p != '\0') {
		if (strncmp(p, old, len_old) == 0) {
			memcpy(q, new, len_new);
			q += len_new;
			p += len_old;
		} else {
			*q++ = *p++;
		}
	}
	*q = '\0';
	return r;
}

