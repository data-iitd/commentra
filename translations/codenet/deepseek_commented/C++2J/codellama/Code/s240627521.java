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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

public class Main {
  public static void main(String[] args) {
    int N;
    cin>>N; // Read the number of elements in the array A
    vector<ll> A(N);
    for(int i=0;i<N;++i) cin>>A[i]; // Read the elements of the array A
    sort(A.begin(), A.end(), greater<ll>()); // Sort the array A in descending order
    int index;
    ll max = inf; // Initialize max with a large value
    for(int i=1;i<N;++i) { // Iterate through the array to find the optimal pair
      if(max>abs(A[0]-2*A[i])) { // Check if the current difference is smaller than the previous minimum
        max = abs(A[0]-2*A[i]); // Update the minimum difference
        index = i; // Store the index of the current element
      }
    }
    cout<<A[0]<<" "<<A[index]<<endl; // Output the first and the found optimal pair
  }
}

