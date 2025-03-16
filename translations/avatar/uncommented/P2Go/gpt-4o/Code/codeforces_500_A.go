package main

import (
	"fmt"
	"os"
)

func main() {
	var n, t int
	fmt.Scan(&n, &t)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	currentCell := 1 // Start from cell 1 (1-based index)
	for currentCell <= t {
		currentCell += s[currentCell-1]
		if currentCell == t {
			fmt.Println("YES")
			os.Exit(0)
		}
	}
	fmt.Println("NO")
}

// <END-OF-CODE>
