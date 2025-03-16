
#include<stdio.h>

int main(){
	int n,d;
	scanf("%d %d",&n,&d);

	double a = d*2+1;
	printf("%.0f\n",ceil(n/a));


	return 0;
}
