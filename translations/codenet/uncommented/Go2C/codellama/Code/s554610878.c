#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000

int mod = 1e9 + 7;

int main() {
	char *week[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	char *s;
	int index = -1;
	scanf("%s", s);
	for (int i = 0; i < 7; i++) {
		if (strcmp(s, week[i]) == 0) {
			index = i;
			break;
		}
	}

	printf("%d\n", 7 - index);
}

