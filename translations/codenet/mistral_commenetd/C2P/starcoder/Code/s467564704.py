#include<stdio.h>
#include<stdlib.h>
#define N 4
int main()
{
	int input[N][N], tc;
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			scanf("%d",&input[i][j]);
		}
	}
	scanf("%d",&tc);
	for(int i = 0;i<tc;i++)
	{
		int testcase;
		scanf("%d",&testcase);
		for(int m = 0;m<N;m++)
		{
			for(int n = 0;n<N;n++)
			{
				if(input[m][n] == testcase)
				{
					input[m][n] = 0;
				}
			}
		}
	}
	if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0)
	{
		puts("Yes");
		exit(0);
	}
	else
	{
		puts("No");
		exit(1);
	}
	return 0;
}
