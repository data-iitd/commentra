package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	const MOD = 1000000007
	result := int64(0)

	// Iterate over each bit position from 0 to 59
	for b := 0; b < 60; b++ {
		bs := int64(0)

		// Count how many numbers have the b-th bit set (1)
		for _, num := range A {
			if (num>>b)&1 == 1 {
				bs++
			}
		}

		// Calculate the contribution of the b-th bit to the result
		result = (result + bs*(int64(N)-bs)*(1<<b)) % MOD
	}

	// Print the final result
	fmt.Println(result)
}

// <END-OF-CODE>
