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
	// Read the number of elements in the array 'a'
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'a' of size 'n'
	a := make([]int64, n)

	// Initialize a slice 'acc' of size 'n+1' with zero as initial value
	acc := make([]int64, n+1)

	// Read the elements of the array 'a' and calculate the cumulative sum
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])

		// Update the cumulative sum 'acc' for the current index 'i+1'
		acc[i+1] = (acc[i] + a[i]) % MOD
	}

	// Initialize the answer 'ans' to zero
	var ans int64 = 0

	// Calculate the answer using the formula
	for i := 0; i < n; i++ {
		// Calculate the contribution of the current element 'a[i]' to the answer
		temp := (a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD) % MOD

		// Add the contribution to the answer
		ans = (ans + temp) % MOD
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
