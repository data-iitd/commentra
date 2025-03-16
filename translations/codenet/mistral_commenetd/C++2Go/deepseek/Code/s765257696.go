package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	// Synchronize the input and output streams with stdio
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read an integer n from the standard input
	var n int
	fmt.Fscan(in, &n)

	// Allocate an array p of size n to store the input integers
	p := make([]int, n)

	// Initialize the variable ans to 0
	ans := 0

	// Iterate through the array p from index 0 to n-3
	for i := 0; i < n-2; i++ {
		// Read the next element into the array p
		fmt.Fscan(in, &p[i])

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
	fmt.Fprintln(out, ans)

	// Return 0 from the main function to indicate successful execution
}

