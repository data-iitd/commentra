package main

import (
	"fmt"
)

func main() {
	var n, ans int
	fmt.Scan(&n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}
	ans = 0
	for i := 0; i < n-1; i++ {
		if p[i] == i+1 {
			p[i+1] = p[i]
			ans++
		}
	}
	if p[n-1] == n {
		ans++
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
