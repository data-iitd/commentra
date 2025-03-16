#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, X;
	scanf("%d %d", &N, &X);
	int L[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &L[i]);
	
	int i;
	int d = 0;
	for(i = 0; i < N; i++){
		d = d + L[i];
		if(d > X)
			break;
	}

	printf("%d\n", i+1);
}

