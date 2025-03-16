
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	var K int64
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
	a := int64(cur) - int64(idx[next])
	b := int64(idx[next])
	ans := int(math.Mod(10000*a+K-b+1e9, float64(a)) + b)
	if b > K {
		ans = int(K)
	}
	fmt.Println(pos[ans] + 1)
}

