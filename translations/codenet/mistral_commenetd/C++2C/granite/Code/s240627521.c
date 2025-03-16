

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)

void File() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}

const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int base = 131;
const double pi = acos(-1.0);
int n, m, k, t;
int a[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, greater<int>());
  int ans = inf, id;
  for(int i = 2; i <= n; i++) {
    if(ans > abs(a[1] - 2 * a[i])) {
      ans = abs(a[1] - 2 * a[i]);
      id = i;
    }
  }
  printf("%d %d\n", a[1], a[id]);
  return 0;
}
