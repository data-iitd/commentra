
package main

import (
	"fmt"
)

// Define long long type alias for convenience
type lint int64

// Constants for large values and mathematical constants
const INF = 1001001001001001
var inf = 1000000007
var MOD = 1000000007
var PI = 3.1415926535897932

// Function to update the minimum value
func chmin(a *lint, b lint) {
	if *a > b {
		*a = b
	}
}

// Function to update the maximum value
func chmax(a *lint, b lint) {
	if *a < b {
		*a = b
	}
}

// Macros for convenience in iterating through containers
func ALL(a []lint) []lint {
	return a[:len(a)]
}

func RALL(a []lint) []lint {
	return a[len(a)-1:]
}

/* do your best */

func main() {

	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a vector to store the input values and a vector for prefix sums
	a := make([]lint, n)
	acc := make([]lint, n+1)

	// Read input values and compute prefix sums modulo MOD
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		acc[i+1] = acc[i] + a[i] // Update prefix sum
		acc[i+1] %= MOD          // Ensure the prefix sum is within MOD
	}

	// Initialize the answer variable
	var ans lint

	// Calculate the final answer using the prefix sums
	for i := 0; i < n; i++ {
		ans += a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD // Update answer based on current element and remaining sum
		ans %= MOD                                          // Ensure the answer is within MOD
	}

	// Output the final result
	fmt.Println(ans)

}

