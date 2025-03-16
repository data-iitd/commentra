#include <stdio.h>
#include <math.h>

int div(int n);

int main(){
	int num;
	scanf("%d", &num);
	printf("%d:", num);

	while(num!=1){
		printf(" %d", div(num));
		num = num / div(num);
	}
	printf("\n");
}

int div(int n){
	if(n%2 == 0) return 2;
	int s=sqrt(n);
	for(int i=3; i<=s; i+=2){
		if(n%i == 0) return i;
	}

	return n;
}

