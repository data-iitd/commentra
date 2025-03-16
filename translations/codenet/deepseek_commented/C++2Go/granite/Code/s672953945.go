
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Define variables to store N and L
	var N, L int

	// Read the number of strings N and the length L from the standard input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &N, &L)

	// Create a slice to store strings and read N strings from the standard input
	s := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%s\n", &s[i])
	}

	// Sort the slice s in lexicographical order
	sort.Strings(s)

	// Concatenate and print the sorted strings without spaces
	for _, v := range s {
		fmt.Print(v)
	}
	fmt.Println()
}

