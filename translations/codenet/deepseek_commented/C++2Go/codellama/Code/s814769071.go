// Step 1: Import packages
package main

import (
	"fmt"
	"math"
)

// Step 2: Define constants
const (
	MOD = 1e9 + 7
)

// Step 3: Define variables
var (
	n, k int
	mx   int
	mn   int
	res  int
)

// Step 4: Read input values
func main() {
	fmt.Scan(&n, &k)

	// Step 5: Calculate the maximum and minimum sums
	mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2
	mn = k * (k - 1) / 2

	// Step 6: Initialize variables
	res = 0

	// Step 7: Loop through possible lengths
	for i := k; i <= n+1; i++ {
		// Update res, mx, and mn in each iteration
		res += mx - mn + 1
		mx += n - i
		mn += i
		res %= MOD
	}

	// Step 8: Output the result
	fmt.Println(res)
}

