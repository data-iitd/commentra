
package main

import "fmt"

func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	fmt.Printf("%d\n", A[i])
}

func insertionsort(n int, A []int) {
	var i, j, a int
	for i = 0; i < n; i++ {
		for j = 0; j < i; j++ {
			if A[i] < A[j] {
				a = A[i]
				A[i] = A[j]
				A[j] = a
			}
		}
	}
	white(n, A)
}

func main() {
	var n int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	insertionsort(n, A)
}

