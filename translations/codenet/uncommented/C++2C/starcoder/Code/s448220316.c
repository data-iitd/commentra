#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#define N 100005
#define M 200005

int n,m,l,r,vi,fa[N],v[M];

int get(int x){
	if(x==fa[x])return x;
	int f=get(fa[x]);
	v[x]+=v[fa[x]];
	return fa[x]=f;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&vi);
		int li=get(l),ri=get(r);
		if(li!=ri){
			v[ri]=vi-v[r]+v[l];
			fa[ri]=li;
		}else{
			if(v[r]-v[l]!=vi){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
