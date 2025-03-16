package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	total := 0
	for i := 0; i < N; i++ {
		total ^= a[i]
	}
	for i := 0; i < N; i++ {
		fmt.Printf("%d ", a[i]^total)
	}
	fmt.Println()
}

