
package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	var as []int
	fmt.Scan(&n, &k)
	as = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i])
	}
	fmt.Println(Calculator(n, k, as))
}

func Calculator(n, k int, as []int) int {
	var answer int
	var lists [][]int
	lists = make([][]int, n)
	for i := 0; i < n; i++ {
		lists[i] = make([]int, 0)
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			lists[j] = append(lists[j], i)
		} else if j > 0 {
			answer++
		}
	}
	var dfs func(a, pre int) int
	dfs = func(a, pre int) int {
		h := 0
		for _, i := range lists[a] {
			h = int(math.Max(float64(h), float64(dfs(i, a))))
		}
		if pre > 0 && h == k-1 {
			h = 0
			answer++
		} else {
			h++
		}
		return h
	}
	dfs(0, 0)
	return answer
}

