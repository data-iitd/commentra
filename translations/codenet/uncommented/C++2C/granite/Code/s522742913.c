
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	char source[101];
	fgets(source, 101, stdin);

	if(strlen(source) > 10 || strlen(source) < 1)
	{
		return -1;
	}

	int max_i = (int)pow(2, strlen(source) - 1);

	double sum = 0;

	for (int i = 0; i < max_i; ++i)
	{
		bool plus[100];
		for (int j = 0; j < 100; ++j)
		{
			plus[j] = (i & (1 << j))!= 0;
		}

		double number = 0;

		char working[101];
		strcpy(working, source);
		int j = 0;
		while(plus[j])
		{
			sum += atof(strtok(working, " "));
			++j;
		}
		sum += atof(strtok(NULL, " "));
	}

	printf("%.0f\n", sum);


	return 0;
}

