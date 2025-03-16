package main

import (
	"fmt"
)

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	A := make([][]int, m)
	for i := 0; i < m; i++ {
		A[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&A[i][j])
		}
	}

	B := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&B[i])
	}

	S := make([]int, m)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			S[i] += A[i][j] * B[j]
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(S[i])
	}
}

// <END-OF-CODE>
