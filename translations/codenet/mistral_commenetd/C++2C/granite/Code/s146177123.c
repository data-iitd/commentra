

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,t;
	char st[7]={0};
	char ans[8]={0};

	while(scanf("%d",&n),~n){
		memset(st,0,sizeof(st));
		rep(i,n){
			scanf("%d",&t);
			rep(i,7){
				ans[i]=st[i]^(t>>i&1)?'1':'0';
				st[i]=(t>>i&1);
			}
			ans[7]='\0';
			puts(ans);
		}
	}

	return 0;
}



