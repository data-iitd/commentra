package main

import (
	"fmt"
)

func main() {
	// 1. Declare variables
	var N, D, X int
	var num_of_chocolate int
	var counter int
	var days int
	var A [101]int

	// 2. Input reading
	fmt.Scan(&N, &D, &X)

	// 3. Reading values into array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// 4. Calculating the number of chocolates
	num_of_chocolate = 0
	for i := 0; i < N; i++ {
		days = 0
		counter = 0
		for j := 0; ; j++ {
			days = j*A[i] + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		num_of_chocolate += counter
	}

	// 5. Adding extra chocolates
	num_of_chocolate += X

	// 6. Output the result
	fmt.Println(num_of_chocolate)
}

// <END-OF-CODE>
