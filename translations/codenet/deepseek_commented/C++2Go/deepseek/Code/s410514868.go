package main

import (
	"fmt"
)

func main() {
	var n, k int
	var s string
	fmt.Scan(&n, &k)
	fmt.Scan(&s)
	
	L := s[0]
	ans := 0
	ans2 := 0
	cnt := 0
	
	for i := 1; i < n; i++ {
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
	
	result := ans + min(2*k, ans2-1)
	fmt.Println(result)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

