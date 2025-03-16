


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[1000];
	scanf("%s", s);
	char *new_s = str_replace(s, "2017", "2018", -1);
	printf("%s", new_s);
	free(new_s);
}

char *str_replace(char *s, char *old, char *new, int count) {
	int i, j, k, l;
	char *new_s;
	l = strlen(old);
	k = strlen(new);
	if (count == -1) {
		count = 0;
		for (i = 0; s[i]!= '\0'; i++) {
			count++;
		}
	}
	new_s = (char *) malloc(sizeof(char) * (i + k * count + 1));
	for (i = 0, j = 0; i < count; i++) {
		while (s[j]!= old[0] || (s[j] == old[0] && strncmp(s + j, old, l)!= 0)) {
			new_s[i + k * i] = s[j];
			j++;
			if (s[j] == '\0') {
				strcpy(new_s + i + k * i, s + j);
				return new_s;
			}
		}
		for (j = 0; j < k; j++) {
			new_s[i + k * i] = new[j];
		}
	}
	return new_s;
}

