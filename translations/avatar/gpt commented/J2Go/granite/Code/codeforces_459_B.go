
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Create a scanner to read input from the standard input stream
	in := bufio.NewReader(os.Stdin)

	// Create a writer to output results to the standard output stream
	out := bufio.NewWriter(os.Stdout)

	// Read the number of elements from input
	N, _ := strconv.Atoi(read(in))

	// Initialize an array to hold the input integers
	A := make([]int, N)

	// Read N integers from input and store them in the array A
	for n := 0; n < N; n++ {
		A[n], _ = strconv.Atoi(read(in))
	}

	// Sort the array A to easily find the minimum and maximum values
	sort.Ints(A)

	// Identify the minimum and maximum values in the sorted array
	min := A[0]
	max := A[N-1]

	// Initialize counters for occurrences of min and max values
	mins := int64(0)
	maxs := int64(0)

	// Count how many times the minimum and maximum values occur in the array
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	// If all elements are the same (min equals max)
	if min == max {
		// Calculate the difference (which is 0) and the number of ways to choose 2 from mins
		fmt.Fprintf(out, "%d %d\n", max-min, mins*(mins-1)/2)
	} else {
		// Calculate the difference and the product of occurrences of min and max
		fmt.Fprintf(out, "%d %d\n", max-min, mins*maxs)
	}

	// Flush the output
	out.Flush()
}

// read reads a single line from the input stream
func read(in *bufio.Reader) string {
	line, _, _ := in.ReadLine()
	return string(line)
}

// Debugging function to print objects in a readable format
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// End of code