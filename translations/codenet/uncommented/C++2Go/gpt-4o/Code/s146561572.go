package main

import (
	"fmt"
)

func solve() {
	var ans int64 = 0
	var n int
	fmt.Scan(&n)

	// Contribution of The Nodes.
	for i := 1; i <= n; i++ {
		ans += int64(i) * int64(n-i+1)
	}
	for i := 1; i < n; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		a := max(u, v)
		b := min(u, v)
		ans -= int64(b) * int64(n-a+1)
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var t int
	// fmt.Scan(&t)
	t = 1
	for t > 0 {
		solve()
		t--
	}
}

// <END-OF-CODE>
