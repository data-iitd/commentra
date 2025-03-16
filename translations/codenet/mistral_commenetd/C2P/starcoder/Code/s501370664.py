
#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

int main(){
	int n,i,cnt;
	int flag[MAX+1];

	for(i = 2;i <= MAX;i++){
		flag[i] = 0;
	}

	for(i = 2;i*i <= MAX;i++){
		if(flag[i] == 0){
			for(int j = i;i*j <= MAX;j++){
				flag[i*j] = 1;
			}
		}
	}

	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		i = 2;
		cnt = 0;
		while(i*i <= n){
			if(!flag[i] &&!flag[n-i]){
				cnt++;
			}
			i++;
		}
		printf("%d\n",cnt);
	}

	return 0;
}

