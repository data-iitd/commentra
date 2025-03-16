#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>

#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r) for(ll i=(l);i>=(r);i--)
#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 // Maximum character size
#define PI 3.141592653589793238

#define swap(a,b) a,b=b,a
#define cin(n) scanf("%lld", &n)

#define max2(a,b) a>=b?a:b
#define min2(a,b) a>=b?b:a
#define min3(a,b,c) (a<=b&&a<=c)?a:(b<=c?b:c)
#define max3(a,b,c) (a>=b&&a>=c)?a:(b>=c?b:c)

#define minn(n,a) (n,a=minn(n,a))
#define maxn(n,a) (n,a=maxn(n,a))

#define POW(a,b) (1,POW(a,b))
#define POW_d(a,b) (1,POW_d(a,b))

#define gcd(a,b) b?gcd(b,a%b):a
#define lcm(a,b) a/gcd(a,b)*b

#define mod_MOD1(n) n+=n<0?((-n)/MOD1+1)*MOD1:0,n%=MOD1
#define mod_p(n,p) n+=n<0?((-n)/p+1)*p:0,n%=p

#define change_into_num(s,len,p) (!p)?0:POW(10,p-1)*(s[len-p]-'0')+change_into_num(s,len,p-1)
#define digits(a,b) (a/b?1:1)+digits(a/b,b)

#define is_inArr1(x,n) (x<0||x>=n)?0:1
#define is_inArr2(y,x,h,w) (y<0||y>=h||x<0||x>=w)?0:1

#define lr_lower(l,r,am,val,type) (type<3)?(am<val?(*l=(*l+*r)/2):(*r=(*l+*r)/2)):((am<=val)?(*l=(*l+*r)/2):(*r=(*l+*r)/2))
#define lr_upper(l,r,am,val,type) (type<3)?(am<=val?(*l=(*l+*r)/2):(*r=(*l+*r)/2)):(am<val?(*l=(*l+*r)/2):(*r=(*l+*r)/2))

#define cmp_lower(a,b,type) (type==1)?(a==b?1:0):(type==2)?(a>=b?1:0):(a>b?1:0)
#define cmp_upper(a,b,type) (type==1)?(a==b?1:0):(type==2)?(a<=b?1:0):(a<b?1:0)

#define lower_bound(a,l,r,val,type) while(r-l>1)lr_lower(&l,&r,a[(l+r)/2],val,type);return cmp_lower(a[l],val,type)?l:cmp_lower(a[r],val,type)?r:-1
#define upper_bound(a,l,r,val,type) while(r-l>1)lr_upper(&l,&r,a[(l+r)/2],val,type);return cmp_upper(a[r],val,type)?r:cmp_upper(a[l],val,type)?l:-1

#define count(a,l,r,x) (l=lower_bound(a,l,r,x,1),r=upper_bound(a,l,r,x,1),r-l+1)

#define factor_pre() (is_factor_prepared++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define factor(n,new_common_plus) (is_factor_prepared++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define judge_prime(n) (is_factor_prepared++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define makeinv(n,mod) (is_minv_made++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define make_mf(n,mod) (is_mf_made++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define m_inv(x,mod,is_fac) (is_minv_made++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define m_f(x,mod) (is_mf_made++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define mod_nck(n,k,mod) (is_mf_made++)?0:((1e6)/2+1,fac_tmp=malloc(sizeof(ll)*(1e6)/2+1),rep(i,0,(1e6)/2+1)fac_tmp[i]=i?2*i+1:2,rep(i,1,(1e6)/2+1){if(fac_tmp[i]){repp(j,3,(1e6)/(2*i+1)+1,2){if(j*(2*i+1)<(1e6))fac_tmp[(j*(2*i+1)-1)/2]=0;}}else continue;}rep(i,0,(1e6)/2+1){if(fac_tmp[i]){rep(j,0,2){factors[j]=realloc(factors[j],sizeof(ll)*(fac_cnt+1));factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];}}else continue;}return 0;

#define m_p(r,n,mod) (1,m_p(r,n,mod))

#define m_mul2(a,b,mod) a*b%mod
#define m_mul3(a,b,c,mod) m_mul2(a*b%mod,c,mod)
#define m_mul4(a,b,c,d,mod) m_mul3(a*b%mod,c,d,mod)
#define m_mul5(a,b,c,d,e,mod) m_mul4(a*b%mod,c,d,e,mod)

#define upll(a,b) *(ll *)a<*(ll *)b?-1:*(ll *)a>(ll *)b?1:0
#define downll(a,b) *(ll *)a<*(ll *)b?1:*(ll *)a>(ll *)b?-1:0
#define cmp_string(a,b) strcmp((char *)a,(char *)b)
#define cmp_char(a,b) *(char *)a-*(char *)b

#define sortup(a,n) qsort(a,n,sizeof(ll),upll)
#define sortdown(a,n) qsort(a,n,sizeof(ll),downll)
#define sort_string(n,size,s) qsort((void *)s,n,sizeof(s[0]),cmp_string)
#define sort_char(s) qsort((void *)s,strlen(s),sizeof(char),cmp_char)

#define unique