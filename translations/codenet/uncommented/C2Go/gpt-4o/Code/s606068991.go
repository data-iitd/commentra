package main

import (
	"fmt"
)

func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	fmt.Println(A[n-1])
}

func insertionsort(n int, A []int) {
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if A[i] < A[j] {
				A[i], A[j] = A[j], A[i]
			}
		}
		white(n, A)
	}
}

func main() {
	var n int
	var A [100]int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	insertionsort(n, A[:n])
}

// <END-OF-CODE>
