#include <stdio.h>

int main() {
	char s[100000];
	scanf("%s", s);
	int ans = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '1') {
			ans++;
		}
	}
	printf("%d\n", ans);
}
