#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char source[100];
	scanf("%s", source);

	if(strlen(source) > 10 || strlen(source) < 1)
	{
		return -1;
	}

	int max_i = pow(2, strlen(source) - 1);

	double sum = 0;

	for (int i = 0; i < max_i; ++i)
	{
		char plus[100];
		sprintf(plus, "%d", i);

		double number = 0;

		char working[100];
		strcpy(working, source);
		while(strlen(plus) > 0)
		{
			int i = 0;
			while(plus[i] != '1') ++i;
			sum += atof(working);
			plus[i] = '\0';
			working = working + i + 1;
		}
		sum += atof(working);
	}

	printf("%.0f\n", sum);


	return 0;
}

