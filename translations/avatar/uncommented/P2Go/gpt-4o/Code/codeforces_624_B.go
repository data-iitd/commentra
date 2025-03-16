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

	pre := float64(1<<63 - 1) // equivalent to float('inf')
	ans := 0
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	for j := 0; j < n; j++ {
		ans += max(0, int(min(pre-1, float64(a[j]))))
		pre = max(0, min(pre-1, float64(a[j])))
	}

	fmt.Println(ans)
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
