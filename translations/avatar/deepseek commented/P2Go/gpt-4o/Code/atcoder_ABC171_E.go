package main

import (
	"fmt"
	"strings"
)

func main() {
	// Step 1: Take an integer input N, which represents the number of elements in the list.
	var N int
	fmt.Scan(&N)

	// Step 2: Take a list of integers as input and store them in the slice 'a'.
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	// Step 3: Calculate the total XOR of all elements in the slice 'a'.
	total := 0
	for _, value := range a {
		total ^= value
	}

	// Step 4: Create a new slice where each element is the XOR of the original element and the total.
	result := make([]string, N)
	for i, value := range a {
		result[i] = fmt.Sprintf("%d", value^total)
	}

	// Print the new slice as a space-separated string.
	fmt.Println(strings.Join(result, " "))
}

// <END-OF-CODE>
