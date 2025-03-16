#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char *s;
	int count = 0;
	int *counter;
	int i;
	int len;

	scanf("%s", s);

	if (s[0] == '\0') {
		return 0;
	}

	counter = (int *)malloc(sizeof(int));
	counter[0] = 0;
	char *li = strtok(s, "");

	for (i = 0; li != NULL; i++) {
		if (li[0] == 'A' || li[0] == 'C' || li[0] == 'G' || li[0] == 'T') {
			count++;
		} else {
			counter = (int *)realloc(counter, (i + 1) * sizeof(int));
			counter[i] = count;
			count = 0;
		}
		li = strtok(NULL, "");
	}

	counter = (int *)realloc(counter, (i + 1) * sizeof(int));
	counter[i] = count;
	sort(counter, counter + i + 1);
	printf("%d\n", counter[i]);

	return 0;
}

