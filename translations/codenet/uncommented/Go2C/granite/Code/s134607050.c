
#include <stdio.h>
#include <string.h>

// S....M....E
// R...RL...LR
void searchRange(char *text, int start, int limit, int *middle, int *end) {
	*middle = -1;

	for (int i = start; i < limit; i++) {
		if (text[i]!= 'R') {
			*middle = i;
			break;
		}
	}

	*end = limit;

	for (int i = *middle; i < limit; i++) {
		if (text[i]!= 'L') {
			*end = i;
			break;
		}
	}
}

void answer() {
	char text[1000001];
	scanf("%s", text);
	int limit = strlen(text);

	int start = 0;
	int middle = 0;
	int end = 0;
	bool firstPrinted = false;

	for (end = 0; end < limit; ) {
		searchRange(text, start, limit, &middle, &end);
		int len1 = middle - start;
		int len2 = end - middle;

		for (int i = start; i < middle - 1; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = true;
		}

		int count1 = (len1 + 1) / 2 + len2 / 2;
		int count2 = len1 / 2 + (len2 + 1) / 2;

		if (firstPrinted) {
			printf(" ");
		}
		printf("%d %d", count1, count2);
		firstPrinted = true;

		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = true;
		}
		start = end;
		firstPrinted = true;
	}
	printf("\n");
}

int main() {
	answer();
	return 0;
}
