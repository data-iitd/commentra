package main

import (
	"fmt"
)

const (
	INF  = 1001001001001001
	inf  = 1000000007
	MOD  = 1000000007
	PI   = 3.1415926535897932
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input values and a slice for prefix sums
	a := make([]int64, n)
	acc := make([]int64, n+1)

	// Read input values and compute prefix sums modulo MOD
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = (acc[i] + a[i]) % MOD // Update prefix sum
	}

	// Initialize the answer variable
	var ans int64 = 0

	// Calculate the final answer using the prefix sums
	for i := 0; i < n; i++ {
		ans = (ans + (a[i]%MOD)*(MOD+acc[n]-acc[i+1])%MOD) % MOD) % MOD // Update answer based on current element and remaining sum
	}

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
