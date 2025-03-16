
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Synchronize input/output for faster performance
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements
	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	// Initialize a slice to store the elements and read them from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	// Sort the slice to facilitate duplicate checking
	sort.Ints(a)

	// Check for duplicates in the sorted slice
	for i := 0; i < n-1; i++ {
		if a[i] == a[i+1] {
			// If a duplicate is found, print "NO" and exit
			fmt.Fprintln(writer, "NO")
			return
		}
	}

	// If no duplicates are found, print "YES"
	fmt.Fprintln(writer, "YES")
}

