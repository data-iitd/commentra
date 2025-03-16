package main

import (
	"fmt"
	"sort"
)

func main() {
	// Declare a slice to store strings and variables for input
	var v []string
	var N, L int

	// Read the number of strings (N) and the length of strings (L)
	fmt.Scan(&N, &L)

	// Input N strings from the user and store them in the slice
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s) // Add the string to the slice
	}

	// Sort the slice of strings in lexicographical order
	sort.Strings(v)

	// Output the sorted strings
	for _, str := range v {
		fmt.Print(str) // Print each string in the sorted order
	}
	fmt.Println() // Print a newline at the end
}

// <END-OF-CODE>
