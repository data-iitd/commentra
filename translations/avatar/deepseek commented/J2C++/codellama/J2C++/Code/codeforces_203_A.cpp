
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortall(x) sort(all(x))
#define endl "\n"
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MOD1 998244353
#define MOD2 1000000009
#define N 1000000000
#define eps 1e-9
#define inf 1e18
#define pi acos(-1.0)
#define ll long long
#define ull unsigned long long
#define lld long long double
#define ullll unsigned long long long
#define debug(x) cout<<#x<<" = "<<x<<endl
#define debug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define debug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define debugarray(arr,n) {rep(i,n) cout<<arr[i]<<" ";cout<<endl;}
#define debugarray2(arr,n,m) {rep(i,n) {rep(j,m) cout<<arr[i][j]<<" ";cout<<endl;}}
#define debugarray3(arr,n,m,l) {rep(i,n) {rep(j,m) {rep(k,l) cout<<arr[i][j][k]<<" ";cout<<endl;}}}
#define debugarray4(arr,n,m,l,p) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) cout<<arr[i][j][k][t]<<" ";cout<<endl;}}}}
#define debugarray5(arr,n,m,l,p,q) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) cout<<arr[i][j][k][t][s]<<" ";cout<<endl;}}}}}
#define debugarray6(arr,n,m,l,p,q,r) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) cout<<arr[i][j][k][t][s][v]<<" ";cout<<endl;}}}}}}
#define debugarray7(arr,n,m,l,p,q,r,w) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) cout<<arr[i][j][k][t][s][v][x]<<" ";cout<<endl;}}}}}}}
#define debugarray8(arr,n,m,l,p,q,r,w,e) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) cout<<arr[i][j][k][t][s][v][x][y]<<" ";cout<<endl;}}}}}}}}
#define debugarray9(arr,n,m,l,p,q,r,w,e,z) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) cout<<arr[i][j][k][t][s][v][x][y][u]<<" ";cout<<endl;}}}}}}}}}
#define debugarray10(arr,n,m,l,p,q,r,w,e,z,a) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) cout<<arr[i][j][k][t][s][v][x][y][u][o]<<" ";cout<<endl;}}}}}}}}}}
#define debugarray11(arr,n,m,l,p,q,r,w,e,z,a,b) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) cout<<arr[i][j][k][t][s][v][x][y][u][o][c]<<" ";cout<<endl;}}}}}}}}}}}
#define debugarray12(arr,n,m,l,p,q,r,w,e,z,a,b,c) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d]<<" ";cout<<endl;}}}}}}}}}}}}
#define debugarray13(arr,n,m,l,p,q,r,w,e,z,a,b,c,d) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f]<<" ";cout<<endl;}}}}}}}}}}}}}}
#define debugarray14(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g]<<" ";cout<<endl;}}}}}}}}}}}}}}}}
#define debugarray15(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}
#define debugarray16(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}
#define debugarray17(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}
#define debugarray18(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray19(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray20(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray21(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray22(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray23(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray24(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o,p) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) {rep(q,p) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p][q]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray25(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o,p,q,r) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) {rep(q,p) {rep(s,q) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p][q][r]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray26(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o,p,q,r,s) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) {rep(q,p) {rep(s,q) {rep(t,s) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p][q][r][t]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray27(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) {rep(q,p) {rep(s,q) {rep(t,s) {rep(u,t) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p][q][r][t][u]<<" ";cout<<endl;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define debugarray28(arr,n,m,l,p,q,r,w,e,z,a,b,c,d,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u) {rep(i,n) {rep(j,m) {rep(k,l) {rep(t,p) {rep(s,q) {rep(v,r) {rep(x,w) {rep(y,e) {rep(u,z) {rep(o,a) {rep(c,b) {rep(d,c) {rep(f,d) {rep(g,f) {rep(h,g) {rep(i,h) {rep(j,i) {rep(k,j) {rep(l,k) {rep(m,l) {rep(n,m) {rep(o,n) {rep(p,o) {rep(q,p) {rep(s,q) {rep(t,s) {rep(u,t) {rep(v,u) cout<<arr[i][j][k][t][s][v][x][y][u][o][c][d][f][g][h][i][j][k][l][m][n][o][p][q][r][t][u][v