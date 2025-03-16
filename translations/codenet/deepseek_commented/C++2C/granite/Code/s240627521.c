
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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

int main() {
  int N;
  scanf("%d", &N); // Read the number of elements in the array A
  ll A[N];
  for(int i=0;i<N;++i) scanf("%lld", &A[i]); // Read the elements of the array A
  sort(A, A+N, greater<ll>()); // Sort the array A in descending order
  int index;
  ll max = inf; // Initialize max with a large value
  for(int i=1;i<N;++i) { // Iterate through the array to find the optimal pair
    if(max>abs(A[0]-2*A[i])) { // Check if the current difference is smaller than the previous minimum
      max = abs(A[0]-2*A[i]); // Update the minimum difference
      index = i; // Store the index of the current element
    }
  }
  printf("%lld %lld\n", A[0], A[index]); // Output the first and the found optimal pair
  return 0;
}


