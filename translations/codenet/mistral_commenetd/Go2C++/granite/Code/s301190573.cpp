

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <stack>
#include <queue>
#include <ctime>
#include <complex>
#include <sstream>
#include <iomanip>
#include <assert.h>
#include <array>
#include <random>
#include <valarray>

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<class T> using vT = vector<T>;
template<class T> using vvT = vector<vector<T>>;
template<class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPN(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP_D(i, n) for(int i = (n)-1; i >= 0; i--)
#define REPN_D(i, m, n) for(int i = (n)-1; i >= (m); i--)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()
#define EXIST(s, e) ((s).find(e)!= (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(ALL(c), greater<typeof(*c.begin())>())
#define SQ(n) ((n) * (n))

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (b)-1; i >= (a); i--)

#define DUMP(x) cout << #x << " = " << (x) << endl
#define DUMP2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define DUMP3(x, y, z) cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl

#define YN(x) cout << ((x)?"YES":"NO") << endl
#define YN_c(x) cout << ((x)?"Yes":"No") << endl

#define MAX_N 1000000

int par[MAX_N];
int rank[MAX_N];

void init(int n){
  REP(i, n){
    par[i] = i;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vi p(n);
  REP(i, n) cin >> p[i], p[i]--;
  init(n);
  REP(i, m){
    int x, y;
    cin >> x >> y;
    unite(x-1, y-1);
  }
  int ans = 0;
  REP(i, n){
    if(same(i, p[i])) ans++;
  }
  cout << ans << endl;

  return 0;
}

