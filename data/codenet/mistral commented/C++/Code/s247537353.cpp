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

// Chmin and chmax are helper functions to update a variable with the minimum or maximum of it and another value, respectively.
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { // if the current value is greater than the new value
    a = b; // update the current value with the new value
    return true; // return true to indicate an update occurred
  }
  return false; // otherwise, return false
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { // if the current value is less than the new value
    a = b; // update the current value with the new value
    return true; // return true to indicate an update occurred
  }
  return false; // otherwise, return false
}

const int INF = (1 << 30) - 1; // constant definition for a large integer value
const ll INFLL= (1LL << 61) - 1; // constant definition for a large long long integer value
const int MOD = 1000000007; // constant definition for the modulus value
#define ALL(a) (a).begin(),(a).end() // macro definition for getting the iterator range of a container
#define rALL(a) (a).rbegin(),(a).rend() // macro definition for getting the reverse iterator range of a container
#define FOR(i,a,b) for(int i=(a);i<(b);++i) // for loop definition with initialization, condition, and increment
#define REP(i,n) FOR(i,0,n) // repetition loop definition with loop variable and loop count

int main(){
  cin.tie(nullptr); // set cin to unbuffered mode
  ios::sync_with_stdio(false); // disable automatic flushing of cout

  // Read input values from the standard input
  cin>>A>>B>>C>>K;

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // If true, print the minimum value between A and K
    cout<<min(A,K)<<endl;
  }else{
    // If false, calculate the difference between K and the sum of A and B,
    // and subtract it from A to get the required value
    cout<<A-(K-(A+B))<<endl;
  }
}