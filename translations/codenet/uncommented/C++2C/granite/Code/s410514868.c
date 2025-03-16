
#include <stdio.h>
typedef long long ll;
ll n,k,ans,L,ans2;
char s[100005];

int main(void){
    scanf("%lld%lld%s",&n,&k,s);
    L=s[0];
    ll cnt=0;
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
    printf("%lld\n",ans+min(2*k,ans2-1));
    }


