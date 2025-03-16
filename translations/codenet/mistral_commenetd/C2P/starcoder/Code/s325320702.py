
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>

#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r)for(ll i=(l);i>=(r);i--)

#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 //10^5+5
#define PI 3.141592653589793238

#define swap(a,b) {ll c;c=b;b=a;a=c;}
#define cin(n) scanf("%lld",&(*n));

#define max2(a,b) (a>=b?a:b)
#define min2(a,b) (a>=b?b:a)
#define min3(a,b,c) (a<=b && a<=c?a:b<=c?b:c)
#define max3(a,b,c) (a>=b && a>=c?a:b>=c?b:c)
#define minn(n,a) {ll b=INF;rep(i,0,n) b=min2(b,a[i]);return b;}
#define maxn(n,a) {ll b=-INF;rep(i,0,n) b=max2(b,a[i]);return b;}

#define POW(a,b) {ll c=1;rep(i,0,b) c*=a;return c;}
#define POW_d(a,b) {double c=1;rep(i,0,b) c*=a;return c;}

#define gcd(a,b) (b?gcd(b,a%b):a)
#define lcm(a,b) (a/gcd(a,b)*b)

#define mod_MOD1(n) {n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
#define mod_p(n,p) {n+= n<0?((-n)/p+1)*p:0; return n%=p;}

#define change_into_num(s,len,p) (!p? 0 : POW(10,p-1)*(s[len-p]-'0') + change_into_num(s,len,p-1))

#define digits(a,b) (a/b?1+digits(a/b,b):1)
#define base(n,a,i) (i==1?n%a:base(n/a,a,i-1))

#define is_inArr1(x,n) ( x<0 || x>=n? 0 : 1 )
#define is_inArr2(y,x,h,w) ( y<0 || y>=h || x<0 || x>=w? 0 : 1 )

#define lr_lower(l,r,am,val,type) { \
    while(l<r){ \
        ll m=(l+r)/2; \
        if( (type)? (am<val) : (am<=val) ) r=m; \
        else l=m+1; \
    } \
}

#define lr_upper(l,r,am,val,type) { \
    while(l<r){ \
        ll m=(l+r)/2; \
        if( (type)? (am<=val) : (am<val) ) r=m; \
        else l=m+1; \
    } \
}

#define cmp_lower(a,b,type) ( (type)? (a==b) : (a<b) )
#define cmp_upper(a,b,type) ( (type)? (a==b) : (a<=b) )

#define lower_bound(a,l,r,val,type) { \
    while(l<r){ \
        ll m=(l+r)/2; \
        if( cmp_lower(a[m],val,type) ) r=m; \
        else l=m+1; \
    } \
    return l; \
}

#define upper_bound(a,l,r,val,type) { \
    while(l<r){ \
        ll m=(l+r)/2; \
        if( cmp_upper(a[m],val,type) ) r=m; \
        else l=m+1; \
    } \
    return l; \
}

#define count(a,l,r,x) { \
    ll ans=0; \
    rep(i,l,r) if(a[i]==x) ans++; \
    return ans; \
}

#define factor(n,new_common_plus) { \
    ll ans=1; \
    while(n%2==0) { \
        if(new_common_plus==1) ans*=2; \
        n/=2; \
    } \
    ll i=3; \
    while(i*i<=n) { \
        if(n%i==0) { \
            if(new_common_plus==1) ans*=i; \
            n/=i; \
            if(new_common_plus==2) ans*=i; \
        } \
        else i+=2; \
    } \
    if(n>1) { \
        if(new_common_plus==1) ans*=n; \
        if(new_common_plus==2) ans*=n; \
    } \
    return ans; \
}

#define judge_prime(n) (n==2 || n==3 || n==5 || n==7 || n==11 || n==13 || n==17 || n==19)

#define makeinv(x,mod,is_fac) (is_fac?m_inv(x,mod,1):m_inv(x,mod,0))
#define m_inv(x,mod,is_fac) { \
    ll ans=1,a=mod,b=x; \
    while(b) { \
        ll t=a/b; \
        a-=t*b; \
        swap(a,b); \
        if(is_fac) ans*=t; \
    } \
    return ans; \
}

#define m_f(x,mod) { \
    ll ans=1,a=x,b=mod; \
    while(b) { \
        ll t=a/b; \
        a-=t*b; \
        swap(a,b); \
        ans*=t; \
    } \
    return ans; \
}

#define mod_nck(n,k,mod) { \
    ll ans=1; \
    if(k>n-k) k=n-k; \
    rep(i,0,k) { \
        ans*=n-i; \
        ans%=mod; \
        ans*=m_inv(i+1,mod,0); \
        ans%=mod; \
    } \
    return ans; \
}

#define m_p(r,n,mod) { \
    ll ans=1; \
    while(n) { \
        if(n&1) ans*=r; \
        ans%=mod; \
        r*=r; \
        r%=mod; \
        n>>=1; \
    } \
    return ans; \
}

#define m_mul2(a,b,mod) { \
    ll ans=0; \
    ans+=a*b; \
    ans%=mod; \
    ans+=mod; \
    ans%=mod; \
    return ans; \
}

#define m_mul3(a,b,c,mod) { \
    ll ans=0; \
    ans+=a*b; \
    ans%=mod; \
    ans+=c; \
    ans%=mod; \
    ans+=mod; \
    ans%=mod; \
    return ans; \
}

#define m_mul4(a,b,c,d,mod) { \
    ll ans=0; \
    ans+=a*b; \
    ans%=mod; \
    ans+=c; \
    ans%=mod; \
    ans+=d; \
    ans%=mod; \
    ans+=mod; \
    ans%=mod; \
    return ans; \
}

#define m_mul5(a,b,c,d,e,mod) { \
    ll ans=0; \
    ans+=a*b; \
    ans%=mod; \
    ans+=c; \
    ans%=mod; \
    ans+=d; \
    ans%=mod; \
    ans+=e; \
    ans%=mod; \
    ans+=mod; \
    ans%=mod; \
    return ans; \
}

#define upll(a,b) (*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0)
#define downll(a,b) (*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0)
#define cmp_string(a,b) strcmp( (char *)a, (char *)b )
#define cmp_char(a,b) *(char *)a - *(char *)b

#define sortup(a,n) qsort(a,n,sizeof(ll),upll)
#define sortdown(a,n) qsort(a,n,sizeof(ll),downll)
#define sort_string(n,size,s) qsort( (void*)s, n, sizeof(s[0]), cmp_string )
#define sort_char(s) qsort( (void *)s, strlen(s), sizeof(char), cmp_char )

#define unique_string(n,size,s) { \
    ll ans=1; \
    rep(i,1,n) if( strcmp(s[i],s[i-1]) ) ans++; \
    return ans; \
}

#define unique_num(n,a) { \
    ll ans=1; \
    rep(i,1,n) if( a[i]!=a[i-1] ) ans++; \
    return ans; \
}

char s[1151154];

int main(void){
    ll l,r,d;
    ll ans=0;

    cin(&l);
    cin(&r);
    cin(&d);

    rep(i,l,r+1){
        if(i%d==0) ans++;
    }

    printf("%lld\n",ans);

    return 0;
}

