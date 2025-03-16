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
	for _, ai := range a {
		total ^= ai
	}

	for i := 0; i < N; i++ {
		a[i] ^= total
	}

	fmt.Println(strings.Trim(fmt.Sprint(a), "[]"))
}

