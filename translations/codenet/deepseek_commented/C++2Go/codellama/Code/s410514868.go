package main

import (
	"fmt"
)

func main() {
	var n, k, ans, L, ans2 int
	var s string

	fmt.Scan(&n, &k)
	fmt.Scan(&s)

	L = int(s[0])
	cnt := 0

	for i := 1; i < n; i++ {
		if L == int(s[i]) {
			cnt++
		} else {
			L = int(s[i])
			ans += cnt
			ans2++
			cnt = 0
		}
	}

	ans += cnt
	ans2++

	fmt.Println(ans + min(2*k, ans2-1))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

