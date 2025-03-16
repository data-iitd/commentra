package main

import (
	"fmt"
	"math"
)

func main() {
	// Read an integer input from the user
	var N int
	fmt.Scan(&N)

	// Read 5 integer inputs from the user and store them in a slice A
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&A[i])
	}

	// Calculate the minimum value from the slice A
	minValue := A[0]
	for _, value := range A {
		if value < minValue {
			minValue = value
		}
	}

	// Calculate the result and print it
	result := int(math.Ceil(float64(N) / float64(minValue))) + 4
	fmt.Println(result)
}

// <END-OF-CODE>
