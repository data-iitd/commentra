#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str = (char *)malloc(100 * sizeof(char));
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		if (strcmp(str, "Yes") == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
