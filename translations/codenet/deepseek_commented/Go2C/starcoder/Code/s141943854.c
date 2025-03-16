
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check function logs fatal errors if they occur
void check(char *message) {
	if (message!= NULL) {
		fprintf(stderr, "error: %s\n", message);
		exit(1);
	}
}

int main() {
	char *sage;
	scanf("%s", &sage);

	if (strcmp(sage, "1") == 0) {
		printf("Hello World\n");
	} else if (strcmp(sage, "2") == 0) {
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			scanf("%d", &sum);
			sum += sum;
		}
		printf("%d\n", sum);
	}
}

