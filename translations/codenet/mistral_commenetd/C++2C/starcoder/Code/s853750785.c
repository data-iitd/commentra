#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define MOD 1000000007
#define INF 1000000000000000000
#define eps 1e-9
#define pi acos(-1)
#define rad_to_deg(rad) (((rad)/2/pi)*360)
#define deg_to_rad(deg) (((deg)/360)*2*pi)
#define show(s) printf("%s\n",s)
#define show1(s) printf("%d\n",s)
#define show2(s) printf("%d %d\n",s,s)
#define show3(s) printf("%d %d %d\n",s,s,s)
#define show4(s) printf("%d %d %d %d\n",s,s,s,s)
#define show5(s) printf("%d %d %d %d %d\n",s,s,s,s,s)
#define show6(s) printf("%d %d %d %d %d %d\n",s,s,s,s,s,s)
#define show7(s) printf("%d %d %d %d %d %d %d\n",s,s,s,s,s,s,s)
#define show8(s) printf("%d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s)
#define show9(s) printf("%d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s)
#define show10(s) printf("%d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s)
#define show11(s) printf("%d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s)
#define show12(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s)
#define show13(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show14(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show15(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show16(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show17(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show18(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show19(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show20(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show21(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show22(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show23(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show24(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show25(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show26(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show27(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show28(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show29(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show30(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show31(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show32(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show33(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show34(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show35(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show36(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show37(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show38(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show39(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show40(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show41(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show42(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show43(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show44(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show45(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show46(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show47(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show48(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show49(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show50(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show51(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show52(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s)
#define show53(s) printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %