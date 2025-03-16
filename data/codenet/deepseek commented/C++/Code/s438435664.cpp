#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>

using namespace std;
typedef long long ll;

// 最小公倍数
// Computes the greatest common divisor of two numbers x and y
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

// 最大公倍数
// Computes the least common multiple of two numbers x and y
ll lcm(ll x, ll y) {
  return x / gcd(x, y) * y;
}

// 階乗
// Computes the factorial of a number k modulo 10^9 + 7
ll kaijo(ll k) {
  ll sum = 1;
  for (ll i = 1; i <= k; ++i) {
    sum *= i;
    sum %= 1000000000 + 7;
  }
  return sum;
}

// for(int i = ; i < ; i++){}

// Utility functions to find the maximum and minimum of two numbers
ll lmax(ll s, ll t) {
  if (s > t) {
    return s;
  } else {
    return t;
  }
}

ll lmin(ll s, ll t) {
  if (s < t) {
    return s;
  } else {
    return t;
  }
}

// ここから開始

int main() {
  // Read two integers n and k
  int n, k;
  cin >> n >> k;
  ll sum = 0;

  // Iterate over possible values of b
  for (int b = 1; b <= n; b++) {
    // Calculate the count and remainder
    int cnt = (n + 1) / b;
    int md = (n + 1) % b;

    // Update the sum based on the conditions involving k
    sum += cnt * max((b - k), 0) + max((md - k), 0);

    // Adjust the sum if k is 0
    if (k == 0) sum--;
  }

  // Print the computed sum
  cout << sum << endl;
  return 0;
}
