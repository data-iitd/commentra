package main

import (
	"fmt"
	"math"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)
	A := make([]int, N)
	B := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	m := A[0]
	B[1] = A[1] - m
	m = int(math.Min(float64(m), float64(A[1])))

	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = int(math.Min(float64(m), float64(A[i])))
	}

	maxB := B[0]
	for _, value := range B {
		if value > maxB {
			maxB = value
		}
	}

	count := 0
	for _, value := range B {
		if value == maxB {
			count++
		}
	}

	fmt.Println(count)
}

// <END-OF-CODE>
