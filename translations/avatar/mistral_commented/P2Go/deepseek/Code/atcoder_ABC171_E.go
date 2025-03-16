package main

import (
	"fmt"
	"strconv"
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

	result := make([]string, N)
	for i, ai := range a {
		result[i] = strconv.Itoa(ai ^ total)
	}

	fmt.Println(strconv.Quote(strconv.Join(result, " ")))
}

