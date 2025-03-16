package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	pre := float64(1000000000)
	ans := 0
	for j := 0; j < n; j++ {
		ans += int(max(0, min(pre-1, float64(a[j]))))
		pre = max(0, min(pre-1, float64(a[j])))
	}
	fmt.Println(ans)
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

