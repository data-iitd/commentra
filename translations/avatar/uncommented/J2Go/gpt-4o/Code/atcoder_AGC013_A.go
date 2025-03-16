package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	count := 0
	for i := 0; i < N; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
			// do nothing
		} else if A[i] < A[i+1] {
			for A[i] <= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		} else {
			for A[i] >= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		}
	}
	fmt.Println(count)
}

// <END-OF-CODE>
