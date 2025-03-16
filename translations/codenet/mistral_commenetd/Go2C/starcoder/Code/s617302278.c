
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x;
	scanf("%d", &x);
	int sum = 0;
	int i = 1;
	while (1) {
		sum += i;
		if (sum >= x) {
			break;
		}
		i++;
	}
	printf("%d", i);
	return 0;
}

