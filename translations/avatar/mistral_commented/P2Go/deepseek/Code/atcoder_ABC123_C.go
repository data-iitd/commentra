package main

import (
	"fmt"
	"math"
)

func main() {
	// Define a constant variable N, which is the input number
	var N int
	fmt.Scan(&N)

	// Define a list A, which consists of five integers, each input as a separate line
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&A[i])
	}

	// Calculate the minimum value in the list A
	minValue := A[0]
	for _, value := range A {
		if value < minValue {
			minValue = value
		}
	}

	// Calculate the ceiling value of N divided by the minimum value in the list A
	ceilingValue := int(math.Ceil(float64(N) / float64(minValue)))

	// Add 4 to the ceiling value to get the final answer
	finalAnswer := ceilingValue + 4

	// Print the final answer
	fmt.Println(finalAnswer)
}
