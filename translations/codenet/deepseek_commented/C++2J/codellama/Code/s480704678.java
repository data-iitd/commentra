
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

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/*
 * Include Necessary Headers: The code starts by including various headers from the C++ standard library.
 * These headers provide essential functionalities for input/output operations, string manipulation,
 * mathematical operations, and more.
 */

/*
 * Define Constants and Aliases: The code defines constants and aliases for commonly used values such as
 * INF, inf, MOD, PI, and an alias lint for long long int. These definitions help in making the code more
 * readable and maintainable.
 */

/*
 * Template Functions for Min/Max: Two template functions chmin and chmax are defined to ensure that the
 * minimum and maximum values between two variables are correctly assigned.
 */

/*
 * Main Function:
 * - Input the Size of the Array: The size of the array n is read from the standard input.
 * - Initialize Arrays: Two vectors a and acc are initialized. a stores the elements of the array, and acc
 *   is used to store the cumulative sum of a, modulo MOD.
 * - Compute Cumulative Sum: A loop iterates over the elements of a, updating the cumulative sum acc and
 *   taking modulo MOD to prevent overflow.
 * - Compute the Answer: Another loop calculates the final answer based on the given formula, which involves
 *   the elements of a and the cumulative sum acc. The result is accumulated and taken modulo MOD to ensure
 *   it fits within the specified range.
 * - Output the Result: The final result is printed to the standard output.
 */

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] a = new long[n];
    long[] acc = new long[n + 1];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
      acc[i + 1] = acc[i] + a[i];
      acc[i + 1] %= MOD;
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;
      ans %= MOD;
    }
    System.out.println(ans);
  }
}

