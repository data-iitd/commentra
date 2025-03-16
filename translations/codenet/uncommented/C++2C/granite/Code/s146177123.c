
#include<stdio.h>

int main()
{
	int n,t; int st[7];
	while(scanf("%d",&n),~n){
		rep(i,7)st[i]=0;
		rep(i,n){
			scanf("%d",&t);
			char ans[8]={0};
			rep(i,7){
				ans[i]=st[i]^(t>>i&1)?'1':'0';
				st[i]=t>>i&1;
			}
			puts(ans);
		}
	}
	
	return 0;
}

