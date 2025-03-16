package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N) // Read an integer input N (not used in further calculations)

	var a []int
	for i := 0; i < N; i++ {
		var num int
		fmt.Scan(&num) // Read integers into the slice
		a = append(a, num)
	}

	// Calculate the total using the XOR operation across all elements in the list 'a'
	total := 0
	for _, value := range a {
		total ^= value
	}

	// For each element in the list 'a', compute the XOR with 'total' and store the results
	var results []string
	for _, value := range a {
		results = append(results, fmt.Sprintf("%d", value^total))
	}

	// Join the results with a space and print
	fmt.Println(strings.Join(results, " "))
}

// <END-OF-CODE>
