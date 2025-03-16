package main

import "fmt"

func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	fmt.Printf("%d\n", A[i])
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
	fmt.Scanf("%d", &n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}
	insertionsort(n, A)
}

