
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var K int64
	fmt.Scan(&N)
	fmt.Scan(&K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]--
	}
	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next := 0
	cur := 0
	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}
	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := int((10000*a + K - b) % a + b)
	if b > K {
		ans = int(K)
	}
	fmt.Println(pos[ans] + 1)
}

