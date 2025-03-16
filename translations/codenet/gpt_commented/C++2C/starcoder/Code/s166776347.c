#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007

int main() {
	// Input: Read the values of N and K
	int N,K;scanf("%d%d",&N,&K); // N is the size of the array, K is a parameter
	int A[N];REP(i,N)scanf("%d",&A[i]); // Read N elements into array A

	// Solution: Calculate the number of inversions in the array
    int ans1 = 0; // Initialize the count of inversions
	REP(i,N){ // Iterate through each element
        REP(j,N){ // Compare with every other element
            if (i>=j) continue; // Skip if i is greater than or equal to j
            if (A[i]>A[j]) ans1++; // Count inversion if A[i] > A[j]
            ans1 %= MOD; // Take modulo to prevent overflow
        }
    }
    
    // Count occurrences of each element in the array
    int count[2005] = {0}; // Initialize a count array to store frequencies
    REP(i,N){ // Iterate through the array
        count[A[i]-1]++; // Increment the count for the corresponding value
    }

    // Calculate the second part of the answer based on the counts
    int ans2 = 0; // Initialize the second answer
    int remain = N; // Remaining elements to consider
    REP(i,2005){ // Iterate through the count array
        remain -= count[i]; // Decrease the remaining count by the current count
        ans2 += count[i]*remain; // Calculate pairs of inversions
    }

    // Calculate the final answer based on ans1 and ans2
    int ans = 0; // Initialize the final answer
    int tmp = K*(K-1); // Calculate the number of ways to choose 2 from K
    tmp /= 2; // Divide by 2 to get combinations
    tmp %= MOD; // Take modulo
    tmp *= ans2; // Multiply by the second answer
    tmp %= MOD; // Take modulo again
    ans += ans1 * K; // Add the contribution from ans1
    ans %= MOD; // Take modulo
    ans += tmp; // Add the contribution from tmp
    ans %= MOD; // Take modulo

	// Output: Print the final answer
	printf("%d\n",ans); // Output the result
}

