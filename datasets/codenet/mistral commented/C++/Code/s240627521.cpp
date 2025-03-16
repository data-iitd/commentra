
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
#define rep(i, n) for(int i=0;i<n;++i) // Iterate through a range [0, n)
#define rrep(i, n) for(int i=n;i>=0;--i) // Iterate through a range [n, 0]
const int inf=1e9+7; // Large constant value used as an infinite value
const ll mod=1e9+7; // Constant value representing the modulus
const ll mod1=998244353; // Another constant value representing the modulus
const ll big=1e18; // Large constant value used to represent a big number
const double PI=2*asin(1); // Constant value representing the mathematical constant pi

int main() {
  int N; // Variable to store the number of elements in the vector
  cin>>N; // Read the number of elements from the standard input
  vector<ll> A(N); // Declare and initialize a vector A of size N with default-constructed elements
  for(int i=0;i<N;++i) { // Iterate through the range [0, N) and read each element into the vector
    cin>>A[i];
  }
  sort(A.begin(), A.end(), greater<ll>()); // Sort the vector A in descending order
  int index; // Variable to store the index of the second smallest element
  ll max = inf; // Initialize the maximum difference to an infinite value
  for(int i=1;i<N;++i) { // Iterate through the range [1, N)
    if(max>abs(A[0]-2*A[i])) { // Check if the current difference is greater than the maximum difference
      max = abs(A[0]-2*A[i]); // Update the maximum difference if it is
      index = i; // Update the index of the second smallest element
    }
  }
  cout<<A[0]<<" "<<A[index]<<endl; // Output the smallest and second smallest elements
}

