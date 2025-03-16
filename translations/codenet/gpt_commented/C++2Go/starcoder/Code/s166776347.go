package main

import (
	"fmt"
	"math"
)

// Define types and macros for convenience
type ll int64
type P struct {
	first, second ll
}

// Define constants
const (
	mod = 1e9 + 7
	INF = 1e18
)

func main() {
	// Input: Read the values of N and K
	var N, K ll
	fmt.Scanf("%d %d\n", &N, &K)

	// Solution: Calculate the number of inversions in the array
	var ans1, ans2 ll
	A := make([]ll, N)
	for i := range A {
		fmt.Scanf("%d\n", &A[i])
	}
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			if A[i] > A[j] {
				ans1++
			}
			ans1 %= mod
		}
	}

	// Count occurrences of each element in the array
	count := make([]ll, 2005)
	for i := 0; i < N; i++ {
		count[A[i]-1]++
	}

	// Calculate the second part of the answer based on the counts
	remain := N
	for i := 0; i < 2005; i++ {
		remain -= count[i]
		ans2 += count[i] * remain
	}

	// Calculate the final answer based on ans1 and ans2
	ans := 0
	tmp := K * (K - 1)
	tmp /= 2
	tmp %= mod
	tmp *= ans2
	tmp %= mod
	ans += ans1 * K
	ans %= mod
	ans += tmp
	ans %= mod

	// Output: Print the final answer
	fmt.Printf("%d\n", ans)
}

