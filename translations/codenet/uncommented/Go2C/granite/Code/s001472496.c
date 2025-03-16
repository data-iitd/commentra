
#include <stdio.h>

int main() {
	char s[100];
	scanf("%s", s);

	int max_tmp = 0;
	int max = 0;
	for (int i = 0; i < strlen(s); i++) {
		bool flag = false;
		switch (s[i]) {
		case 'A':
		case 'C':
		case 'T':
		case 'G':
			max_tmp++;
			break;
		default:
			flag = true;
			break;
		}

		if (i == strlen(s)-1) {
			flag = true;
		}
		if (flag == true) {
			if (max < max_tmp) {
				max = max_tmp;
			}
			max_tmp = 0;
		}
	}
	printf("%d\n", max);
	return 0;
}
