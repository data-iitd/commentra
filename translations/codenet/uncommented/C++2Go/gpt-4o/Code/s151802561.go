package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	sw := 0
	for i := 0; i < n; i++ {
		mini := i
		for j := i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		A[i], A[mini] = A[mini], A[i]
		if i != mini {
			sw++
		}
	}

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()
	fmt.Println(sw)
}

// <END-OF-CODE>
