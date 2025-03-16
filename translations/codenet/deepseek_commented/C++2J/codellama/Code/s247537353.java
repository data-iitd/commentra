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

// Function to check and update the minimum value of a variable
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

// Function to check and update the maximum value of a variable
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

// Define constants for maximum values
const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;

// Macro to iterate over all elements in a container
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  // Fast I/O setup
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Declare variables to store input values
  long A,B,C,K;
  cin>>A>>B>>C>>K;

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // Output the minimum of A and K
    System.out.println(Math.min(A,K));
  }else{
    // Calculate the result by subtracting the excess amount from A
    System.out.println(A-(K-(A+B)));
  }
}

