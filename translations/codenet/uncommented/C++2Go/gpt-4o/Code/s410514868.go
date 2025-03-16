package main

import (
	"fmt"
)

func main() {
	var n, k int64
	var ans, cnt, ans2 int64
	var s string

	fmt.Scan(&n, &k)
	fmt.Scan(&s)

	L := s[0]
	cnt = 0

	for i := int64(1); i < n; i++ {
		if L == s[i] {
			cnt++
		} else {
			L = s[i]
			ans += cnt
			ans2++
			cnt = 0
		}
	}
	ans += cnt
	ans2++

	fmt.Println(ans + min(2*k, ans2-1))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
