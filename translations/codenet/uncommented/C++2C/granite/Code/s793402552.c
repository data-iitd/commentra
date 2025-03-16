
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b; scanf("%d %d", &a, &b);
	int num = a * pow(10, (int)log10(b) + 1) + b;

	int i;
	for (i = 1; i <= 100100; i++)
	{
		if (i * i == num) break;
	}

	if (i > 100100) printf("No\n");
	else printf("Yes\n");
}

