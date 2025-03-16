package main

import (
	"fmt"
	"strings"
)

func main() {
	var a, b string
	fmt.Scan(&a, &b)
	n, m := len(a), len(b)
	ans := n + m
	for i := 0; i+m <= n; i++ {
		sum := 0
		for j := 0; j < m; j++ {
			if a[i+j] != b[j] {
				sum++
			}
		}
		ans = min(ans, sum)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

