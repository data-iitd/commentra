package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	ans := n - 1
	last := 0
	for i := 0; i < n; i++ {
		ans += abs(last-l[i]) + 1
		last = l[i]
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

