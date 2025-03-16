package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a slice to hold three integers
	in := make([]int, 3)

	// Read three integers from standard input
	fmt.Scan(&in[0], &in[1], &in[2])

	// Sort the integers in ascending order
	sort.Ints(in)

	// Calculate the result based on the sorted integers
	// The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
	fmt.Println(in[2]*10 + in[1] + in[0])
}
