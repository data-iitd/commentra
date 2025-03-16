#include<stdio.h>
#include<stdlib.h>

int main(){
	int m, nmi, nma;
	while(scanf("%d %d %d", &m, &nmi, &nma) && nmi!=0){
		int data[m];
		for(int i=0;i<m;i++)scanf("%d", &data[i]);
		int ma=0;
		int ans=0;
		for(int i=nmi-1;i<nma;i++){
			if(ma<=data[i]-data[i+1]){
				ans=i+1;
				ma=data[i]-data[i+1];
			}
		}
		printf("%d\n", ans);
	}
}

