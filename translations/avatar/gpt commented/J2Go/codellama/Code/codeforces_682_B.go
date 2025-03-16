package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of elements
	var n int
	fmt.Fscan(in, &n)

	// Initialize an ArrayList to store the input integers
	list := make([]int, 0, n)

	// Read n integers from input and add them to the list
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(in, &x)
		list = append(list, x)
	}

	// Sort the list of integers in ascending order
	sort.Ints(list)

	// Initialize a counter to track the maximum consecutive integer
	c := 1

	// Iterate through the sorted list to find the maximum consecutive integer
	for i := 0; i < n; i++ {
		// If the current integer is greater than or equal to the counter, increment the counter
		if list[i] >= c {
			c++
		}
	}

	// Print the result which is the maximum consecutive integer found
	fmt.Fprintln(out, c)

	// Close the PrintWriter
	out.Flush()
}

// Debugging method to print objects to the error output
func debug(a ...interface{}) {
	fmt.Fprintln(os.Stderr, a...)
}

