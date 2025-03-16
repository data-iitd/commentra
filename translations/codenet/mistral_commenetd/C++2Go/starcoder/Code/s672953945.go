<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"sort"
	"strings"
)

// The main function begins here
func main() {

	// Initialize an empty vector 'v' of strings
	var v []string

	// Read the number of strings 'N' and their lengths 'L' from the standard input
	var N, L int
	fmt.Scanf("%d %d\n", &N, &L)

	// Allocate memory for 'N' strings in the vector 'v'
	for i := 0; i < N; i++ {
		// Read a string's' from the standard input and push it back into the vector 'v'
		var s string
		fmt.Scanf("%s\n", &s)
		v = append(v, s)
	}

	// Sort the strings in the vector 'v' in ascending order using the'sort' function
	sort.Strings(v)

	// Iterate through the sorted strings in the vector 'v' and print each string to the standard output
	for i := 0; i < len(v); i++ {
		// Print the current string from the vector 'v' to the standard output
		fmt.Printf("%s", v[i])
	}

	// Print a newline character at the end of the output
	fmt.Printf("\n")
}

