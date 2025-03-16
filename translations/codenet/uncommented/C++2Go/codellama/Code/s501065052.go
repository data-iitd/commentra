package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	mem := make([]int, N+1)
	for i := 1; i <= N; i++ {
		var P int
		fmt.Scan(&P)
		mem[P] = i
	}

	maxcnt := 1
	cnt := 1
	for i := 1; i < N; i++ {
		if mem[i] < mem[i+1] {
			cnt++
		} else {
			maxcnt = max(maxcnt, cnt)
			cnt = 1
		}
		if i == N-1 {
			maxcnt = max(maxcnt, cnt)
		}
	}
	// cnt = 1
	// for i := N; i > 1; i-- {
	// 	if mem[i] > mem[i-1] {
	// 		cnt++
	// 	}
	// }

	fmt.Println(N - maxcnt)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

