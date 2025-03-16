
#include<stdio.h>
#include<stdlib.h>

int n,m,l,r,vi,fa[100005],v[200005];

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
