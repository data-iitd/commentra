
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of elements
	n, _ := strconv.Atoi(read(in))

	// Initialize an array to store the input integers
	a := make([]int, n)

	// Read n integers from input and store them in the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(in))
	}

	// Sort the array of integers in ascending order
	sort.Ints(a)

	// Initialize a counter to track the maximum consecutive integer
	c := 1

	// Iterate through the sorted array to find the maximum consecutive integer
	for i := 0; i < n; i++ {
		// If the current integer is greater than or equal to the counter, increment the counter
		if a[i] >= c {
			c++
		}
	}

	// Print the result which is the maximum consecutive integer found
	fmt.Fprintln(out, c)
}

// read reads a single line from the input
func read(in *bufio.Reader) string {
	s, _ := in.ReadString('\n')
	return s
}

// Debugging function to print objects to the error output
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// End of code