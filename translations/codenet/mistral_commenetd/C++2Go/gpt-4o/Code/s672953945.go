package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize a slice of strings
	var v []string

	// Read the number of strings 'N' and their lengths 'L' from the standard input
	var N, L int
	fmt.Scan(&N, &L)

	// Allocate memory for 'N' strings in the slice 'v'
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s)
	}

	// Sort the strings in the slice 'v' in ascending order
	sort.Strings(v)

	// Iterate through the sorted strings in the slice 'v' and print each string to the standard output
	for _, str := range v {
		fmt.Print(str)
	}

	// Print a newline character at the end of the output
	fmt.Println()
}

// <END-OF-CODE>
