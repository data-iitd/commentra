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

// Function to compute the greatest common divisor (GCD) of two numbers
ll gcd(ll x, ll y) {
  ll tmp = 0;
  // Ensure x is greater than or equal to y
  if (x < y){
    tmp = x;
    x = y;
    y = tmp;
  }
  // Apply the Euclidean algorithm to find GCD
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x; // Return the GCD
}

// Function to compute the least common multiple (LCM) of two numbers
ll lcm(ll x, ll y){
  return x / gcd(x, y) * y; // LCM formula using GCD
}

// Function to compute the factorial of a number modulo 1,000,000,007
ll kaijo(ll k){
    ll sum = 1;
    // Calculate factorial iteratively
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i; // Multiply current sum by i
        sum %= 1000000000 + 7; // Take modulo to prevent overflow
    }
    return sum; // Return the factorial
}

// Function to return the maximum of two numbers
ll lmax(ll s, ll t){
  if(s > t){
    return s; // Return s if it is greater
  }
  else{
    return t; // Otherwise return t
  }
}

// Function to return the minimum of two numbers
ll lmin(ll s, ll t){
  if(s < t){
    return s; // Return s if it is smaller
  }
  else{
    return t; // Otherwise return t
  }
}

// Main function to execute the program
int main(){
  int n, k;
  // Input the values of n and k
  cin >> n >> k;
  ll sum = 0; // Initialize sum to zero

  // Loop through each integer b from 1 to n
  for(int b = 1; b <= n; b++){
    // Calculate the count of multiples of b in the range [1, n]
    int cnt = (n + 1) / b;
    // Calculate the remainder when n + 1 is divided by b
    int md = (n + 1) % b;
    // Update the sum based on the count and the maximum values
    sum += cnt * max((b - k), 0) + max((md - k), 0);
    // Adjust the sum if k is zero
    if(k == 0) sum--;
  }
  
  // Output the final computed sum
  cout << sum << endl;
  return 0; // End of the program
}
