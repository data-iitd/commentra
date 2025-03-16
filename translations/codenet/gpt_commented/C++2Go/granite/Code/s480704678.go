
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define long long type alias for convenience
type lint = int64

// Constants for large values and mathematical constants
const (
	INF  = 1001001001001001
	MOD  = 100000007
	PI   = 3.1415926535897932
)

func main() {
	// Initialize the input reader
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	// Initialize a slice to store the input values and a slice for prefix sums
	a := make([]lint, n)
	acc := make([]lint, n+1)

	// Read input values and compute prefix sums modulo MOD
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		acc[i+1] = acc[i] + a[i] // Update prefix sum
		acc[i+1] %= MOD // Ensure the prefix sum is within MOD
	}

	// Initialize the answer variable
	ans := lint(0)

	// Calculate the final answer using the prefix sums
	for i := 0; i < n; i++ {
		ans += a[i] % MOD * (MOD + acc[n]-acc[i+1]) % MOD // Update answer based on current element and remaining sum
		ans %= MOD // Ensure the answer is within MOD
	}

	// Output the final result
	fmt.Println(ans)
}

