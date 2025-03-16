package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	r := 0

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		r ^= a[i]
	}

	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(r ^ a[i])
	}
}

// <END-OF-CODE>
