
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define int long long
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22
int N;
vector<P> G[100000];
int U[MAX_L][100000], R[100000];
long long L[100000];

void dfs(int x, int p, int r, long long l) {
  U[0][x] = p;
  R[x] = r;
  L[x] = l;
  for (P pp : G[x]) {
    int t = pp._1;
    if (t == p) continue;
    dfs(t, x, r+1, l+pp._2);
  }
}

int lca(int a, int b) {
  if (R[a] > R[b]) swap(a, b);
  for (int k=0; k<MAX_L; k++) {
    if ((R[a] - R[b]) >> k & 1) b = U[k][b];
  }
  if (a == b) return a;
  for (int k=MAX_L-1; k>=0; k--) {
    if (U[k][a]!= U[k][b]) {
      a = U[k][a];
      b = U[k][b];
    }
  }
  return U[0][a];
}
long long dist(int x, int y) {
  int g = lca(x, y);
  return L[x] + L[y] - 2LL*L[g];
}

int main() {
  int N;
  scanf("%lld", &N);
  rep(i, N-1) {
    int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    a--, b--;
    G[a].pb(P(b, c));
    G[b].pb(P(a, c));
  }
  rep(i, MAX_L) rep(j, N) U[i][j] = -1;
  dfs(0, -1, 0, 0);
  for (int i=0; i<MAX_L-1; i++) {
    for (int v=0; v<N; v++) {
      if (U[i][v] == -1) U[i+1][v] = -1;
      U[i+1][v] = U[i][U[i][v]];
    }
  }
  int Q, K;
  scanf("%lld %lld", &Q, &K);
  K--;
  rep(i, Q) {
    int x, y;
    scanf("%lld %lld", &x, &y);
    x--, y--;
    printf("%lld\n", dist(x, K) + dist(K, y));
  }
  return 0;
}
