package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)
	result := 0
	h := make([]int, n)
	g := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&h[i], &g[i])
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				result++
			}
		}
	}

	fmt.Println(result)
}

// <END-OF-CODE>
