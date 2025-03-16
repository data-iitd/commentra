
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <numeric>
#include <sstream>
#include <complex>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

struct UnionFind {
  vector<int> par;
  vector<int> rank;
  UnionFind(int n) : par(n), rank(n) {
    REP(i,n) par[i] = i;
    REP(i,n) rank[i] = 0;
  }
  int find(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  REP(i,m) {
    int x,y,z;
    cin >> x >> y >> z;
    uf.unite(x-1,y-1);
  }
  int ans = 0;
  REP(i,n) {
    if (uf.find(i) == i) ans++;
  }
  cout << ans << endl;
  return 0;
}
// END-OF-CODE