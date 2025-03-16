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
typedef long long ll; // long long integer type definition

#define INF (1 << 30) - 1 // constant definition for a large integer value
#define INFLL (1LL << 61) - 1 // constant definition for a large long long integer value
#define MOD 1000000007 // constant definition for the modulus value
#define ALL(a) (a).begin(),(a).end() // macro definition for getting the iterator range of a container
#define rALL(a) (a).rbegin(),(a).rend() // macro definition for getting the reverse iterator range of a container
#define FOR(i,a,b) for(int i=(a);i<(b);++i) // for loop definition with initialization, condition, and increment
#define REP(i,n) FOR(i,0,n) // repetition loop definition with loop variable and loop count

def main():
  cin.tie(None) # set cin to unbuffered mode
  ios.sync_with_stdio(False) # disable automatic flushing of cout

  # Read input values from the standard input
  A, B, C, K = map(int, input().split())

  # Check if the sum of A and B is greater than or equal to K
  if A + B >= K:
    # If true, print the minimum value between A and K
    print(min(A, K))
  else:
    # If false, calculate the difference between K and the sum of A and B,
    # and subtract it from A to get the required value
    print(A - (K - (A + B)))

