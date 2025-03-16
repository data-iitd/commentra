package main

import (
	"fmt"
	"math"
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
		a := int(math.Max(float64(u), float64(v)))
		b := int(math.Min(float64(u), float64(v)))
		ans -= int64(b) * int64(n-a+1)
	}

	fmt.Println(ans)
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

