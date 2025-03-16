#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int x=N%K;
	x=min(abs(x-K),x);
	printf("%d",x);
}
