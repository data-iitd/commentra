#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <random>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

#define chmin(a,b) if (a > b) {a = b;}
#define chmax(a,b) if (a < b) {a = b;}

const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;

int main(){
  // Fast I/O setup
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  # Declare variables to store input values
  ll A,B,C,K;
  cin>>A>>B>>C>>K;

  # Check if the sum of A and B is greater than or equal to K
  if(A+B>=K):
    # Output the minimum of A and K
    print(min(A,K))
  else:
    # Calculate the result by subtracting the excess amount from A
    print(A-(K-(A+B)))

# 