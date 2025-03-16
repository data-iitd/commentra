#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[1000000];
	scanf("%s", s);

	int count = 0;
	int counter[1000000];

	if (s[0] == '\0') {
		return 0;
	}
	counter[0] = 0;
	int i = 0;
	while (s[i]!= '\0') {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			count++;
		} else {
			counter[i] = count;
			count = 0;
		}
		i++;
	}
	counter[i] = count;
	qsort(counter, i + 1, sizeof(int), compare);
	printf("%d", counter[i]);
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

