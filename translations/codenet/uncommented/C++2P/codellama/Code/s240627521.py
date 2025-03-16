#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

def main():
  N = int(input())
  A = [0] * N
  for i in range(N):
    A[i] = int(input())
  A.sort(reverse=True)
  index = 0
  max = inf
  for i in range(1, N):
    if max > abs(A[0] - 2 * A[i]):
      max = abs(A[0] - 2 * A[i])
      index = i
  print(A[0], A[index])


