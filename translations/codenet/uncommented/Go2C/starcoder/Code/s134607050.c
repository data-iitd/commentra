#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char text[1000000];
	scanf("%s", text);
	int limit = strlen(text);

	int start = 0;
	int middle = 0;
	int end = 0;
	int firstPrinted = 0;

	for (end = 0; end < limit; end++) {
		for (start = 0; start < end; start++) {
			if (text[start]!= 'R') {
				middle = start;
				break;
			}
		}

		for (int i = middle; i < end; i++) {
			if (text[i]!= 'L') {
				end = i;
				break;
			}
		}

		int len1 = middle - start;
		int len2 = end - middle;

		for (int i = start; i < middle-1; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = 1;
		}

		int count1 = (len1+1)/2 + len2/2;
		int count2 = len1/2 + (len2+1)/2;

		if (firstPrinted) {
			printf(" ");
		}
		printf("%d %d", count1, count2);
		firstPrinted = 1;

		for (int i = middle + 1; i < end; i++) {
			if (firstPrinted) {
				printf(" ");
			}
			printf("0");
			firstPrinted = 1;
		}
		start = end;
		firstPrinted = 1;
	}
	printf("\n");
}

