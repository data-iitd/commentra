#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100000];
	scanf("%s",str);
	int sum=0;
	for(int i=0;str[i]!='\0';i++)
	{
		sum+=(str[i]-'0');
	}
	if(sum%9==0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

