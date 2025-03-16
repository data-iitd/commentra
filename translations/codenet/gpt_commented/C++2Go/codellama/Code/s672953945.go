// Include necessary header files
package main

import (
	"fmt"
	"sort"
)

// Define long long as int for convenience
type int int

// Macros for loop iterations
func REP(i, s, e int) {
	for i = s; i < e; i++ {
	}
}

func RREP(i, s, e int) {
	for i = s - 1; i >= e; i-- {
	}
}

func FOR(i, n int) {
	for i = 0; i < n; i++ {
	}
}

func RFOR(i, n int) {
	for i = n - 1; i >= 0; i-- {
	}
}

// Define a constant for modulo operation
const MOD int = 1000000007

func main() {
	// Declare a vector to store strings and variables for input
	var v []string
	var N, L int

	// Read the number of strings (N) and the length of strings (L)
	fmt.Scan(&N, &L)

	// Input N strings from the user and store them in the vector
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s) // Add the string to the vector
	}

	// Sort the vector of strings in lexicographical order
	sort.Strings(v)

	// Output the sorted strings
	for i := 0; i < len(v); i++ {
		fmt.Print(v[i]) // Print each string in the sorted order
	}
	fmt.Println() // Print a newline at the end
}

