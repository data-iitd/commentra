package main

import "fmt"

func main() {
	var m, n int
	var i, j int
	var A [100][100]int
	var B [100]int
	var S [100]int

	fmt.Scanf("%d %d", &m, &n)

	for i = 0; i < m; i++ {

		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d ", &A[i][j])
		}
		fmt.Scanf("%d\n", &A[i][n-1])

	}

	for i = 0; i < n; i++ {
		fmt.Scanf("%d\n", &B[i])
	}

	for i = 0; i < m; i++ {

		for j = 0; j < n; j++ {
			S[i] = S[i] + A[i][j]*B[j]
		}

	}

	for i = 0; i < m; i++ {
		fmt.Printf("%d\n", S[i])
	}

}

