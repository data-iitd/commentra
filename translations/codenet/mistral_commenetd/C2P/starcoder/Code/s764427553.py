
#include<stdio.h>

#define MAX_V 999999

int main(){
	int prime[MAX_V+1];
	for(i=0;i<=MAX_V;i++){
		prime[i]=1;
	}

	for(i=2;i<=MAX_V;i++){
		if(prime[i]){
			for(k=i*i;k<=MAX_V;k+=i){
				prime[k]=0;
			}
		}
	}

	prime[0]=0;
	prime[1]=0;

	int count=0;
	while(scanf("%d",&n)!=EOF){
		count++;
		int cnt=0;
		for(i=n;i>0;i--){
			if(prime[i]==1){
				cnt++;
			}
		}
		printf("%d\n",cnt);
		if(count==30)break;
	}
	return 0;
}

