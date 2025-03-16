
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 100000007
#define MOD998 99824435
#define sp <<" "<<
#define el <<endl
#define c(n) printf("%d\n", n);
#define c2(n, m) printf("%d %d\n", n, m);
#define c3(n, m, k) printf("%d %d %d\n", n, m, k);
#define s(n) scanf("%d", &n);
#define s2(n, m) scanf("%d%d", &n, &m);
#define s3(n, m, k) scanf("%d%d%d", &n, &m, &k);
#define sll(n) scanf("%lld", &n);
#define sll2(n, m) scanf("%lld%lld", &n, &m);
#define sll3(n, m, k) scanf("%lld%lld%lld", &n, &m, &k);
#define sld(n) scanf("%Lf", &n);
#define sld2(n, m) scanf("%Lf%Lf", &n, &m);
#define sld3(n, m, k) scanf("%Lf%Lf%Lf", &n, &m, &k);
#define scl(n) scanf("%Lf", &n);
#define scl2(n, m) scanf("%Lf%Lf", &n, &m);
#define scl3(n, m, k) scanf("%Lf%Lf%Lf", &n, &m, &k);
#define scs(s) scanf("%s", s);
#define p(n) printf("%d", n);
#define p2(n, m) printf("%d %d", n, m);
#define p3(n, m, k) printf("%d %d %d", n, m, k);
#define pl(n) printf("%lld", n);
#define pl2(n, m) printf("%lld %lld", n, m);
#define pl3(n, m, k) printf("%lld %lld %lld", n, m, k);
#define pld(n) printf("%Lf", n);
#define pld2(n, m) printf("%Lf %Lf", n, m);
#define pld3(n, m, k) printf("%Lf %Lf %Lf", n, m, k);
#define pcl(n) printf("%Lf", n);
#define pcl2(n, m) printf("%Lf %Lf", n, m);
#define pcl3(n, m, k) printf("%Lf %Lf %Lf", n, m, k);
#define pcs(s) printf("%s", s);
#define println puts("")
#define print(x) cout << x << endl;
#define read(x) cin >> x;
#define For(i, n) for(int i = 0; i < (n); i++)
#define rFor(i, n) for(int i = (n)-1; i >= 0; i--)
#define Forr(i, n) for(int i = (n)-1; i >= 0; i--)
#define Forv(i, v) for(auto i : v)
#define Forvr(i, v) for(auto i = v.rbegin(); i!= v.rend(); i++)
#define Forvrev(i, v) for(auto i = v.rend(); i!= v.rbegin(); i++)
#define Forc(i, c) for(auto i : c)
#define Forcr(i, c) for(auto i = c.rbegin(); i!= c.rend(); i++)
#define Forcrev(i, c) for(auto i = c.rend(); i!= c.rbegin(); i++)
#define Foracon(i, a) for(auto i : a)
#define Foraconr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconv(i, a) for(auto i : a)
#define Foraconvr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconvrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconc(i, a) for(auto i : a)
#define Foraconcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvc(i, a) for(auto i : a)
#define Foraconcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvvc(i, a) for(auto i : a)
#define Foraconcvvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcrev(i, a) for(auto i = a.rend(); i!= a.rbegin(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvc(i, a) for(auto i : a)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcvcr(i, a) for(auto i = a.rbegin(); i!= a.rend(); i++)
#define Foraconcvcvcv