#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>
typedef long long ll;
typedef long double ld;
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

def swap(a,b):
    c=b
    b=a
    a=c

def cin(n):
    scanf("%lld",&n)

def max2(a,b):
    return a>=b?a:b

def min2(a,b):
    return a>=b?b:a

def min3(a,b,c):
    return (a<=b and a<=c) ? a : b<=c ? b : c

def max3(a,b,c):
    return (a>=b and a>=c) ? a : b>=c ? b : c

def minn(n,a):
    b=INF
    rep(i,0,n)
        b=min2(b,a[i])
    return b

def maxn(n,a):
    b=-INF
    rep(i,0,n)
        b=max2(b,a[i])
    return b

def POW(a,b):
    c=1
    rep(i,0,b)
        c*=a
    return c

def POW_d(a,b):
    c=1
    rep(i,0,b)
        c*=a
    return c

def gcd(a,b):
    return b?gcd(b,a%b):a

def lcm(a,b):
    return a/gcd(a,b)*b

def mod_MOD1(n):
    n+= n<0?((-n)/MOD1+1)*MOD1:0
    return n%MOD1

def mod_p(n,p):
    n+= n<0?((-n)/p+1)*p:0
    return n%p

def change_into_num(s,len,p):
    return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + change_into_num(s,len,p-1)

def digits(a,b):
    return a/b?1+digits(a/b,b):1

def base(n,a,i):
    return i==1?n%a:base(n/a,a,i-1)

def is_inArr1(x,n):
    return ( x<0 or x>=n ) ? 0 : 1

def is_inArr2(y,x,h,w):
    return ( y<0 or y>=h or x<0 or x>=w ) ? 0 : 1

def lr_lower(l,r,am,val,type):
    (type<3) ? ( am < val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) ) : ( am <= val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) )

def lr_upper(l,r,am,val,type):
    (type<3) ? ( am <= val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) ) : ( am < val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) )

def cmp_lower(a,b,type):
    return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a>=b ? 1 : 0 ) : ( a>b ? 1 : 0 )

def cmp_upper(a,b,type):
    return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a<=b ? 1 : 0 ) : ( a<b ? 1 : 0 )

def lower_bound(a,l,r,val,type):
    while r-l>1:
        lr_lower(&l,&r,a[(l+r)/2],val,type)
    return cmp_lower(a[l],val,type) ? l : cmp_lower(a[r],val,type) ? r : -1

def upper_bound(a,l,r,val,type):
    while r-l>1:
        lr_upper(&l,&r,a[(l+r)/2],val,type)
    return cmp_upper(a[r],val,type) ? r : cmp_upper(a[l],val,type) ? l : -1

def count(a,l,r,x):
    p = lower_bound(a,l,r,x,1)
    return p==-1 ? 0 : upper_bound(a,p,r,x,1)-p+1

def factors[2] , fac_cnt=0 , is_factor_prepared=0;
def factor_pre():
    rep(i,0,1):
        if is_factor_prepared:
            return 0
    tmp=(1e6)/2+1
    fac_tmp[tmp]
    rep(i,1,tmp):
        if fac_tmp[i]:
            repp(j,3,tmp/(2*i+1)+1,2):
                if j*(2*i+1)<tmp:
                    fac_tmp[ (j*(2*i+1)-1)/2 ]=0
    rep(i,0,tmp):
        if fac_tmp[i]:
            rep(j,0,2):
                factors[j] = realloc( factors[j] , sizeof(ll)*( fac_cnt +1 ) )
                factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i]
    return 0

def factor(n,new_common_plus):
    factor_pre()
    rep(i,0,fac_cnt):
        cnt=0
        rep(j,0,1):
            while ( cnt+= n %factors[0][i]==0 ? 1 : 0 )  and (n/=factors[0][i]) %factors[0][i]==0:
                continue
        factors[1][i]= new_common_plus==1 ? cnt :  new_common_plus==2 ? max2(factors[1][i],cnt) : factors[1][i]+cnt
        if factors[0][i]> n:
            break
    return n

def judge_prime(n):
    factor_pre()
    rep(i,0,fac_cnt):
        if n<factors[0][i]*factors[0][i] or n==factors[0][i]:
            break
        else if n%factors[0][i]==0:
            n/=n
    return n==1?0:1

def makeinv(n,mod):
    rep(i,0,1):
        if is_minv_made:
            return 0
    inv_arr = realloc(inv_arr, sizeof(ll)*2 )
    finv_arr = realloc(finv_arr, sizeof(ll)*2 )
    inv_arr[1]=1
    finv_arr[0]=finv_arr[1]=1
    rep(i,2,n+1):
        inv_arr = realloc(inv_arr, sizeof(ll)*(i+1) )
        finv_arr = realloc(finv_arr, sizeof(ll)*(i+1) )
        inv_arr[i]= mod - inv_arr[mod%i] * (mod / i) % mod
        finv_arr[i] = finv_arr[i - 1] * inv_arr[i] % mod
    return 0

def make_mf(n,mod):
    rep(i,0,1):
        if is_mf_made:
            return 0
    mf_arr = realloc(mf_arr, sizeof(ll)*2 )
    ll x=1
    mf_arr[0]=mf_arr[1]=x
    rep(i,2,n+1):
        x=x*i%mod
        mf_arr = realloc(mf_arr, sizeof(ll)*(i+1) )
        mf_arr[i]=x
    return 0

def m_inv(x,mod,is_fac):
    makeinv(num_of_inv,mod)
    return is_fac?finv_arr[x]:inv_arr[x]

def m_f(x,mod):
    make_mf(num_of_inv,mod)
    return mf_arr[x]

def mod_nck(n,k,mod):
    return m_f(n,mod)*m_inv(k,mod,1)%mod*m_inv(n-k,mod,1)%mod

def m_p(r,n,mod):
    t=1
    s=r
    while n>0:
        t = (n&1) ? t*s%mod : t
        s=s*s%mod
        n>>=1
    return r?t:0

def m_mul2(a,b,mod):
    return a*b%mod

def m_mul3(a,b,c,mod):
    return m_mul2(a*b%mod,c,mod)

def m_mul4(a,b,c,d,mod):
    return m_mul3(a*b%mod,c,d,mod)

def m_mul5(a,b,c,d,e,mod):
    return m_mul4(a*b%mod,c,d,e,mod)

def upll(a,b):
    return a<b?-1:a>b?1:0

def downll(a,b):
    return a<b?1:a>b?-1:0

def cmp_string(a,b):
    return strcmp(a,b)

def sortup(a,n):
    qsort(a,n,sizeof(ll),upll)

def sortdown(a,n):
    qsort(a,n,sizeof(ll),downll)

def sort_string(n,size,s):
    qsort(s,n,sizeof(s[0]),cmp_string)

def sort_char(s):
    qsort(s,strlen(s),sizeof(char),cmp_char)

def unique_string(n,size,s):
    ans=1
    rep(i,1,n):
        if strcmp(s[i],s[i-1]):
            ans++
    return ans

def unique_num(n,a):
    ans=1
    rep(i,1,n):
        if a[i]!=a[i-1]:
            ans++
    return ans

def cmp1(p,q):
    return ((fr*)p) ->a - ((fr*)q)->a

def cmp2(p,q):
    return ((fr*)q) ->a - ((fr*)p)->a

def strsortup(a,n):
    qsort(a,n,sizeof(fr),cmp1)

def strsortdown(a,n):
    qsort(a,n,sizeof(fr),cmp2)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>
typedef long long ll;
typedef long double ld;
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

def swap(a,b):
    c=b
    b=a
    a=c

def cin(n):
    scanf("%lld",&n)

def max2(a,b):
    return a>=b?a:b

def min2(a,b):
    return a>=b?b:a

def min3(a,b,c):
    return (a<=b and a<=c) ? a : b<=c ? b : c

def max3(a,b,c):
    return (a>=b and a>=c) ? a : b>=c ? b : c

def minn(n,a):
    b=INF
    rep(i,0,n)
        b=min2(b,a[i])
    return b

def maxn(n,a):
    b=-INF
    rep(i,0,n)
        b=max2(b,a[i])
    return b

def POW(a,b):
    c=1
    rep(i,0,b)
        c*=a
    return c

def POW_d(a,b):
    c=1
    rep(i,0,b)
        c*=a
    return c

def gcd(a,b):
    return b?gcd(b,a%b):a

def lcm(a,b):
    return a/gcd(a,b)*b

def mod_MOD1(n):
    n+= n<0?((-n)/MOD1+1)*MOD1:0
    return n%MOD1

def mod_p(n,p):
    n+= n<0?((-n)/p+1)*p:0
    return n%p

def change_into_num(s,len,p):
    return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + change_into_num(s,len,p-1)

def digits(a,b):
    return a/b?1+digits(a/b,b):1

def base(n,a,i):
    return i==1?n%a:base(n/a,a,i-1)

def is_inArr1(x,n):
    return ( x<0 or x>=n ) ? 0 : 1

def is_inArr2(y,x,h,w):
    return ( y<0 or y>=h or x<0 or x>=w ) ? 0 : 1

def lr_lower(l,r,am,val,type):
    (type<3) ? ( am < val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) ) : ( am <= val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) )

def lr_upper(l,r,am,val,type):
    (type<3) ? ( am <= val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) ) : ( am < val ?  ( l = (l+r)/2 ) : ( r= (l+r)/2 ) )

def cmp_lower(a,b,type):
    return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a>=b ? 1 : 0 ) : ( a>b ? 1 : 0 )

def cmp_upper(a,b,type):
    return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a<=b ? 1 : 0 ) : ( a<b ? 1 : 0 )

def lower_bound(a,l,r,val,type):
    while r-l>1:
        lr_lower(&l,&r,a[(l+r)/2],val,type)
    return cmp_lower(a[l],val,type) ? l : cmp_lower(a[r],val,type) ? r : -1

def upper_bound(a,l,r,val,type):
    while r-l>1:
        lr_upper(&l,&r,a[(l+r)/2],val,type)
    return cmp_upper(a[r],val,type) ? r : cmp_upper(a[l],val,type) ? l : -1

def count(a,l,r,x):
    p = lower_bound(a,l