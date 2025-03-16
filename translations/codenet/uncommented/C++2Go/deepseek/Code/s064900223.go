package main

import (
	"fmt"
)

func main() {
	var n, i, ans int
	fmt.Scan(&n)
	p := make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&p[i])
	}
	ans = 0
	for i = 0; i < n-1; i++ {
		if p[i] == i+1 {
			p[i+1] = p[i]
			ans += 1
		}
	}
	if p[n-1] == n {
		ans += 1
	}
	fmt.Println(ans)
}

