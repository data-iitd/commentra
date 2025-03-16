package main

import (
	"fmt"
)

func main() {
	var m, n int
	var i, j int
	var A [100][100]int
	var B [100]int
	var S [100]int

	fmt.Scan(&m, &n)

	for i = 0; i < m; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Scan(&A[i][j])
		}
		fmt.Scan(&A[i][n-1])
	}

	for i = 0; i < n; i++ {
		fmt.Scan(&B[i])
	}

	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			S[i] += A[i][j] * B[j]
		}
	}

	for i = 0; i < m; i++ {
		fmt.Println(S[i])
	}
}

