package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	var k, a int
	var x [31]int

	// Read input values for n and m
	fmt.Fscan(reader, &n, &m)

	// Process each input value for n times
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &k) // Read the number of elements in the current input

		// Process each element in the current input
		for j := 0; j < k; j++ {
			fmt.Fscan(reader, &a) // Read the value of the current element
			x[a]++ // Increment the count of the current value in the array x
		}
	}

	// Initialize answer variable to zero
	var ans int

	// Check each value from 1 to m and increment the answer if the count is equal to n
	for i := 1; i <= m; i++ {
		if x[i] == n { // Check if the count of the current value is equal to n
			ans++ // Increment the answer if true
		}
	}

	// Output the final answer
	fmt.Fprintln(writer, ans)
}

