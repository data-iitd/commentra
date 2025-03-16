#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	scanf("%s", s);
	printf("%s", str_replace(s, "2017", "2018"));
}

char* str_replace(char* s, char* old, char* new) {
	int len = strlen(s);
	int old_len = strlen(old);
	int new_len = strlen(new);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < len) {
		if (s[i] == old[j]) {
			for (k = 0; k < new_len; k++) {
				s[i + k] = new[k];
			}
			i += new_len;
			j = 0;
		} else {
			i++;
		}
	}
	return s;
}

