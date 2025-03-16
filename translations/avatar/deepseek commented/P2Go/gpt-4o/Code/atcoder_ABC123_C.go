package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Step 2: Read an integer input N

	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&A[i]) // Step 3: Read five integer inputs and store them in a slice A
	}

	minValue := A[0]
	for _, value := range A {
		if value < minValue {
			minValue = value // Find the minimum value in A
		}
	}

	result := int(math.Ceil(float64(N) / float64(minValue))) + 4 // Step 4: Calculate the result
	fmt.Println(result) // Print the result
}

// <END-OF-CODE>
