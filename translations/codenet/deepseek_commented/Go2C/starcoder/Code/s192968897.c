#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char s[100000];
	scanf("%s", s);
	int l = strlen(s);
	char ans[100000] = "AC";
	if (s[0]!= 'A') {
		ans[0] = 'W';
		ans[1] = 'A';
	}
	int cnt = 0;
	for (int i = 1; i < l; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (i == 1 || i == l-1 || s[i]!= 'C') {
				ans[0] = 'W';
				ans[1] = 'A';
			}
			cnt++;
		}
	}
	if (cnt!= 1) {
		ans[0] = 'W';
		ans[1] = 'A';
	}
	printf("%s\n", ans);
}

