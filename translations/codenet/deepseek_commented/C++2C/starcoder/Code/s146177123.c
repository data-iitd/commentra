#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,t;
	while(scanf("%d",&n),n){
		int st[7]={0};
		while(n--){
			scanf("%d",&t);
			char ans[8]={0};
			for(int i=0;i<7;i++){
				ans[i]=st[i]^seg[t][i]?'1':'0';
				st[i]=seg[t][i];
			}
			printf("%s\n",ans);
		}
	}
	return 0;
}

