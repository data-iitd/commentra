
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <vector> 
#include <map> 
#include <set> 
#include <bitset> 
#include <queue> 
#include <stack> 
#include <string> 
#include <cctype> 
#include <fstream> 
#include <iomanip> 
#include <sstream> 
#include <cassert> 
using namespace std; 

#define INF 1000000000 
#define MOD 1000000007 
#define MAX 1000000000 
#define LN 1000000000 
#define EPS 1e-9 
#define PI acos(-1.0) 
#define LL long long 
#define ULL unsigned long long 
#define PB push_back 
#define MP make_pair 
#define F first 
#define S second 
#define PI 3.1415926535897932384626433832795 
#define MOD 1000000007 
#define N 1000000000 
#define eps 1e-9 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define endl "\n" 
#define input(n) int n;cin>>n; 
#define input2(n,m) int n,m;cin>>n>>m; 
#define input3(n,m,k) int n,m,k;cin>>n>>m>>k; 
#define input4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d; 
#define input5(a,b,c,d,e) int a,b,c,d,e;cin>>a>>b>>c>>d>>e; 
#define input6(a,b,c,d,e,f) int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f; 
#define input7(a,b,c,d,e,f,g) int a,b,c,d,e,f,g;cin>>a>>b>>c>>d>>e>>f>>g; 
#define input8(a,b,c,d,e,f,g,h) int a,b,c,d,e,f,g,h;cin>>a>>b>>c>>d>>e>>f>>g>>h; 
#define input9(a,b,c,d,e,f,g,h,i) int a,b,c,d,e,f,g,h,i;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i; 
#define input10(a,b,c,d,e,f,g,h,i,j) int a,b,c,d,e,f,g,h,i,j;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j; 
#define input11(a,b,c,d,e,f,g,h,i,j,k) int a,b,c,d,e,f,g,h,i,j,k;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k; 
#define input12(a,b,c,d,e,f,g,h,i,j,k,l) int a,b,c,d,e,f,g,h,i,j,k,l;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l; 
#define input13(a,b,c,d,e,f,g,h,i,j,k,l,m) int a,b,c,d,e,f,g,h,i,j,k,l,m;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m; 
#define input14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) int a,b,c,d,e,f,g,h,i,j,k,l,m,n;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n; 
#define input15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o; 
#define input16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p; 
#define input17(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q; 
#define input18(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r; 
#define input19(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s; 
#define input20(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t; 
#define input21(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u; 
#define input22(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v; 
#define input23(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w; 
#define input24(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x; 
#define input25(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y; 
#define input26(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z; 
#define input27(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa; 
#define input28(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb; 
#define input29(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc; 
#define input30(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd; 
#define input31(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee; 
#define input32(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff; 
#define input33(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg; 
#define input34(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh; 
#define input35(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii; 
#define input36(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj; 
#define input37(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk; 
#define input38(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll; 
#define input39(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm; 
#define input40(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm>>nn; 
#define input41(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm>>nn>>oo; 
#define input42(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm>>nn>>oo>>pp; 
#define input43(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm>>nn>>oo>>pp>>qq; 
#define input44(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh>>ii>>jj>>kk>>ll>>mm>>nn>>oo>>pp>>qq>>rr; 
#define input45(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr,ss) int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr,ss;cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w>>x>>y>>z>>aa>>bb>>cc>>dd>>ee>>ff>>gg>>hh