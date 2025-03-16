
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int a, b; scanf("%d %d", &a, &b);

	char bstr[100000];
	sprintf(bstr, "%d", b);

	int num = a * pow(10, strlen(bstr)) + b;

	int i;
	for (i = 1; i <= 100100; i++)
	{
		if (i * i == num) break;
	}

	if (i > 100100) printf("No\n");
	else printf("Yes\n");
}

