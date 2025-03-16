#include <stdio.h>
#include <stdlib.h>

int main() {
	int x;
	scanf("%d", &x);
	int i = 1;
	int sum = 0;
	for(; ; i++) {
		sum += i;
		if(sum >= x) {
			break;
		}
	}
	printf("%d", i);
	return 0;
}

