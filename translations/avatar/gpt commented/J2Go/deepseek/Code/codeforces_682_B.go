package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	
	// Read the number of elements
	in.Scan()
	n, _ := fmt.Sscanf(in.Text(), "%d", &n)
	
	// Initialize a slice to store the input integers
	list := make([]int, n)
	
	// Read n integers from input and add them to the slice
	for i := 0; i < n; i++ {
		in.Scan()
		fmt.Sscanf(in.Text(), "%d", &list[i])
	}
	
	// Sort the slice of integers in ascending order
	sort.Ints(list)
	
	// Initialize a counter to track the maximum consecutive integer
	c := 1
	
	// Iterate through the sorted slice to find the maximum consecutive integer
	for i := 0; i < n; i++ {
		// If the current integer is greater than or equal to the counter, increment the counter
		if list[i] >= c {
			c++
		}
	}
	
	// Print the result which is the maximum consecutive integer found
	fmt.Fprintln(pw, c)
	
	// Close the PrintWriter
	pw.Flush()
}

