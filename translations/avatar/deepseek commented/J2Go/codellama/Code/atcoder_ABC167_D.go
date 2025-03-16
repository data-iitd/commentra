
package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next, cur := 0, 0
	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}
	a := float64(cur - idx[next])
	b := float64(idx[next])
	ans := int(math.Mod(10000*a+float64(K)-b, a) + b)
	if b > float64(K) {
		ans = int(K)
	}
	fmt.Println(pos[ans] + 1)
}

