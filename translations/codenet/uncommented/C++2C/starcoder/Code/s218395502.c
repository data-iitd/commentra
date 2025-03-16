
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if ((100*a + 10*b + c) % 4 == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

