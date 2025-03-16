//#include<bits/stdc++.h>
package main

import (
	"fmt"
	"sort"
)

// Main function to execute the program
func main() {

	// Vector to store strings and variables to store N and L
	var v []string
	var N, L int

	// Read the number of strings N and the length L from the standard input
	fmt.Scan(&N, &L)

	// Read N strings from the standard input and store them in the vector v
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s)
	}

	// Sort the vector v in lexicographical order
	sort.Strings(v)

	// Concatenate and print the sorted strings without spaces
	for i := 0; i < len(v); i++ {
		fmt.Print(v[i])
	}
	fmt.Println()
}

