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
	fmt.Scan(&N)
	fmt.Scan(&K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]-- // Adjusting to 0-based index
	}

	used := make(map[int]struct{})
	idx := make([]int, N)
	pos := make([]int, N)
	next := 0
	cur := 0

	for {
		if _, exists := used[next]; exists {
			break
		}
		used[next] = struct{}{}
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := (10000*a + K - b) % a + b
	if b > K {
		ans = K
	}
	fmt.Println(pos[ans] + 1) // Adjusting back to 1-based index
}

// <END-OF-CODE>
