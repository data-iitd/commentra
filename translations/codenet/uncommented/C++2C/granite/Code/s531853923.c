
#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a*b%2==1&&(c+d)%2==1)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
}
