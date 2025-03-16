
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

// Templates for min and max
template<typename T1,typename T2>
inline void chmin(T1 &a,const T2 &b){
  if(a > b) a = b; // Set 'a' to the minimum of 'a' and 'b'
}

template<typename T1,typename T2>
inline void chmax(T1 &a,const T2 &b){
  if(a < b) a = b; // Set 'a' to the maximum of 'a' and 'b'
}

// Define the alias for 'all' elements in a container
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/*
 * Main function starts here
 */
int main() {
  // Read the number of elements in the array 'a'
  int n; cin >> n;

  // Initialize a vector 'a' of size 'n'
  vector<lint> a(n);

  // Initialize a vector 'acc' of size 'n+1' with zero as initial value
  vector<lint> acc(n + 1, 0);

  // Read the elements of the array 'a' and calculate the cumulative sum
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    // Update the cumulative sum 'acc' for the current index 'i+1'
    acc[i + 1] = acc[i] + a[i];

    // Perform modulo operation to keep the value within the range of 'MOD'
    acc[i + 1] %= MOD;
  }

  // Initialize the answer 'ans' to zero
  lint ans = 0;

  // Calculate the answer using the formula
  for (int i = 0; i < n; i++) {
    // Calculate the contribution of the current element 'a[i]' to the answer
    lint temp = a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;

    // Add the contribution to the answer
    ans += temp;

    // Perform modulo operation to keep the value within the range of 'MOD'
    ans %= MOD;
  }

  // Print the answer
  cout << ans << endl;

  // Terminate the program
  return 0;
}