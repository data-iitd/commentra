

#include<stdio.h>

int main()
{
	char s[100];
	scanf("%s", s);

	for (char i = 'a'; i <= 'z'; i++)
	{
		int a = 0;

		for (int j = 0; j < strlen(s); j++)
		{
			if (i==s[j])
			{
				a++;
			}
		}

		if (a==0)
		{
			printf("%c\n", i);
			break;
		}

		if (i=='z')
		{
			printf("None\n");
			break;
		}
	}
}

