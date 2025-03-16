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

	fmt.Scan(&N, &D, &X)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	numOfChocolate = 0
	for i := 0; i < N; i++ {
		days = 0
		counter = 0
		for {
			days = (counter * A[i]) + 1
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

