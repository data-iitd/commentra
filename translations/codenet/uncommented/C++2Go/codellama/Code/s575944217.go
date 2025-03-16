package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	ans := make([]int, n)
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scan(&a)
		a--
		ans[a]++
	}
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

