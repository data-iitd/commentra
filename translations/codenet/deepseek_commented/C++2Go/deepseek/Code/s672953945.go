package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var N, L int
	var v []string

	// Read the number of strings N and the length L from the standard input
	fmt.Scan(&N, &L)

	// Read N strings from the standard input and store them in the slice v
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s)
	}

	// Sort the slice v in lexicographical order
	sort.Strings(v)

	// Concatenate and print the sorted strings without spaces
	for _, str := range v {
		fmt.Print(str)
	}
	fmt.Println()
}

