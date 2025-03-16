#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// Macro for for loop
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

ll mod = 1e9+7;

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// Macro for for loop
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

ll mod = 1e9+7;

// Main function
int main() {
    // Input
    ll N, K; // Number of elements in array A and the value of K
    cin >> N >> K;
    ll A[N]; // Array to store input elements
    REP(i,N) cin >> A[i]; // Read elements of array A from standard input

    // Solution
    ll ans1 = 0; // Initialize answer for the first part
    REP(i,N){ // Iterate through all elements in array A
        REP(j,N){ // Iterate through all other elements in array A
            if (i >= j) continue; // Skip if current index is greater than or equal to the index of the inner loop
            if (A[i] > A[j]) ans1++; // Increment answer if the current element is greater than the inner element
            ans1 %= mod; // Update answer modulo 1e9+7 to avoid overflow
        }
    }

    ll count[2005] = {0}; // Initialize an array to store the count of each unique element in array A
    REP(i,N){ // Iterate through all elements in array A
        count[A[i]-1]++; // Increment the count of the current element in the count array
    }

    ll ans2 = 0; // Initialize answer for the second part
    ll remain = N; // Initialize the remaining number of elements to be paired
    REP(i,2005){ // Iterate through all unique elements in array A
        remain -= count[i]; // Decrement the remaining number of elements to be paired for the current unique element
        ans2 += count[i]*remain; // Calculate the contribution of the current unique element to the answer
    }

    ll ans = 0; // Initialize the final answer
    ll tmp = K*(K-1); // Calculate (K*(K-1)) modulo 1e9+7
    tmp /= 2; // Divide by 2 to get the number of unique pairs that can be formed using K elements
    tmp %= mod; // Update the temporary variable modulo 1e9+7
    tmp *= ans2; // Multiply the temporary variable with the answer for the second part
    tmp %= mod; // Update the temporary variable modulo 1e9+7
    ans += ans1 * K; // Add the answer for the first part multiplied by K to the final answer
    ans %= mod; // Update the final answer modulo 1e9+7
    ans += tmp; // Add the temporary variable to the final answer
    ans %= mod; // Update the final answer modulo 1e9+7

    // Output
    cout << ans << endl; // Print the final answer
}

