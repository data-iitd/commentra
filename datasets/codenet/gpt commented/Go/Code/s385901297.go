package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a new scanner to read input from standard input (stdin)
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize a slice to hold four integers
	ns := make([]int, 4)

	// Read a line of input and parse it into the slice
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3])

	// Sort the slice of integers in ascending order
	sort.Sort(sort.IntSlice(ns))

	// Check if the sorted integers match the specific sequence [1, 4, 7, 9]
	if ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9 {
		// If they match, print "YES"
		fmt.Println("YES")
	} else {
		// If they do not match, print "NO"
		fmt.Println("NO")
	}
}
