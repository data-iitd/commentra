#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read() {
	static char str[100];
	fgets(str, sizeof(str), stdin);
	return str;
}

int main() {
	int a, b;
	char* token;
	char input[100];

	a = atoi(strtok(read(), " \n"));
	b = atoi(strtok(NULL, " \n"));

	int ret = a + b;

	if (ret < (a - b)) {
		ret = a - b;
	}
	if (ret < (a * b)) {
		ret = a * b;
	}

	printf("%d\n", ret);

	return 0;
}
