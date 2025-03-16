#include <stdio.h>

// S....M....E
// R...RL...LR
int searchRange(char *text, int start, int limit) {
	int middle = -1;

	for (int i = start; i < limit; i++) {
		if (text[i] != 'R') {
			middle = i;
			break;
		}
	}

	int end = limit;

	for (int i = middle; i < limit; i++) {
		if (text[i] != 'L') {
			end = i;
			break;
		}
	}

	return start, middle, end;
}

void answer() {
	char text[1000];
	int limit;
	int start = 0;
	int middle = 0;
	int end = 0;
	int firstPrinted = 0;

	scanf("%s", text);
	limit = strlen(text);

	for (int i = 0; i < limit; i++) {
		if (text[i] != 'R') {
			start = i;
			break;
		}
	}

	for (int i = start; i < limit; i++) {
		if (text[i] != 'L') {
			end = i;
			break;
		}
	}

	for (int i = start; i < middle-1; i++) {
		if (firstPrinted) {
			printf(" ");
		}
		printf("0");
		firstPrinted = 1;
	}

	int len1 = middle - start;
	int len2 = end - middle;

	int count1 = (len1+1)/2 + len2/2;
	int count2 = len1/2 + (len2+1)/2;

	if (firstPrinted) {
		printf(" ");
	}
	printf("%v %v", count1, count2);
	firstPrinted = 1;

	for (int i = middle + 1; i < end; i++) {
		if (firstPrinted) {
			printf(" ");
		}
		printf("0");
		firstPrinted = 1;
	}
	printf("\n");
}

int main() {
	answer();
	return 0;
}

