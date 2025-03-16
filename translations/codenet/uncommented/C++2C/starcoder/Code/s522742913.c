#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	char source[100];
	scanf("%s", source);

	if(strlen(source) > 10 || strlen(source) < 1)
	{
		return -1;
	}

	int max_i = (int)pow(2, strlen(source) - 1);

	double sum = 0;

	for (int i = 0; i < max_i; ++i)
	{
		bool plus[100];
		memset(plus, 0, sizeof(plus));
		for (int j = 0; j < 100; ++j)
		{
			if(i & (1 << j))
			{
				plus[j] = true;
			}
		}

		double number = 0;

		char working[100];
		strcpy(working, source);
		while(plus[0])
		{
			int i = 0;
			while(!plus[i]) ++i;
			sum += atof(working);
			plus[i] = false;
			working[i] = '\0';
		}
		sum += atof(working);
	}

	printf("%.0lf\n", sum);


	return 0;
}

