#include <stdio.h>
#include <stdlib.h>

int main() {
	char *sage;
	scanf("%s", &sage);

	if (strcmp(sage, "1") == 0) {
		printf("Hello World\n");
	} else if (strcmp(sage, "2") == 0) {
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
}
