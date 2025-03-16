
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define a constant number for modulo operations
	const num = 998244353

	// Initialize bufio.Scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize bufio.Writer to output results to standard output
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) from input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Create two slices to store the two sets of integers
	a := make([]int, n)
	b := make([]int, n)

	// Read n pairs of integers from input
	for i := 0; i < n; i++ {
		scanner.Scan()
		fields := strings.Fields(scanner.Text())
		a[i], _ = strconv.Atoi(fields[0])
		b[i], _ = strconv.Atoi(fields[1])
	}

	// Sort both slices to prepare for median calculation
	sort(a)
	sort(b)

	// Check if the number of elements is odd
	if n%2 == 1 {
		// Calculate the result for odd n using the median values
		result := b[n/2] - a[n/2] + 1
		// Print the result to standard output
		fmt.Fprintln(writer, result)
	} else {
		// Calculate the average of the two middle values for even n
		b_avg := float64(a[n/2]+a[n/2-1])/2
		c_avg := float64(b[n/2]+b[n/2-1])/2
		// Calculate the result for even n and print it
		result := int(2*(c_avg-b_avg) + 1)
		// Print the result to standard output
		fmt.Fprintln(writer, result)
	}

	// Flush the writer to ensure all output is written
	writer.Flush()
}
