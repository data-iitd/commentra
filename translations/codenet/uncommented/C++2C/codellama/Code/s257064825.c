#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int sum=0;
	char str[1000000];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
	{
		sum+=(str[i]-48);
	}
	if(sum%9==0)
	{
        printf("Yes\n");
	}
	else
	   printf("No\n");
}
