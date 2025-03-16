package main

import "fmt"

func main() {
	var i, j, N, tmp, count int
	var A [100]int
	fmt.Scanf("%d", &N)
	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	for i = 0; i < N-1; i++ {
		for j = N - 1; j > i; j-- {
			if A[j] < A[j-1] {
				tmp = A[j]
				A[j] = A[j-1]
				A[j-1] = tmp
				count++
			}
		}
	}
	for i = 0; i < N; i++ {
		fmt.Printf("%d", A[i])
		if i < N-1 {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
	fmt.Printf("%d\n", count)
}

