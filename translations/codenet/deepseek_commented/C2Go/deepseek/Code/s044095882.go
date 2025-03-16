package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	count := make([]int, n)

	for i := 1; i < n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ {
		count[i] = 0
	}

	for i := 1; i < n; i++ {
		count[a[i]-1]++
	}

	for i := 0; i < n; i++ {
		fmt.Println(count[i])
	}
}

