<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	// Declare variables to store N and L
	var N, L int

	// Read the number of strings N and the length L from the standard input
	fmt.Scanf("%d %d\n", &N, &L)

	// Declare a slice to store the strings
	var v []string

	// Read N strings from the standard input and store them in the slice v
	for i := 0; i < N; i++ {
		var s string
		fmt.Scanf("%s\n", &s)
		v = append(v, s)
	}

	// Sort the slice v in lexicographical order
	sort.Strings(v)

	// Concatenate and print the sorted strings without spaces
<<<<<<< HEAD
	for i := 0; i < len(v); i++ {
		fmt.Print(v[i])
	}
	fmt.Println()
=======
	fmt.Println(strings.Join(v, ""))
>>>>>>> 98c87cb78a (data updated)
}

