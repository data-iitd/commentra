#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n,k,ans,L,ans2;
    char s[100000];
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    L=s[0];
    int cnt=0;
    for(int i=1;i<n;i++){
        if(L==s[i])cnt++;
        else {
            L=s[i];
            ans+=cnt;
            ans2++;
            cnt=0;
        }
    }
    ans+=cnt;
    ans2++;
    printf("%d\n",ans+min(2*k,ans2-1));
    }

