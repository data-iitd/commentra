#include <stdio.h>
#include <string.h>

int main() {
	char s[100000];
	scanf("%s", s);

	int max_tmp = 0;
	int max = 0;
	for (int i = 0; i < strlen(s); i++) {
		int flag = 0;
		switch (s[i]) {
		case 'A':
		case 'C':
		case 'T':
		case 'G':
			max_tmp++;
		default:
			flag = 1;
		}

		if (i == strlen(s)-1) {
			flag = 1;
		}
		if (flag == 1) {
			if (max < max_tmp) {
				max = max_tmp;
			}
			max_tmp = 0;
		}
	}
	printf("%d", max);
}
