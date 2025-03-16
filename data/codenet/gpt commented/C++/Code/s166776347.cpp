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

// Define types and macros for convenience
typedef long long ll; // Define ll as a long long type
typedef pair<ll,ll> P; // Define P as a pair of long long integers
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++) // Macro for a loop from 0 to n
#define pb push_back // Macro to push back an element in a vector
#define INF (ll)1e18 // Define INF as a large number

ll mod = 1e9+7; // Define a modulus value for calculations
  
int main() {
	// Input: Read the values of N and K
	ll N,K;cin>>N>>K; // N is the size of the array, K is a parameter
	ll A[N];REP(i,N)cin>>A[i]; // Read N elements into array A

	// Solution: Calculate the number of inversions in the array
    ll ans1 = 0; // Initialize the count of inversions
	REP(i,N){ // Iterate through each element
        REP(j,N){ // Compare with every other element
            if (i>=j) continue; // Skip if i is greater than or equal to j
            if (A[i]>A[j]) ans1++; // Count inversion if A[i] > A[j]
            ans1 %= mod; // Take modulo to prevent overflow
        }
    }
    
    // Count occurrences of each element in the array
    ll count[2005] = {0}; // Initialize a count array to store frequencies
    REP(i,N){ // Iterate through the array
        count[A[i]-1]++; // Increment the count for the corresponding value
    }

    // Calculate the second part of the answer based on the counts
    ll ans2 = 0; // Initialize the second answer
    ll remain = N; // Remaining elements to consider
    REP(i,2005){ // Iterate through the count array
        remain -= count[i]; // Decrease the remaining count by the current count
        ans2 += count[i]*remain; // Calculate pairs of inversions
    }

    // Calculate the final answer based on ans1 and ans2
    ll ans = 0; // Initialize the final answer
    ll tmp = K*(K-1); // Calculate the number of ways to choose 2 from K
    tmp /= 2; // Divide by 2 to get combinations
    tmp %= mod; // Take modulo
    tmp *= ans2; // Multiply by the second answer
    tmp %= mod; // Take modulo again
    ans += ans1 * K; // Add the contribution from ans1
    ans %= mod; // Take modulo
    ans += tmp; // Add the contribution from tmp
    ans %= mod; // Take modulo

	// Output: Print the final answer
	cout << ans << endl; // Output the result
}
