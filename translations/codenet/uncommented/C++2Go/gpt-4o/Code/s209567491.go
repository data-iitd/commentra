package main

import (
	"fmt"
)

func main() {
	var N, D, X int
	fmt.Scan(&N, &D, &X)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	numOfChocolate := 0
	for i := 0; i < N; i++ {
		days := 0
		counter := 0
		for j := 0; ; j++ {
			days = j*A[i] + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		numOfChocolate += counter
	}
	numOfChocolate += X

	fmt.Println(numOfChocolate)
}

// <END-OF-CODE>
