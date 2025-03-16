#include<stdio.h>
#include<string.h>
int main()
{
	char z[100000];
	scanf("%s", z);
	int a = strlen(z);
	for(int i = 0; i < a - 1; i++)
	{
		if(z[i] == z[i + 1])
		{
			printf("Bad\n");
			return 0;
		}
	}
	printf("Good\n");
}

