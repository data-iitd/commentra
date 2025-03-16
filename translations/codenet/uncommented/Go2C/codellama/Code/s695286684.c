#include <stdio.h>
#include <string.h>

int main() {
	char s[100];
	scanf("%s", s);
	printf("%s\n", str_replace(s, "2017", "2018"));
	return 0;
}

char *str_replace(char *str, char *old, char *new) {
	char *p, *q, *r;
	int len_old, len_new;
	int count = 0;

	len_old = strlen(old);
	len_new = strlen(new);

	for (p = str; *p != '\0'; p++) {
		if (strncmp(p, old, len_old) == 0) {
			count++;
		}
	}

	p = str;
	r = malloc(strlen(str) + count * (len_new - len_old) + 1);
	q = r;

	while (*p != '\0') {
		if (strncmp(p, old, len_old) == 0) {
			strcpy(q, new);
			q += len_new;
			p += len_old;
		} else {
			*q++ = *p++;
		}
	}

	*q = '\0';
	return r;
}

