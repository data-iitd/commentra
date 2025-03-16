package main

import (
	"fmt"
)

const mod = 1e9 + 7

func main() {
	var N, K int64
	fmt.Scan(&N, &K)
	A := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Solution
	ans1 := int64(0)
	for i := int64(0); i < N; i++ {
		for j := int64(0); j < N; j++ {
			if i >= j {
				continue // Skip if i is not less than j
			}
			if A[i] > A[j] {
				ans1++ // Increment ans1 if A[i] > A[j]
			}
			ans1 %= mod // Take modulo to prevent overflow
		}
	}

	// Count the frequency of each element in the array A
	count := make([]int64, 2005)
	for i := int64(0); i < N; i++ {
		count[A[i]-1]++ // Store frequency of A[i]
	}

	ans2 := int64(0)
	remain := N
	for i := int64(0); i < 2005; i++ {
		remain -= count[i] // Reduce the remaining count
		ans2 += count[i] * remain // Calculate the number of valid pairs
	}

	// Calculate the final answer
	tmp := K * (K - 1) / 2 // Calculate K*(K-1)/2
	tmp %= mod // Take modulo to prevent overflow
	tmp *= ans2 // Multiply with ans2
	tmp %= mod // Take modulo to prevent overflow
	ans := int64(0)
	ans += ans1 * K // Add contribution from ans1
	ans %= mod // Take modulo to prevent overflow
	ans += tmp // Add contribution from tmp
	ans %= mod // Take modulo to prevent overflow

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
