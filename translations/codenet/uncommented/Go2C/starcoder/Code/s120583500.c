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
	int j = 0;
	while (j < i) {
		if (counter[j] > counter[i]) {
			int temp = counter[j];
			counter[j] = counter[i];
			counter[i] = temp;
		}
		j++;
	}
	printf("%d", counter[i]);
}

