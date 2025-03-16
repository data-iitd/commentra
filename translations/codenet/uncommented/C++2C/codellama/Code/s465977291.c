#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,d;
	scanf("%d %d",&n,&d);

	double a = d*2+1;
	printf("%.0lf\n",ceil(n/a));


	return 0;
}
