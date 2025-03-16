package main

import (
	"fmt"
)

func main() {
	var N int
	var K int64
	fmt.Scan(&N, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]-- // Subtracting 1 from the input to get the index of the previous element
	}

	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next, cur := 0, 0

	// Finding the cycle starting point using BFS
	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := (10000*a + K - b + 1000000007) % a + b

	// Checking if the starting position of the cycle is greater than K, if yes then the answer is K
	if b > K {
		ans = K
	}

	fmt.Println(pos[ans] + 1)
}

