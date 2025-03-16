package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	x := 0

	if k <= max(n*n/2, n*n-(n*n/2)) {
		fmt.Println("YES")
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i%2 == j%2 && x < k {
					fmt.Print("L")
					x++
				} else {
					fmt.Print("S")
				}
			}
			fmt.Println()
		}
	} else {
		fmt.Println("NO")
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

