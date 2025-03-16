#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>

int main()
{
	int n,t;
	while(scanf("%d",&n),n){
		int st[7]={0};
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			char ans[8]={0};
			for(int j=0;j<7;j++){
				ans[j]=st[j]^seg[t][j]?'1':'0';
				st[j]=seg[t][j];
			}
			printf("%s\n",ans);
		}
	}
	
	return 0;
}

