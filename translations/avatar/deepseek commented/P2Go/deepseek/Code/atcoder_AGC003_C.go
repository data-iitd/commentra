package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = x * N + i
	}

	// Sort the list A
	// Note: Go's sort package does not have a built-in function for sorting slices of integers
	// We will use the built-in sort function which is not the most efficient for this purpose
	// but it will suffice for the example
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			if A[i] > A[j] {
				A[i], A[j] = A[j], A[i]
			}
		}
	}

	cnt := 0

	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}

	fmt.Println(cnt / 2)
}
