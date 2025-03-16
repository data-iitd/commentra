#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MOD 1000000007

int main() {
	char week[7][3] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	char s[3];
	scanf("%s", s);
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(s, week[i]) == 0) {
			index = i;
			break;
		}
	}
	printf("%d\n", 7 - index);
	return 0;
}

