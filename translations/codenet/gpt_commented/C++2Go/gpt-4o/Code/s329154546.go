package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of strings (N) and the length of each string (L)
	var N, L int
	fmt.Scan(&N, &L)

	// Declare a slice to hold the strings
	S := make([]string, N)

	// Input the strings from the user
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	// Sort the slice of strings in lexicographical order
	sort.Strings(S)

	// Output the sorted strings
	for _, str := range S {
		fmt.Print(str)
	}

	// Print a newline at the end of the output
	fmt.Println()
}

// <END-OF-CODE>
