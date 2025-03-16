#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

#define gcd(a,b) (b==0?a:gcd(b,a%b))
#define lcm(a,b) (a/gcd(a,b)*b)

#define h 19
#define w 15

#define dx [8] = {0,1,0,-1,1,1,-1,-1}
#define dy [8] = {1,0,-1,0,1,-1,1,-1}

#define s [19]

#define ans INF

#define dfs(x,y,cnt) \
    if(cnt > 20)return; \
    if(x == h-1){ \
        ans = min(ans,cnt); \
        return; \
    } \
    rep(i,8){ \
        int nx = x + dx[i]; \
        int ny = y + dy[i]; \
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue; \
        if(s[nx][ny] != 'X')continue; \
        bool c = true; \
        while(c && s[nx][ny] == 'X'){ \
            s[nx][ny] = '.'; \
            nx += dx[i]; \
            ny += dy[i]; \
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){ \
                if(nx >= h)ans = min(ans, cnt+1); \
                c = false; \
            } \
        } \
        if(c)dfs(nx,ny,cnt+1); \
        while(nx != x || ny != y){ \
            nx -= dx[i]; \
            ny -= dy[i]; \
            s[nx][ny] = 'X'; \
        } \
        s[x][y] = '.'; \
    }

#define main() \
    rep(i,h)cin >> s[i]; \
    int sx,sy; \
    rep(i,h)rep(j,w)if(s[i][j] == 'O'){ \
        sx = i, sy = j; \
        s[i][j] = '.'; \
    } \
    dfs(sx,sy,0); \
    if(ans == INF)cout << -1 << endl; \
    else cout << ans << endl;

#define END-OF-CODE

