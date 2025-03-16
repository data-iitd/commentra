package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	m := A[0]
	M := A[0]
	for i := 0; i < N; i++ {
		if A[i] < m {
			m = A[i]
		}
		if A[i] > M {
			M = A[i]
		}
	}

	fmt.Println(M - m)
}

