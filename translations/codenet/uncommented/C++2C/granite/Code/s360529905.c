
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int main(void)
{
	int *a,*b,i,N;
	int frontHalf,backHalf;
	scanf("%d",&N);
	a= (int *)malloc(sizeof(int)*N);
	b= (int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
	{
		scanf("%d",a+i);
		b[i]=a[i];
	}
	std::sort(b,b+N);
	frontHalf=b[N/2-1];
	backHalf=b[N/2];
	free(b);
	for(i=0;i<N;i++)
	{
		if(a[i]<backHalf)
			printf("%d\n",backHalf);
		else
			printf("%d\n",frontHalf);
	}
	free(a);
	return 0;
}
