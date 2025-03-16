
package main

import "fmt"

func main() {

	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	count := 0
	for i := 0; i < N-1; i++ {
		for j := N - 1; j > i; j-- {
			if A[j] < A[j-1] {
				tmp := A[j]
				A[j] = A[j-1]
				A[j-1] = tmp
				count++
			}
		}
	}

	for i := 0; i < N; i++ {
		fmt.Printf("%d", A[i])
		if i < N-1 {
			fmt.Print(" ")
		}
	}

	fmt.Println()
	fmt.Println(count)
}
