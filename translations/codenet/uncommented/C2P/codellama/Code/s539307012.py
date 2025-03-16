#include<stdio.h>

int main(void):
	int n,x,min,m,i
	scanf("%d %d %d",&n,&x,&min)
	x-=min
	for i in range(1,n):
		scanf("%d",&m)
		x-=m
		if min>m:
			min=m
	print(n+x/min)
	return 0

