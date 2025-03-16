package main

import (
	"fmt"
)

const mod = 1e9 + 7

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	ans1 := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
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
	count := make([]int, 2005)
	for i := 0; i < N; i++ {
		count[A[i]-1]++ // Store frequency of A[i]
	}

	ans2 := 0
	remain := N
	for i := 0; i < 2005; i++ {
		remain -= count[i] // Reduce the remaining count
		ans2 += count[i] * remain // Calculate the number of valid pairs
	}

	// Calculate the final answer
	tmp := K * (K - 1) / 2
	tmp %= mod // Take modulo to prevent overflow
	tmp *= ans2
	tmp %= mod // Take modulo to prevent overflow
	ans := 0
	ans += ans1 * K
	ans %= mod // Take modulo to prevent overflow
	ans += tmp
	ans %= mod // Take modulo to prevent overflow

	// Output the final answer
	fmt.Println(ans)
}
