
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <utility>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <valarray>
#include <complex>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)

const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> m(N+1);
  REP(i,N) {
    cin >> m[i] >> m[i+1];
  }
  VVI dp(N+1,VI(N+1));
  REP(l,N) {
    REP(i,N-l) {
      int j = i + l;
      for (int k = i; k < j; ++k) {
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + m[i]*m[k+1]*m[j+1]);
      }
    }
  }
  cout << dp[0][N] << endl;
}

