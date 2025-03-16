package main

import (
	"fmt"
)

func main() {
	var N, D, X int
	var numOfChocolate int
	var counter int
	var days int
	var A [101]int

	// Reading input values
	fmt.Scan(&N, &D, &X)

	// Reading values into array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Calculating the number of chocolates
	numOfChocolate = 0
	for i := 0; i < N; i++ {
		days = 0
		counter = 0
		for {
			days = (days / A[i] * A[i]) + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		numOfChocolate += counter
	}

	// Adding extra chocolates
	numOfChocolate += X

	// Output the result
	fmt.Println(numOfChocolate)
}

