package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	total := 0
	for _, ai := range a {
		total ^= ai
	}

	for _, ai := range a {
		fmt.Print(ai ^ total, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>
