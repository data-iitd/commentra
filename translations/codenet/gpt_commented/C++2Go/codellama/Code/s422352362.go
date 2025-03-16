package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n+1)
	pre := make([]int, n+1)
	last := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	sumpre := 0
	sumlast := 0
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
		// Debugging output for prefix sums (commented out)
		// fmt.Println(pre[i])
	}
	for i := n; i > 1; i-- {
		sumlast += a[i]
		last[i] = sumlast
		// Debugging output for suffix sums (commented out)
		// fmt.Println(last[i])
	}
	d := int(1e18)
	for i := 1; i < n; i++ {
		// Debugging output for the difference calculation (commented out)
		// fmt.Println(pre[i] - last[i+1])
		d = min(d, abs(pre[i]-last[i+1]))
	}
	fmt.Println(d)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

