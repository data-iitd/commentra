package main

import (
	"fmt"
)

func main() {
	var n int
	var a [101]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Print(a[n-1])
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1])
	}
	fmt.Println()
}

// <END-OF-CODE>
