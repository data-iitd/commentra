package main

import (
	"fmt"
)

func main() {
	// Step 2: Read input values
	var n, k int64
	fmt.Scan(&n, &k)
	const MOD = 1e9 + 7

	// Step 3: Calculate the maximum and minimum sums
	mx := n*(n+1)/2 - (n-k)*(n-k+1)/2
	mn := k * (k - 1) / 2

	// Step 4: Initialize variables
	res := int64(0)

	// Step 5: Loop through possible lengths
	for i := k; i <= n+1; i++ {
		// Update res, mx, and mn in each iteration
		res = (res + mx - mn + 1) % MOD
		mx += n - i
		mn += i
	}

	// Step 6: Output the result
	fmt.Println(res)
}

// <END-OF-CODE>
