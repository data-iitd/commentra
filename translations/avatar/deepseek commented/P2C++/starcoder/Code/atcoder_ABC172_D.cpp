
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <cassert>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <array>
#include <tuple>
#include <iterator>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <memory>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>
#include <cassert>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define set0(ar) memset(ar, 0, sizeof(ar))
#define set1(ar) memset(ar, 1, sizeof(ar))
#define setc(ar, val) memset(ar, val, sizeof(ar))
#define seta(ar, val) memset(ar, val, sizeof(ar) / sizeof(ar[0]))
#define max(a, b) ((a) > (b)? (a) : (b))
#define min(a, b) ((a) < (b)? (a) : (b))
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define I64d(x) scanf("%I64d",&x)
#define I64o(x) printf("%I64d\n",x)
#define I64d2(x, y) scanf("%I64d%I64d",&x,&y)
#define I64o2(x, y) printf("%I64d %I64d\n",x,y)
#define I64d3(x, y, z) scanf("%I64d%I64d%I64d",&x,&y,&z)
#define I64o3(x, y, z) printf("%I64d %I64d %I64d\n",x,y,z)
#define I64d4(w, x, y, z) scanf("%I64d%I64d%I64d%I64d",&w,&x,&y,&z)
#define I64o4(w, x, y, z) printf("%I64d %I64d %I64d %I64d\n",w,x,y,z)
#define I64d5(v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d",&v,&w,&x,&y,&z)
#define I64o5(v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d\n",v,w,x,y,z)
#define I64d6(u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&u,&v,&w,&x,&y,&z)
#define I64o6(u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",u,v,w,x,y,z)
#define I64d7(t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&t,&u,&v,&w,&x,&y,&z)
#define I64o7(t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",t,u,v,w,x,y,z)
#define I64d8(s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o8(s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",s,t,u,v,w,x,y,z)
#define I64d9(r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o9(r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",r,s,t,u,v,w,x,y,z)
#define I64d10(q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o10(q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",q,r,s,t,u,v,w,x,y,z)
#define I64d11(p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o11(p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",p,q,r,s,t,u,v,w,x,y,z)
#define I64d12(o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o12(o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d13(n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o13(n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d14(m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o14(m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d15(l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o15(l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d16(k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o16(k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d17(j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o17(j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d18(i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o18(i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d19(h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o19(h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d20(g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o20(g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d21(f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o21(f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d22(e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o22(e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d23(d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o23(d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#define I64d24(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z)
#define I64o24(c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %