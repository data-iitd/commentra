
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Synchronize the input and output streams with stdio
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read an integer n from the standard input
	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	// Allocate an array p of size n to store the input integers
	p := make([]int, n)

	// Initialize the variable ans to 0
	ans := 0

	// Iterate through the array p from index 0 to n-3
	for i := 0; i < n-2; i++ {
		// Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			// Increment the ans variable if both conditions are true
			ans++
		}

		// Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			// Increment the ans variable if both conditions are true
			ans++
		}
	}

	// Print the value of ans to the standard output
	fmt.Fprintf(writer, "%d\n", ans)

	// Flush the output buffer to ensure all data is written to the standard output
	writer.Flush()
}

