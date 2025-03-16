package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Synchronize input/output for faster performance
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	
	// Read the number of elements
	var n int
	fmt.Fscan(in, &n)
	
	// Initialize a slice to store the elements and read them from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	
	// Sort the slice to facilitate duplicate checking
	sort.Ints(a)
	
	// Check for duplicates in the sorted slice
	for i := 0; i < n - 1; i++ {
		if a[i] == a[i + 1] {
			// If a duplicate is found, print "NO" and exit
			fmt.Fprintln(out, "NO")
			return
		}
	}
	
	// If no duplicates are found, print "YES"
	fmt.Fprintln(out, "YES")
}

