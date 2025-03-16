#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define N 2005
#define mod 1000000007

int main() {
	// 入力
	int N,K;scanf("%d%d",&N,&K);
	int A[N];REP(i,N)scanf("%d",&A[i]);

	// 解法 
    int ans1 = 0;
	REP(i,N){
        REP(j,N){
            if (i>=j) continue; // Skip if i is not less than j
            if (A[i]>A[j]) ans1++; // Increment ans1 if A[i] > A[j]
            ans1 %= mod; // Take modulo to prevent overflow
        }
    }
    
    // Count the frequency of each element in the array A
    int count[2005] = {0};
    REP(i,N){
        count[A[i]-1]++; // Store frequency of A[i]
    }

    int ans2 = 0;
    int remain = N;
    REP(i,2005){
        remain -= count[i]; // Reduce the remaining count
        ans2 += count[i]*remain; // Calculate the number of valid pairs
    }

    // Calculate the final answer
    int tmp = K*(K-1);
    tmp /= 2; // Calculate K*(K-1)/2
    tmp %= mod; // Take modulo to prevent overflow
    tmp *= ans2; // Multiply with ans2
    tmp %= mod; // Take modulo to prevent overflow
    int ans = 0;
    ans += ans1 * K; // Add contribution from ans1
    ans %= mod; // Take modulo to prevent overflow
    ans += tmp; // Add contribution from tmp
    ans %= mod; // Take modulo to prevent overflow

    // Output the final answer
    printf("%d\n",ans);
}

