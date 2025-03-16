package main

import (
	"fmt"
)

const MOD = 1000000007
const MAX = int(^uint(0) >> 1) // Equivalent to Integer.MAX_VALUE
const LMAX = int64(^uint64(0) >> 1) // Equivalent to Long.MAX_VALUE
const len = 1000001

func main() {
	var N int
	var K int64
	fmt.Scan(&N, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]-- // Adjusting for 0-based indexing
	}

	used := make(map[int]struct{})
	idx := make([]int, N)
	pos := make([]int, N)

	next := 0
	cur := 0

	// Detect the cycle in the array A
	for _, exists := used[next]; !exists; {
		used[next] = struct{}{}
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	// Calculate the length of the cycle and adjust the position based on K
	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := int((10000*a + K - b) % a + b)

	// Adjust the answer if necessary based on the cycle length
	if b > K {
		ans = int(K)
	}

	// Output the final position
	fmt.Println(pos[ans] + 1)
}

// <END-OF-CODE>
